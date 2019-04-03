/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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

#include "../../inc/MarlinConfig.h"

#if HAS_TEMP_PINDA

#include "../gcode.h"
#include "../../module/temperature.h"
#include "../../lcd/ultralcd.h"

  /**
   * M199: Wait for temperature sensitive bed level sensor to reach target temperature. 
   *       This is for the use of Prusa PINDAv2 bed level sensor with build-in thermistor.
   *       On Prusa Firmware M860 is used, which is already in use in Marlin
   *
   *  S<temperature> - Set temperature to wait for. Without further arguments the printer waits
   *                   until the sensor has warmed or cooled to the specified temperature. If 
   *                   both heaters are off (bed and hotend), cooling will automatically be assumed.
   *                   Otherwise warming is assumed.
   * C               - Force cool down regardless of heater state (optional)
   * W               - Force warm up regardless of heater state (optional)
   * T<seconds>      - Timeout after <seconds> seconds if the set temperature has not been reached 
   *                   (optional)
   * 
   * If both C and W are given, warm up is performed
   */

void GcodeSuite::M199() {
  if (DEBUGGING(DRYRUN)) return;

  // Target temperature
	if (parser.seenval('S')) {
    
    const int16_t target_temp = (int16_t)parser.value_celsius();

    const bool is_pinda_cooling = 
      !parser.seen('W') && 
      ( ((thermalManager.degTargetBed() == 0) && (thermalManager.degTargetHotend(0) == 0))
        || parser.seen('C'));

    //Timeout
    millis_t timeout = 0;
    if (parser.seenval('T')) {
      timeout = millis() + parser.value_millis_from_seconds();
    }

    SERIAL_ECHOPGM("Wait for sensor ");
    is_pinda_cooling ? SERIAL_ECHOPGM("cool down") : SERIAL_ECHOPGM("warm up");
    SERIAL_ECHOPGM(" to target temperature: ");
    SERIAL_ECHO(target_temp);
    SERIAL_EOL();

    float pinda_temp;
    millis_t now = millis();
    millis_t next_serial_status_ms = now + 1000UL;;

    thermalManager.setTargetPinda(target_temp);

    do {        
      pinda_temp = thermalManager.degPinda();

      // PINDA temp is displayed in serial console in response to M105 commands.
      // We display it here on the LCD
      if (ELAPSED(now, next_serial_status_ms)) {
        next_serial_status_ms = now + 1000UL;
        thermalManager.print_heater_states(active_extruder);
        SERIAL_EOL();
        
        #if ENABLED(ULTRA_LCD)
          ui.status_printf_P(0, is_pinda_cooling ? PSTR("P:%i/%i " MSG_COOLING) : PSTR("P:%i/%i " MSG_HEATING), int16_t(pinda_temp), target_temp);
        #endif
      }

      idle();
      reset_stepper_timeout(); // Keep steppers powered

      now = millis();

      if ((timeout != 0) && ELAPSED(now, timeout)) {
        SERIAL_ECHOPGM("TIMEOUT on sensor ");
        if (is_pinda_cooling) {
          SERIAL_ECHOPGM("cool-down");
        } 
        else {
          SERIAL_ECHOPGM("warm-up");
        }
        SERIAL_EOL();
        break;
      }

    } while ( ((!is_pinda_cooling) && (pinda_temp < target_temp)) 
              || (is_pinda_cooling && (pinda_temp > target_temp)) );

    #if ENABLED(ULTRA_LCD)
      ui.reset_status();
    #endif

    thermalManager.setTargetPinda(0);
  }
}

#endif // HAS_TEMP_PINDA