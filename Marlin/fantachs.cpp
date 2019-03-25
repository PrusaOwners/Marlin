/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * fantach.cpp - manages tachometer readings from fans
 */

#include "MarlinConfig.h"

#if ENABLED(FANTACH)

#include "fantachs.h"


/**
 * Pin definition macros do not correctly support all interrupt capable pins on the 
 * ATMEGA2560. We redefine some macros for that here.
 */
#if defined(__AVR_ATmega2560__)

  /**
   * Arduino has its own interrupt numbering scheme, that is somewhat inconsistent across processors and 
   * doesn't match the numbers in the processor data sheet. For the ATMEGA2560, here is the mapping.
   *
   *  ATMEGA2560 |  Arduino  | ATMEGA2560 |  Arduino  |
   *  Port/Pin # |  Pin #    |   INT #    |   INT #   |
   *  -------------------------------------------------
   *   PD0 / 43        21          0            2
   *   PD1 / 44        20          1            3
   *   PD2 / 45        19          2            4
   *   PD3 / 46        18          3            5
   *   PE4 / 6          2          4            0
   *   PE5 / 7          3          5            1
   *   PE6 / 8         79          6            6
   *   PE7 / 9         80          7            7
   */
  #undef digitalPinToInterrupt
  #define digitalPinToInterrupt(p) ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) >= 18 && (p) <= 21 ? 23 - (p) : ((p) >= 79 && (p) <= 80 ? (p) - 73 :NOT_AN_INTERRUPT))))

#endif // __AVR_ATmega2560__


millis_t FanTachs::last_rpm_update_ms = 0;
millis_t FanTachs::last_rpm_interval_ms = 0;

#if HAS_TACH_E0
  uint16_t FanTachs::count_e0 = 0;
  uint16_t FanTachs::rpm_e0 = 0;
#endif

#if HAS_TACH_E1
  uint16_t FanTachs::count_e1 = 0;
  uint16_t FanTachs::rpm_e1 = 0;
#endif

#if HAS_TACH_0
  uint16_t FanTachs::count_0 = 0;
  uint16_t FanTachs::rpm_0 = 0;
#endif

#if HAS_TACH_1
  uint16_t FanTachs::count_1 = 0;
  uint16_t FanTachs::rpm_1 = 0;
#endif

#if DISABLED(FANTACH_INTERRUPT)
  #if HAS_TACH_E0
    uint8_t  FanTachs::state_e0 = 0;
  #endif

  #if HAS_TACH_E1
    uint8_t  FanTachs::state_e1 = 0;
  #endif

  #if HAS_TACH_0
    uint8_t  FanTachs::state_0 = 0;
  #endif

  #if HAS_TACH_1
    uint8_t  FanTachs::state_1 = 0;
  #endif
#endif

void FanTachs::init()
{
  last_rpm_update_ms = millis();

  #if HAS_TACH_E0 && defined(TACH_E0_PULLUP)
    SET_INPUT_PULLUP(TACH_E0_PIN);
  #endif
  #if HAS_TACH_E1 && defined(TACH_E1_PULLUP)
    SET_INPUT_PULLUP(TACH_E1_PIN);
  #endif
  #if HAS_TACH_0 && defined(TACH_0_PULLUP)
    SET_INPUT_PULLUP(TACH_0_PIN);
  #endif
  #if HAS_TACH_1 && defined(TACH_1_PULLUP)
    SET_INPUT_PULLUP(TACH_1_PIN);
  #endif

#if ENABLED(FANTACH_INTERRUPT)
  #if HAS_TACH_E0
    static_assert(digitalPinToInterrupt(TACH_E0_PIN) != NOT_AN_INTERRUPT, "TACH_E0_PIN is not interrupt-capable");
    attachInterrupt(digitalPinToInterrupt(TACH_E0_PIN), FanTachs::isr_e0, FALLING); 
  #endif

  #if HAS_TACH_E1
    static_assert(digitalPinToInterrupt(TACH_E1_PIN) != NOT_AN_INTERRUPT, "TACH_E1_PIN is not interrupt-capable");
    attachInterrupt(digitalPinToInterrupt(TACH_E1_PIN), FanTachs::isr_e1, FALLING); 
  #endif

  #if HAS_TACH_0
    static_assert(digitalPinToInterrupt(TACH_0_PIN) != NOT_AN_INTERRUPT, "TACH_0_PIN is not interrupt-capable");
    attachInterrupt(digitalPinToInterrupt(TACH_0_PIN), FanTachs::isr_0, FALLING); 
  #endif

  #if HAS_TACH_1
    static_assert(digitalPinToInterrupt(TACH_1_PIN) != NOT_AN_INTERRUPT, "TACH_1_PIN is not interrupt-capable");
    attachInterrupt(digitalPinToInterrupt(TACH_1_PIN), FanTachs::isr_1, FALLING); 
  #endif
#endif
}

