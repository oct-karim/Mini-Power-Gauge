---
title: "USB-C PCB Power Gauge"
github: "oct-karim/Mini-Power-Gauge"
description: "A compact USB-C power monitor using an ATmega328P."
created_at: "2026-08-18"
---

<div align="center">

#  USB-C PCB POWER GAUGE 

---

## Introduction

Welcome to the journal for the **USB-C PCB Power Gauge**. 

This journal serves as a complete development log tracking the hardware design, schematic layout and firmware . The objective is to build a reliable USB-C meter capable of displaying real-time  voltage, current draw, and power consumption using an ATmega328P and dedicated I2C peripherals.

---
<div align="center">
  
##  Journal Entries Index

| Date | Log Title | Time Spent |
| :---: | :--- | :--- |
| [<ins>2026-08-18</ins>](#august-18-2026--Schematic-Design-and-datasheet-nightmare) | Schematic Design, PCB Layout and Firmware | 3h |
| [<ins>2026-08-19</ins>](#august-19-2026--PCB-Layout-and-Firmware) | Schematic Design, PCB Layout and Firmware | 4h |

---

# August 18, 2026:  Schematic Design and datasheet nightmare

<div align="center">

This is one of my firt pcb project. I already have experience in pcb layout and I2C communication but never used a 8-bit microcontroller. First i putted my objective clear: To mesure voltage and current. I didn't want a rp2040 or esp32 mcu. It's way overkill. I choose the ATmega328P. Simple and efficient. Searched online for datasheet and started routing and placing decoupling capacitors. Putted the USB-C receptacle and started adding bulking capacitors to smooth the power for the PCB.<img width="1126" height="660" alt="image" src="https://github.com/user-attachments/assets/40940028-317f-4643-968c-a68c16aee042" /> I placed a ferrite bead to block noise. I searched online for the perfect value and found 300 ohms and 600Mhz. I also choose a TVS Diode to protect it from voltage spikes. Then made the MCU footprint with it's 16MHz Crystal (Because it works at 5V and it's faster) some other decoupling capacitor and started connecting the MCU to the I2C expander. I, then addes three LED to make it more alive   
     <img width="448" height="641" alt="image" src="https://github.com/user-attachments/assets/6eec61a7-a1e2-4780-b3cc-d664e5e7983b" />    
Then the nightmare begun... i had problems with the datasheet of the I2C Expander and how to connect it to the LCD. I searched for almost one hour and then asked to an ia lol. I thought it was intuitevly but no way: <img width="640" height="783" alt="image" src="https://github.com/user-attachments/assets/7f524704-1ff8-4ff2-9d80-fe722b16fb54" />   
    This is the easy part, very simple to understand.   
        <img width="605" height="798" alt="image" src="https://github.com/user-attachments/assets/3a79e99a-4aca-41c1-b36d-60c925890f33" />    
      So in th beginning i routed all the "P" pins from the I2C expander to the DB for the LCD. But after countless reddit forums and datasheet i found out that it's wrong. The LCD needs only 4 pins to work so the other will be routed for the backlight. I then placed a connector for the LCD DIsplay beacuse it's not SMD.
    <img width="860" height="797" alt="image" src="https://github.com/user-attachments/assets/a89fd8f4-e8e0-4f55-a389-63cde5e74c93" />  ²  
    I also added a BJT to regulate the backlight for the failsafe and sleepmode.  
        Then i placed the sensor and started calculating the resistance of the shunt resistor and with it's max shunt rating of 82mV and my current rangr of 3A i placed a 0.02 ohm shunt resistor.       
            <img width="669" height="734" alt="image" src="https://github.com/user-attachments/assets/3ddb5b4e-b549-436d-91fe-17d539813e5b" />    
                In the end i placed the ICSP socket to programm the ATmega beacuse it doesn't have a USB interface    
                    <img width="756" height="443" alt="image" src="https://github.com/user-attachments/assets/1f9f9226-e891-4546-914f-4894c55b7377" />    
                        And placed the INPUT/OUTPUT of the load to mesure. I used screw terminals    
                            <img width="453" height="265" alt="image" src="https://github.com/user-attachments/assets/ab70d9be-070c-4112-9ae4-faeac863c117" />    
                                That's the end for today, i actually spent 3h+ 2h of research and datasheet anaalysis. Anyway, next time i will start to route the PCB layout and make the firmware.
  ## Final Schematics 
  <img width="1093" height="757" alt="image" src="https://github.com/user-attachments/assets/e47782e3-00e7-4a94-ba00-342fa32502e7" />    
        Total time spent: 3h+2h of research

---

# August 19, 2026:  PCB Layout and Firmware

<div align="center">
Today i made the PCB Layout,i had some difficulties while routing because the weird footprint of some compnents. But did a good job in the end:
    <img width="1007" height="801" alt="image" src="https://github.com/user-attachments/assets/efc00dc7-2a8d-4039-94fc-c71cf7c49967" />







  







---

