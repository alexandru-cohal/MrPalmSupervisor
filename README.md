# MrPalmSupervisonr

## Project Description
* The purpose of this project is to develop an IoT application for supervising my plant, Mr. Palm.

## How to Use
* 
 
## Software Items
* Arduino IDE 2.3.10

## Hardware Items
* Arduino Nano 33 IoT
* DHT11 temperature and humidity sensor
* Arduino capacitive soil moisture sensor v1.2
* Breadboard + wires

## Requirements (in progress)
* The project shall be split into the hardware node and the cloud node.
* The hardware node:
  * Shall initialize all the sensors.
  * Shall log the sensors initialization results.
  * Shall print, if enabled, on UART the sensors initialization results.
  * Shall read periodically (period TBD) the temperature, humidity and soil moisture values from the sensors.
  * Shall log each sensor reading.
  * Shall print, if enabled, on UART each sensor reading.

## To Do in the following releases:
* 