#if ENABLED(FANTACH_INTERRUPT)
  #if HAS_TACH_E0
    void FanTachs::isr_e0() {
      ++count_e0;
    }
  #endif

  #if HAS_TACH_E1
    void FanTachs::isr_e1() {
      ++count_e1;
    }
  #endif

  #if HAS_TACH_0
    void FanTachs::isr_0() {
        ++count_0;
    }
  #endif

  #if HAS_TACH_1
    void FanTachs::isr_1() {
      ++count_1;
    }
  #endif
#endif

#if DISABLED(FANTACH_INTERRUPT)
  void FanTachs::updateCounts() {
    uint8_t pinstate;

    #if HAS_TACH_E0
      pinstate = READ(TACH_E0_PIN);
      if (!pinstate && state_e0) { // Falling edge
        ++count_e0;
      }
      state_e0 = pinstate;
    #endif
    
    #if HAS_TACH_E1
      pinstate = READ(TACH_E1_PIN);
      if (!pinstate && state_e1) { // Falling edge
        ++count_e1;
      }
      state_e1 = pinstate;
    #endif

    #if HAS_TACH_0
      pinstate = READ(TACH_0_PIN);
      if (!pinstate && state_0) { // Falling edge
        ++count_0;
      }
      state_0 = pinstate;
    #endif

    #if HAS_TACH_1
      pinstate = READ(TACH_1_PIN);
      if (!pinstate && state_1) { // Falling edge
        ++count_1;
      }
      state_1 = pinstate;
    #endif
  }
#endif

void FanTachs::updateRpm()
{
  const millis_t now = millis();
  const millis_t elapsed_ms =  now - last_rpm_update_ms;
    
  if (elapsed_ms > FANTACH_SAMPLE_WINDOW_MS)
  {
    last_rpm_update_ms = now;

    // Capture and reset count values with interrupts disabled so updateCounts doesn't run concurrently.
    // Do minimal work with interrupts disabled
    CRITICAL_SECTION_START;
      #if HAS_TACH_E0
        const uint16_t tmp_count_e0 = count_e0;
        count_e0 = 0;
      #endif
      #if HAS_TACH_E1
        const uint16_t tmp_count_e1 = count_e1;
        count_e1 = 0;
      #endif
      #if HAS_TACH_0
        const uint16_t tmp_count_0 = count_0;
        count_0 = 0;
      #endif
      #if HAS_TACH_1
        const uint16_t tmp_count_1 = count_1;
        count_1 = 0;
      #endif
    CRITICAL_SECTION_END;

    #if HAS_TACH_E0
      rpm_e0 = (uint16_t)((uint32_t)tmp_count_e0 * 60 * 1000 / TACH_E0_PPR / elapsed_ms);
    #endif
    #if HAS_TACH_E1
      rpm_e1 = (uint16_t)((uint32_t)tmp_count_e1 * 60 * 1000 / TACH_E1_PPR / elapsed_ms);
    #endif
    #if HAS_TACH_0
      rpm_0 = (uint16_t)((uint32_t)tmp_count_0 * 60 * 1000 / TACH_0_PPR / elapsed_ms);
    #endif
    #if HAS_TACH_1
      rpm_1 = (uint16_t)((uint32_t)tmp_count_1 * 60 * 1000 / TACH_1_PPR / elapsed_ms);
    #endif

    last_rpm_interval_ms = elapsed_ms;
  }
}

void FanTachs::printTachRpms()
{
  #if HAS_TACH_E0
    SERIAL_PROTOCOLPAIR(" E0: ", rpm_e0);
  #endif
  #if HAS_TACH_E1
    SERIAL_PROTOCOLPAIR(" E1: ", rpm_e1);
  #endif
  #if HAS_TACH_0
    SERIAL_PROTOCOLPAIR(" 0: ", rpm_0);
  #endif
  #if HAS_TACH_1
    SERIAL_PROTOCOLPAIR(" 1: ", rpm_1);
  #endif
  SERIAL_EOL();
}


#endif  // FANTACH
