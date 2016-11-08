# Geo-Location-Tracker
Geo-Location Tracker using Arduino Uno 

ABSTRACT:
We are building geo location tracker. 
The idea is simple: read the GPS coordinates (longitude and latitude) and send them by using a GSM module  to owner’s phone. 
Owner can use this to track the object.

These above function are performed using a microcontroller like Arduino uno, GPS module and GSM/GPRS module.

COMPONENTS:

Arduino UNO Board x 1
GPS MODULE x 1
GSM/GPRS MODULE x 1
Jumper Wires
Arduino IDE


CONNECTION:
Use SoftwareSerial library so that we can use the connect use any pin as RX and TX for interfacing with modules.

Interfacing with gps:
Connect the gps module’s Rx and Tx pin with 10,11 pin of Arduino.
Connect the VCC and GND pin to the Arduino.

Interfacing with GSM/GPRS:
Connect the module’s Rx and Tx pin with 3,4 pin of Arduino.
Connect the GND and power supply.
