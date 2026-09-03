# Smart Passenger Detection System (SPDS)

An Arduino-based embedded safety system that detects whether a passenger remains on a bus seat after the engine has been turned off, and triggers an immediate audio-visual alert.

## Overview

SPDS is a low-cost, privacy-preserving prototype built to prevent children from being accidentally forgotten inside school buses. Instead of relying on cameras or manual inspection, the system uses a **Force Sensitive Resistor (FSR)** placed on the seat to detect occupancy, combined with an Arduino Uno controller, an LCD display, a buzzer, and an LED indicator to alert the driver.

The system continuously monitors the engine state (simulated in this prototype via a push button) and the seat pressure reading. If the engine is switched OFF while the seat is still occupied, the system immediately raises a warning.

## Project Purpose

- Prevent incidents of children being left inside school buses after trips.
- Provide a reliable technological safeguard that reduces dependence on manual, error-prone inspection by drivers.
- Offer an alternative to camera-based detection systems, avoiding privacy concerns and high hardware cost.
- Deliver a simple, low-cost, and scalable solution suitable for school and public transportation safety.
- Support Saudi Vision 2030's goals for improving quality of life and traffic safety through practical technology.

## System Configuration

| Component | Quantity | Notes |
|---|---|---|
| Arduino Uno R3 | 1 | Main microcontroller / processing unit |
| LCD 16×2 (parallel interface) | 1 | Displays system status and alert messages |
| Breadboard | 1 | Circuit assembly |
| Pushbutton | 1 | Simulates engine ON/OFF state |
| Buzzer | 1 | Audible alert |
| Red LED | 1 | Visual alert indicator |
| 250 kΩ Potentiometer | 1 | LCD contrast adjustment |
| Seat Pressure Sensor (e.g. Chiffonade JY-102 type) | 1 | Multi-point resistive pressure pad designed for car seat/seatbelt sensing — placed under the seat cushion to detect passenger weight |
| Resistor – 1 kΩ | 1 | Sensor signal circuit |
| Resistor – 22 Ω | 1 | Buzzer circuit |

**Software:** Arduino IDE, Arduino C/C++, `LiquidCrystal` library.

## Assembly Scope

The current implementation is a **single-seat prototype** assembled on a breadboard for demonstration and testing purposes:

- Only one FSR sensor is used to represent one bus seat.
- The engine ON/OFF state is **simulated** with a push button rather than connected to a real vehicle ignition system.
- Alerts (buzzer, LED, LCD) are **local only** — there is no wireless, mobile, or cloud connectivity in this version.
- No camera or image-based sensing is used, by design, to preserve passenger privacy.

The design is intended to be **scalable**: future versions can support multiple seats, integration with the vehicle's CAN Bus and OBD-II systems, and cloud connectivity via GPS/4G for remote monitoring and mobile notifications.

## Mechanical / Operating Principle

1. The seat pressure sensor pad — a multi-point resistive pressure sensor designed for car seat/seatbelt applications — is placed under the seat cushion and continuously outputs an analog pressure reading to the Arduino.
2. While the engine state is ON, the system displays the normal operating status and does not raise alerts.
3. When the engine state changes to OFF, the system enters **monitoring mode** and checks the seat sensor reading.
4. The reading is compared against two calibrated threshold values to account for natural sensor fluctuation:
   - `thresholdHigh = 800`
   - `thresholdLow = 500`
5. **If pressure stays above the threshold** (seat occupied) while the engine is OFF → the buzzer activates, the LED turns on, and the LCD displays `WARNING! Child in Bus`.
6. **If pressure drops below the threshold** (seat empty) → the buzzer stops, the LED turns off, and the LCD returns to `Seat Empty`.

This threshold-based calibration was required because the sensor's baseline analog reading did not stay perfectly at zero even with no weight applied, so upper/lower bounds were used to prevent false alerts.

## Authors

- Albatul Abdullah Albogami 
- Nouf Ibrahim AlDawsari 

**Supervised by:** Dr. Manahill Idriss Adrob Anja

---
*Graduation project "Smart Passenger Detection System (SPDS)" — Department of Computer Science, College of Computers and Information Technology, Taif University, 2025–2026.*
