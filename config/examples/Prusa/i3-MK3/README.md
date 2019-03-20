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
|||
|||
|||
|||
|||
|||