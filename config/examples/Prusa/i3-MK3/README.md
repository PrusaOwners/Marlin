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
|DEFAULT_AXIS_STEPS_PER_UNIT  |{ 100, 100, 3200/8, 280 }|{ 80, 80, 4000, 500 }
|DEFAULT_MAX_FEEDRATE         |{ 200, 200, 12, 120 }    |{ 300, 300, 5, 25 }
|DEFAULT_MAX_ACCELERATION     |{ 1000, 1000, 200, 5000 }|{ 3000, 3000, 100, 10000 }
|DEFAULT_ACCELERATION         |1250                     |3000
|DEFAULT_RETRACT_ACCELERATION |1250                     |3000
|DEFAULT_TRAVEL_ACCELERATION  |1250                     |3000
|JUNCTION_DEVIATION           |(uncommented)            |(commented out)
|DEFAULT_ZJERK                |0.4                      |0.3
|DEFAULT_EJERK                |2.5                      |5.0
|S_CURVE_ACCELERATION         |(uncommented)            |(commented out)
|FIX_MOUNTED_PROBE            |(uncommented)            |(commented out)
|X_PROBE_OFFSET_FROM_EXTRUDER |23                       |10
|Y_PROBE_OFFSET_FROM_EXTRUDER |5                        |10
|MIN_PROBE_EDGE               |0                        |10
|XY_PROBE_SPEED               |10000                    |8000
|Z_PROBE_SPEED_SLOW           |(Z_PROBE_SPEED_FAST / 4) |(Z_PROBE_SPEED_FAST / 2)
|MULTIPLE_PROBING             |2                      |2 (commented out)
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
|FIL_RUNOUT_PIN               |62                       |(not explicitly defined)
|FIL_RUNOUT_INVERTING         |true                     |false
|AUTO_BED_LEVELING_BILINEAR   |(uncommented)            |(commented out)
|G26_MESH_VALIDATION          |(uncommented)            |(commented out)
|MESH_TEST_HOTEND_TEMP        |205                      |215
|GRID_MAX_POINTS_X            |4                        |3
]GRID_MAX_POINTS_Y            |6                        |GRID_MAX_POINTS_X
|LEFT_PROBE_BED_POSITION      |24                       |MIN_PROBE_EDGE
|RIGHT_PROBE_BED_POSITION     |228                      |(X_BED_SIZE - (MIN_PROBE_EDGE))
|FRONT_PROBE_BED_POSITION     |6                        |MIN_PROBE_EDGE
|BACK_PROBE_BED_POSITION      |210                      |(Y_BED_SIZE - (MIN_PROBE_EDGE))
|MESH_INSET                   |0                        |1
|GRID_MAX_POINTS_X            |4                        |10
|GRID_MAX_POINTS_Y            |6                        |GRID_MAX_POINTS_X
|Z_SAFE_HOMING                |(uncommented)            |(commented out)
|HOMING_FEEDRATE_Z            |(8*60)                   |(4*60)
|SKEW_CORRECTION              |(uncommented)            |(commented out)
|SKEW_CORRECTION_FOR_Z        |(uncommented)            |(commented out)
|SKEW_CORRECTION_GCODE        |(uncommented)            |(commented out)
|EEPROM_SETTINGS              |(uncommented)            |(commented out)
|PREHEAT_1_TEMP_HOTEND        |215                      |180
|PREHEAT_1_TEMP_BED           |60                       |70
|PREHEAT_2_LABEL              |"PET"                    |"ABS"
|PREHEAT_2_TEMP_HOTEND        |230                      |240
|PREHEAT_2_TEMP_BED           |85                       |110
|NOZZLE_PARK_FEATURE          |(uncommented)            |(commented out)
|LCD_INFO_SCREEN_STYLE        |1                        |0
|SDSUPPORT                    |(uncommented)            |(commented out)
|SD_CHECK_AND_RETRY           |(uncommented)            |(commented out)
|ENCODER_PULSES_PER_STEP      |4                        |4 (commented out)
|REVERSE_ENCODER_DIRECTION    |(uncommented)            |(commented out)
|INDIVIDUAL_AXIS_HOMING_MENU  |(uncommented)            |(commented out)
|SPEAKER                      |(uncommented)            |(commented out)
|REPRAP_DISCOUNT_SMART_CONTROLLER |(uncommented)        |(commented out)

### Configuration_adv.h

The following tables shows all changes from Marlin bugfix-2.0.x default values.

