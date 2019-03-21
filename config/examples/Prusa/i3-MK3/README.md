# Marlin 2 3D Printer Firmware for Prusa i3 MK3

## Summary of Changes

### Configuration.h

The following tables shows all changes from Marlin bugfix-2.0.x default values.

|Symbol                       |Value                    |Default
|-----------------------------|-------------------------|-------
|BAUDRATE                     |115200                   |250000
|MOTHERBOARD                  |BOARD_EINSY_RAMBO        |BOARD_RAMPS_14_EFB
|CUSTOM_MACHINE_NAME          |"Prusa i3 MK3"           |"3D Printer" (commented out)
|DEFAULT_NOMINAL_FILAMENT_DIA |1.75                     |3.0
|TEMP_SENSOR_0                |5                        |1
|TEMP_SENSOR_BED              |1                        |0
|HEATER_0_MAXTEMP             |305                      |275
|BED_MAXTEMP                  |125                      |150
|DEFAULT_Kp                   |16.13                    |22.2
|DEFAULT_Ki                   |1.1625                   |1.08
|DEFAULT_Kd                   |56.23                    |114
|PIDTEMPBED                   |                         |(commented out)
|DEFAULT_bedKp                |126.13                   |10.00
|DEFAULT_bedKi                |4.30                     |.023
|DEFAULT_bedKd                |924.76                   |305.4
|EXTRUDE_MINTEMP              |175                      |170
|X_MIN_ENDSTOP_INVERTING      |true                     |false
|Y_MIN_ENDSTOP_INVERTING      |true                     |false
|X_DRIVER_TYPE                |TMC2130                  |(commented out)
|Y_DRIVER_TYPE                |TMC2130                  |(commented out)
|Z_DRIVER_TYPE                |TMC2130                  |(commented out)
|E0_DRIVER_TYPE               |TMC2130                  |(commented out)
|ENDSTOP_INTERRUPTS_FEATURE   |                         |(commented out)
|DEFAULT_AXIS_STEPS_PER_UNIT  |{ 100, 100, 3200/8, 280 }|{ 80, 80, 4000, 500 }
|DEFAULT_MAX_FEEDRATE         |{ 200, 200, 12, 120 }    |{ 300, 300, 5, 25 }
|DEFAULT_MAX_ACCELERATION     |{ 1000, 1000, 200, 5000 }|{ 3000, 3000, 100, 10000 }
|DEFAULT_ACCELERATION         |1250                     |3000
|DEFAULT_RETRACT_ACCELERATION |1250                     |3000
|DEFAULT_TRAVEL_ACCELERATION  |1250                     |3000
|JUNCTION_DEVIATION           |                         |(commented out)
|DEFAULT_ZJERK                |0.4                      |0.3
|DEFAULT_EJERK                |2.5                      |5.0
|S_CURVE_ACCELERATION         |                         |(commented out)
|FIX_MOUNTED_PROBE            |                         |(commented out)
|X_PROBE_OFFSET_FROM_EXTRUDER |23                       |10
|Y_PROBE_OFFSET_FROM_EXTRUDER |5                        |10
|MIN_PROBE_EDGE               |0                        |10
|XY_PROBE_SPEED               |???                      |8000
|Z_PROBE_SPEED_SLOW           |???                      |(Z_PROBE_SPEED_FAST / 2)
|MULTIPLE_PROBING             |???                      |2 (commented out)
|Z_CLEARANCE_DEPLOY_PROBE     |2                        |10
|Z_CLEARANCE_BETWEEN_PROBES   |2                        |5
|Z_CLEARANCE_MULTI_PROBE      |1                        |5
|Z_PROBE_LOW_POINT            |-1                       |-2
|Z_PROBE_OFFSET_RANGE_MIN     |-3                       |-20
|Z_PROBE_OFFSET_RANGE_MAX     |0                        |20
|INVERT_X_DIR                 |true                     |false
|INVERT_Y_DIR                 |false                    |true
|INVERT_Z_DIR                 |true                     |false
|X_BED_SIZE                   |250                      |200
|Y_BED_SIZE                   |210                      |200
|Y_MIN_POS                    |-4                       |0
|Z_MIN_POS                    |0.15                     |0
|X_MAX_POS                    |255                      |X_BED_SIZE
|Y_MAX_POS                    |212.5                    |Y_BED_SIZE
|Z_MAX_POS                    |210                      |200
|FIL_RUNOUT_INVERTING         |true                     |false
|AUTO_BED_LEVELING_BILINEAR   |                         |(commented out)
|GRID_MAX_POINTS_X            |4                        |3
]GRID_MAX_POINTS_Y            |6                        |GRID_MAX_POINTS_X
|LEFT_PROBE_BED_POSITION      |24                       |MIN_PROBE_EDGE
|RIGHT_PROBE_BED_POSITION     |228                      |(X_BED_SIZE - (MIN_PROBE_EDGE))
|FRONT_PROBE_BED_POSITION     |6                        |MIN_PROBE_EDGE
|BACK_PROBE_BED_POSITION      |210                      |(Y_BED_SIZE - (MIN_PROBE_EDGE))
|MESH_INSET                   |0                        |1
|GRID_MAX_POINTS_X            |4                        |10
|GRID_MAX_POINTS_Y            |6                        |GRID_MAX_POINTS_X
|Z_SAFE_HOMING                |                         |(commented out)
|HOMING_FEEDRATE_XY           |???                      |(50*60)
|HOMING_FEEDRATE_Z            |???                      |(4*60)
|SKEW_CORRECTION              |                         |(commented out)
|SKEW_CORRECTION_FOR_Z        |                         |(commented out)
|SKEW_CORRECTION_GCODE        |                         |(commented out)
|EEPROM_SETTINGS              |                         |(commented out)
|PREHEAT_1_TEMP_HOTEND        |215                      |180
|PREHEAT_1_TEMP_BED           |60                       |70
|PREHEAT_2_LABEL              |"PET"                    |"ABS"
|PREHEAT_2_TEMP_HOTEND        |230                      |240
|PREHEAT_2_TEMP_BED           |85                       |110
|NOZZLE_PARK_FEATURE          |                         |(commented out)
|LCD_INFO_SCREEN_STYLE        |1                        |0
|SDSUPPORT                    |                         |(commented out)
|SD_CHECK_AND_RETRY           |                         |(commented out)
|ENCODER_PULSES_PER_STEP      |4                        |4 (commented out)
|REVERSE_ENCODER_DIRECTION    |                         |(commented out)
|INDIVIDUAL_AXIS_HOMING_MENU  |                         |(commented out)
|SPEAKER                      |                         |(commented out)
|REPRAP_DISCOUNT_SMART_CONTROLLER|                      |(commented out)

### Configuration_adv.h

The following tables shows all changes from Marlin bugfix-2.0.x default values.

|Symbol                       |Value                    |Default
|-----------------------------|-------------------------|-------
|PID_EXTRUSION_SCALING        |                         |(commented out)
|DEFAULT_Kc                   |(1)                      |(100)
|AUTOTEMP                     |(commented out)          |(uncommented)
|FAN_KICKSTART_TIME           |800                      |100 (commented out)
|E0_AUTO_FAN_PIN              |8                        |-1
|FAN_PIN                      |6                        |8 (in pins_EINSY_RAMBO.h)
|FAN1_PIN                     |-1                       |6 (in pins_EINSY_RAMBO.h)
|X_HOME_BUMP_MM               |0                        |5
|Y_HOME_BUMP_MM               |0                        |5
|Z_HOME_BUMP_MM               |1                        |2
|DEFAULT_STEPPER_DEACTIVE_TIME |60                      |120
|HOME_AFTER_DEACTIVATE        |                         |(uncommented)