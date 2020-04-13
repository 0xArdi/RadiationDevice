# RadiationMeter
## 1. Setup
##### NODEMCU
In order to start programming the NODEMCU you will need some set up first.
1. Add https://arduino.esp8266.com/stable/package_esp8266com_index.json to additional boards, this can be done by navigating to File -> Preferences.
2. Now that you have added an additional index containing esp8266 boards, you will have to navigate to Tools -> Board -> Boards Manager, then type in esp8266 and install the same package.
3. Finally go to Tools -> Boards and select your esp8266 board, in this case it is NODEMCU v1.0.
##### Arduino Uno
No special setup is needed in order to program this board.

## 2. Connecting the boards
All connections between boards are done via breadboard unless specified otherwise.
##### Geiger Counter
Three pins is all you need to connect. 
+ Connect Geiger GND to Arduino GND.
+ Connect Geiger 5V to Arduino 5V.
+ Connect Geiger VIN to Arduino Digital Pin 2. This is done directly not through breadboard.
##### NODEMCU
Follow the scheme.
**Note: Uno RX is connected to NODEMCU TX and vice versa**
![alt text](https://raw.githubusercontent.com/ardi1998/RadiationMeter/master/schemes/nodemcu-shceme.jpg)

## 3. Flashing the programs to the boards
##### NODEMCU
Connect to PC via microUSB cable, open nodemcu.ino file and click upload.
**NOTE: Remove 3.3V, GND and RX TX pins when flashing to NODEMCU.**

##### Arduino
Connect to PC, open spi_rad_logger.ino file and click upload.
**NOTE: Remove RX TX pins when flashing to Arduino.**

## 4. Changing communication settings
In order to set to which network the device should connect, change the following two lines of code in nodemcu.ino file.
```C
const char* ssid = "Test";
const char* password = "12345678";
```
To change the server to which the data is send to alter the following variable.
``` C
const char* URL = "http://skopje.ml/device/sendData?deviceSecret=YOUR_DEVICE_SECRET";
```
