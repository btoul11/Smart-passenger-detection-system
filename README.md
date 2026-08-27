# Smart-passenger-detection-system
Smart Passenger Detection System (SPDS) using Arduino and FSR sensors to ensure school bus safety.
# Smart Passenger Detection System (SPDS) 🚌💡

A smart embedded system designed to automatically detect remaining passengers or children on school bus seats after engine shutdown. The system uses non-invasive pressure sensors to provide immediate local audio-visual alerts, helping prevent accidental heatstroke incidents.

---

## 📌 Project Overview
Preventing child abandonment in school buses is a critical safety priority. SPDSautomates post-trip seat inspections, replacing manual checks with an accurate, privacy-preserving, and cost-effective hardware solution.

Developed as a Graduation Capstone Project at **Taif University (2025-2026)**.

---

## 🛠️ System Architecture & Logic
* **Microcontroller:** Arduino Uno
* **Sensors:** Force Sensitive Resistors (FSR) / Seat Pressure Sensors
* **Outputs:** 16x2 LCD Display, Audio Buzzer, LED Safety Indicators
* **Engine Control Simulation:** Ignition State Push-Button Switch

### System Workflow:
1. Upon turning off the bus engine, SPDS automatically transitions to active monitoring mode.
2. The system scans seat pressure values based on pre-calibrated threshold ranges to prevent false alarms.
3. If weight or pressure is detected, an immediate alarm sequence activates (LCD message, audible buzzer, and flashing LED).
4. The system automatically resets once the seat is completely cleared.

---

## 🚀 Future Development & Industrial Integration
* **Automated Vehicle Integration:** Connecting directly via CAN Bus and OBD-II interfaces for automatic engine-state detection.
* **IoT & Fleet Management:** Adding 4G and GPS modules to transmit instant alerts and locations to school administrators via mobile apps and SMS.
* **External Alarm Triggering:** Wiring the system to activate the bus horn and hazard lights if internal warnings are not acknowledged.

---

## 👥 Intellectual Property & Authors
**Protected under Taif University Intellectual Property Rights and Regulations.**

* **Authors & Engineers:** 
  * Albatul Abdullah Albogami
  * Nouf Ibrahim AlDawsari
* **Project Supervisor:** Dr. Manahill Idriss Adrob Anja
* **Institution:** Department of Computer Science, College of Computers and Information Technology, Taif University.

*Copyright © 2025-2026 Albatul Albogami & Nouf AlDawsari. All Rights Reserved.*