|Symbol                       |Value                    |Default
|-----------------------------|-------------------------|-------
|WATCH_BED_TEMP_PERIOD        |90                       |60 
|PID_EXTRUSION_SCALING        |(uncommented)            |(commented out)
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
|HOME_AFTER_DEACTIVATE        |(uncommented)            |(commented out)
|ADAPTIVE_STEP_SMOOTHING      |(uncommented)            |(commented out)
|LCD_INFO_MENU                |(uncommented)            |(commented out)
|STATUS_MESSAGE_SCROLLING     |(uncommented)            |(commented out)
|LCD_TIMEOUT_TO_STATUS        |30000                    |15000 (commented out)
|SDCARD_SORT_ALPHA            |(uncommented)            |(commented out)
|LONG_FILENAME_HOST_SUPPORT   |(uncommented)            |(commented out)
|SCROLL_LONG_FILENAMES        |(uncommented)            |(commented out)
|BABYSTEPPING                 |(uncommented)            |(commented out)
|DOUBLECLICK_FOR_Z_BABYSTEPPING |(uncommented)          |(commented out)
|DOUBLECLICK_MAX_INTERVAL     |2000                     |1250
|MOVE_Z_WHEN_IDLE             |(uncommented)            |(commented out)
|BABYSTEP_ZPROBE_OFFSET       |(uncommented)            |(commented out)
|LIN_ADVANCE                  |(uncommented)            |(commented out)
|LIN_ADVANCE_K                |0                        |0.22
|MESH_MIN_X                   |24                       |MESH_INSET (commented out)
|MESH_MIN_Y                   |6                        |MESH_INSET (commented out)
|MESH_MAX_X                   |228                      |X_BED_SIZE - (MESH_INSET) (commented out)
|MESH_MAX_Y                   |210                      |Y_BED_SIZE - (MESH_INSET) (commented out)
|MINIMUM_STEPPER_DIR_DELAY    |20                       |650 (commented out)
|MINIMUM_STEPPER_PULSE        |0                        |2 (commented out)
|MAXIMUM_STEPPER_RATE         |400000                   |250000 (commented out)
|ADVANCED_PAUSE_FEATURE       |(uncommented)            |(commented out)
|FILAMENT_CHANGE_UNLOAD_FEEDRATE |120                   |10
|FILAMENT_CHANGE_UNLOAD_ACCEL    |800                   |25
|FILAMENT_CHANGE_UNLOAD_LENGTH   |80                    |100
|FILAMENT_CHANGE_SLOW_LOAD_LENGTH |3                    |0
|FILAMENT_CHANGE_FAST_LOAD_FEEDRATE |18                 |6
|FILAMENT_CHANGE_FAST_LOAD_LENGTH |0                    |63
|FILAMENT_UNLOAD_RETRACT_LENGTH |0                      |13
|FILAMENT_UNLOAD_DELAY        |0                        |5000
|FILAMENT_UNLOAD_PURGE_LENGTH |3                        |8
|PARK_HEAD_ON_PAUSE           |(uncommented)            |(commented out)
|HOME_BEFORE_FILAMENT_CHANGE  |(uncommented)            |(commented out)
|FILAMENT_LOAD_UNLOAD_GCODES  |(uncommented)            |(commented out)
|HOLD_MULTIPLIER              |1.0                      |0.5
|X_CURRENT                    |282                      |800 
|X_RSENSE                     |0.22                     |0.11
|Y_CURRENT                    |348                      |800
|Y_RSENSE                     |0.22                     |0.11
|Z_CURRENT                    |530                      |800
|Z_RSENSE                     |0.22                     |0.11
|E0_CURRENT                   |514                      |800
|E0_MICROSTEPS                |32                       |16
|E0_RSENSE                    |0.22                     |0.11
|STEALTHCHOP_XY               |(commented out)          |(uncommented)
|STEALTHCHOP_Z                |(commented out)          |(uncommented)
|STEALTHCHOP_E                |(commented out)          |(uncommented)
|CHOPPER_TIMING               |{3, -2, 6} (see below)   |CHOPPER_DEFAULT_12V
|MONITOR_DRIVER_STATUS        |(uncommented)            |(commented out)
|SENSORLESS_HOMING            |(uncommented)            |(commented out) 
|X_STALL_SENSITIVITY          |3                        |8
|Y_STALL_SENSITIVITY          |3                        |8
|Z_STALL_SENSITIVITY          |4 (commented out)        |8 (commented out)
|TMC_ADV()                    |(see below)              |{}

####TMC_ADV() and CHOPPER_TIMING
It turns out that Marlin 2.0.x does not like a lot of the advanced options that we used on Marlin 1.1.9

