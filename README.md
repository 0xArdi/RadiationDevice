# RadiationMeter
## Setup
### NODEMCU
In order to start programming the NODEMCU you will need some set up first.
1. Add https://arduino.esp8266.com/stable/package_esp8266com_index.json to additional boards, this can be done by navigating to File -> Preferences.
2. Now that you have added an additional index containing esp8266 boards, you will have to navigate to Tools -> Board -> Boards Manager, then type in esp8266 and install the same package.
3. Finally go to Tools -> Boards and select your esp8266 board, in this case it is NODEMCU v1.0.
### Arduino Uno
No special setup is needed in order to program this board.

## Flashing the programs to the boards
### NODEMCU
Connect to PC via microUSB cable, open nodemcu.ino file click upload.
**NOTE: Remove 3.3V, GND and RX TX pins when flashing to NODEMCU.**

### Arduino
Connect to PC, open spi_rad_logger.ino file click upload.
**NOTE: Remove RX TX pins when flashing to Arduino.**
