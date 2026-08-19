n <div align="center">

#  USB-C PCB Power Gauge

A simple PCB, functional and efficient. For monitoring current, voltage and power.

![Hardware](https://img.shields.io/badge/Hardware-PCB_Design-red.svg)
![Firmware](https://img.shields.io/badge/Firmware-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/Status-Prototype-orange.svg)

<img width="1176" height="787" alt="image" src="https://github.com/user-attachments/assets/dbdd48a3-2b09-41dd-ab6e-d791dc5ec91e" />


</div>

##  Overview

This simple power gauge, controlled by the ATmega328P microcontroller has a voltage range of 0-36V and a current range of 0-3A. 
The footprints have been chosen to be easy to solder. And the components are widely available.

## Features
-Range 0/36V & 0/3.5A
-16x2 Display
-Sleep Mode: Consumes less energy after 30s without mesuring voltage
-Warning LED: Inform the user that the mesurements are reaching the max or a activated failsafe
-LCD Ping: checks if the display is alive or faulty soldering
-AVR Watchdog: prevents the microcontroller to freeze for more than 2 sec
-I2C Failsafe: checks if the  I2C communication is good to go
-Over range Failsafe: if the mesurements are more than 36V or 3.5A it shuts down the sensor.

##  Hardware Overview

The system is built around a standard 8-bit AVR and an I2C communication. 

| Component | Function |
| :--- | :--- |
| **ATmega328p** | Microcontroller handling data and display. |
| **INA226** | I2C current and power sensor. |
| **HY1602E** | Standard 16x2 character LCD display. |
| **PCF8574AT** | I2C expander to drive the LCD using less pins. |
| **USB-C Port** | Power input. |
| **ICSP Socket** | Firmware upload. |