These are the options that are still compiling:
```
#define TMC_ADV() { \
  stepperX.blank_time(24); \
  stepperY.blank_time(24); \
  stepperZ.blank_time(24); \
  stepperE0.blank_time(24); \
  stepperX.hysteresis_end(1); \
  stepperY.hysteresis_end(1); \
  stepperZ.hysteresis_end(1); \
  stepperE0.hysteresis_end(1); \
  stepperX.hysteresis_start(5); \
  stepperY.hysteresis_start(5); \
  stepperZ.hysteresis_start(5); \
  stepperE0.hysteresis_start(5); \
  }
```

These settings give a compilation error
```
  #define TMC_ADV() { \
    stepperX.high_sense_R(1);\
    stepperY.high_sense_R(1);\
    stepperE0.high_sense_R(1);\
    stepperX.hold_delay(8); \
    stepperY.hold_delay(8); \
    stepperZ.hold_delay(8); \
    stepperE0.hold_delay(8); \
    stepperX.power_down_delay(0); \
    stepperY.power_down_delay(0); \
    stepperZ.power_down_delay(0); \
    stepperE0.power_down_delay(0); \
    stepperX.off_time(3); \
    stepperY.off_time(3); \
    stepperZ.off_time(3); \
    stepperE0.off_time(3); \
    stepperX.stealth_freq(2); \
    stepperY.stealth_freq(2); \
    stepperZ.stealth_freq(2); \
    stepperE0.stealth_freq(2); \
    stepperX.stealth_gradient(4); \
    stepperY.stealth_gradient(4); \
    stepperZ.stealth_gradient(4); \
    stepperE0.stealth_gradient(4); \
    stepperX.stealth_amplitude(230); \
    stepperY.stealth_amplitude(235); \
    stepperZ.stealth_amplitude(200); \
    stepperE0.stealth_amplitude(240); \
    stepperX.stealth_autoscale(true); \
    stepperY.stealth_autoscale(true); \
    stepperZ.stealth_autoscale(true); \
    stepperE0.stealth_autoscale(true); \
    stepperE0.sg_stall_value(3); \
   }
```

Talking to @teemalut (the creator of the TMC library) revealed the issue: Marlin 2.0.x uses a new version of the TMC library. That is also why "ENDSTOP_INTERRUPTS_FEATURE" could be enable in 1.1.9 but not in 2.0.x.

The new library can be found here:
https://github.com/teemuatlut/TMCStepper

The documentation for that library was not done yet (while I write this) so the calls can be all found in the headers.

Teemalut also commented on the settings we used to do:
* stepper.blank_time(24) - that is the default Marlin value anyways
* stepper.hysteresis_end() - is part of the new CHOPPER_TIMING
* stepper.hysteresis_start() - is part of the new CHOPPER_TIMING

So the three still working calls are not nedded anymore. 

About the broken calls:
```
stealth_freq => pwm_freq
stealth_gradient => pwm_grad
stealth_amplitude => pwm_ampl
stealth_autoscale => pwm_autoscale
```
these are only for stealthcop and I am also not sure about defaults, so I keep them out for now.

He further commented:
* stepper.off_time - is part of the new CHOPPER_TIMING
* stepperE0.sg_stall_value - "why set stall value for extruder?" (Because it is in Prusa firmware but unused IMHO)
* stepper.high_sense_R(1) - "Don't set high sensitivity current sensing resistor unless you know what it does. And don't even then. This should depend on the current selection (CS) parameter and so I don't recommend you try to control it yourself. It may not even do anything if the M906 values are retrieved after init..."
* stepper.hold_delay(8);
  and 
  stepperX.power_down_delay(0);  - "I don't see what you'd gain with disabling power down delay or with decreasing hold delay. I'd drop both tbh."

There is now a new concept of the CHOPPER_TIMING parameter that can be defined like:
```
{ <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
```
There is even a defined CHOPPER_PRUSAMK3_24V those are set to 
```
{ 4,  1, 4 }
```
Sadly according to teemalut those are the wrong values. He will create eventually a pull-request with the new values. Meanwhile we can use them directly as a workaound {3, -2, 6}.

He also explained how the numbers are made: "Hysteresis end has an offset of -3.
Meaning that if you want to use setting -3, you need to write 0 to the driver. -2 needs 1. And so forth.
From the Prusa github you see that they push the pattern 1 to the driver, this means that they want to use the value 1 - 3 => -2
Same for hysteresis start, except the offset is +1"

More details should be found in Prusa firmware and the TMC specs. 

So for now: TMC_ADV() is empty! Maybe there is something to do with using stealthchop - but that needs some research (about the default values, which might be the same or good enough?!)

