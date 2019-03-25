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
 * fantach.h - Captures ane makes available tachometer readings from tach-enabled fans.
 */

#pragma once

#include "MarlinConfig.h"

class FanTachs {
private:

  #if HAS_TACH_E0
    static uint16_t count_e0;
    static uint16_t rpm_e0;
  #endif

  #if HAS_TACH_E1
    static uint16_t count_e1;
    static uint16_t rpm_e1;
  #endif

  #if HAS_TACH_0
    static uint16_t count_0;
    static uint16_t rpm_0;
  #endif

  #if HAS_TACH_1
    static uint16_t count_1;
    static uint16_t rpm_1;
  #endif

  static millis_t last_rpm_update_ms;
  static millis_t last_rpm_interval_ms;

#if ENABLED(FANTACH_INTERRUPT)
  #if HAS_TACH_E0
    static void isr_e0();
  #endif

  #if HAS_TACH_E1
    static void isr_e1();
  #endif

  #if HAS_TACH_0
    static void isr_0();
  #endif

  #if HAS_TACH_1
    static void isr_1();
  #endif
#else
  #if HAS_TACH_E0
    static uint8_t  state_e0;
  #endif

  #if HAS_TACH_E1
    static uint8_t  state_e1;
  #endif

  #if HAS_TACH_0
    static uint8_t  state_0;
  #endif

  #if HAS_TACH_1
    static uint8_t  state_1;
  #endif
#endif

public:
  FanTachs() { };

  /**
   * Initialize the fan tachometer pins and interrupt handlers
   */
  static void init();

  /**
   * Periodic call to check for tachometer pins state changes and update the associated counts.
   * Called from either temperature ISR (not used when ISR is in use).
   */
#if DISABLED(FANTACH_INTERRUPT)
  static void updateCounts();
#endif

  /**
   * Called periodically from idle to capture tachometer count and turn it into an RPM value.
   */
  static void updateRpm();

  /**
   * These methods provide estimates rotations-per-minute (RPM) value for each fan.
   */
#if HAS_TACH_E0
  FORCE_INLINE static uint16_t rpmFanE0() { return rpm_e0; }
#endif
#if HAS_TACH_E1
  FORCE_INLINE static uint16_t rpmFanE1() { return rpm_e1; }
#endif
#if HAS_TACH_0
  FORCE_INLINE static uint16_t rpmFan0() { return rpm_0; }
#endif
#if HAS_TACH_1
  FORCE_INLINE static uint16_t rpmFan1() { return rpm_1; }
#endif

  // Serial print fan tachometer values
  static void printTachRpms();
};

extern FanTachs fantachs;

