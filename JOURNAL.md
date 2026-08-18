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

This document serves as a complete development log tracking the hardware design, schematic layout, datasheet analysis, and firmware integration. The core objective is to build a reliable USB-C monitor capable of displaying real-time  voltage, current draw, and power consumption using an ATmega328P and dedicated I2C peripherals.

---

## Journal Entries Index

| Date | Log Title | Time Spent |
| :---: | :--- | :--- |
| [<ins>2026-08-18</ins>](#august-18-2026--Schematic-Design-PCB-Layout-and-Firmware) | Schematic Design, PCB Layout and Firmware | 5h |

---

# August 18, 2026:  Schematic Design, PCB Layout and Firmware


### Hardware Details & IC Quirks
* **ATmega328P:** Acts as the primary MCU handling calculations and screen refreshes.
* **INA226:** High-precision bi-directional current and power monitor communicating over I2C.
* **PCF8574AT:** I2C I/O expander used to drive the character display using only 2 MCU pins (SDA/SCL)[cite: 1] rather than a full 8-bit parallel interface.
* **HY1602E:** Standard 16x2 character display driven by the expander.

Spent time verifying pinouts against the respective datasheets

![Schematic Draft](https://placehold.co/600x400/2D2D2D/FFFFFF?text=Insert+KiCad+Schematic+Screenshot+Here)

**Total time spent: 5h**

---

