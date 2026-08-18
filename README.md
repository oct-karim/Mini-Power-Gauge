<div align="center">

#  USB-C PCB Power Gauge

A simple PCB, fucntional and efficient. For monitoring current, voltage and power.

![Hardware](https://img.shields.io/badge/Hardware-Open_Source-red.svg)
![Firmware](https://img.shields.io/badge/Firmware-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/Status-Prototype-orange.svg)

<img src="https://placehold.co/800x400/1E1E1E/FFFFFF?text=" width="800" alt="Project Hero Image">

</div>

##  Overview

[This simple power gauge, controlled by the ATmega328P microcontroller has a voltage range of 0-36V and a current range of 0-3A ]

##  Hardware Section

The system is built around a standard 8-bit AVR and an I2C communication bus.

| Component | Function |
| :--- | :--- |
| **ATmega328p** | Microcontroller handling data and display logic. |
| **INA226** | High-precision I2C current and power sensor. |
| **HY1602E** | Standard 16x2 character LCD display for data readout. |
| **PCF8574AT** | I2C expander to drive the LCD using only less pins. |
| **USB-C Port** | Power input and debug. |

### Schematics & PCB Layout

<p align="center">

</p>
