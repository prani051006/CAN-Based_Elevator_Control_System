# CAN-Based_Elevator_Control_System
## Overview

This project implements a **CAN (Controller Area Network) based Elevator Control System** using the **LPC2129 ARM7 microcontroller**. The system uses distributed nodes communicating over a CAN bus to control elevator operations efficiently and reliably.

Each module (floor control, motor control, display unit) communicates using CAN, eliminating complex wiring and improving system scalability.

---

## 🎯 Objectives

* To design a distributed elevator control system using CAN
* To implement real-time communication between multiple nodes
* To improve reliability and reduce wiring complexity
* To understand CAN protocol in a practical application

---

## 🧠 System Architecture

### 🔹 Master Node (Controller)

* Processes floor requests
* Controls elevator movement logic
* Sends commands via CAN

### 🔹 Slave Nodes

* **Floor Node:** Detects button presses (floor requests)
* **Motor Control Node:** Drives elevator motor (up/down/stop)
* **Display Node:** Shows current floor and status

---

## 🔁 Working Principle

1. User presses a floor button
2. Floor node sends request via CAN bus
3. Master node receives and processes request
4. Decision is made (move up/down/stop)
5. Command is sent to motor control node
6. Elevator moves accordingly
7. Status is updated on display node

---

## ⚙️ Hardware Components

* LPC2129 Microcontroller (ARM7TDMI-S core)
* CAN Transceiver (TJA1050)
* Push Buttons (floor selection)
* Motor Driver (for elevator motor control)
* DC Motor
* LEDs / 7-Segment / LCD Display
* Crystal Oscillator (12 MHz)
* Power Supply

---

## 💻 Software Requirements

* Embedded C
* Keil uVision IDE
* Flash Magic (for programming LPC2129)

---

## 📡 LPC2129 CAN Features

* Dual CAN controllers (CAN1 & CAN2)
* Supports CAN 2.0B
* Data rates up to 1 Mbps
* Hardware filtering
* Automatic error handling and retransmission

---

## 📡 CAN Communication Details

### 🔹 Message Types Used

* Floor Request Message
* Elevator Status Message

## 🚀 Features

* Real-time elevator control
* Distributed architecture using CAN
* Reduced wiring complexity
* High reliability and fault tolerance
* Scalable for multiple floors

---

## 🧪 Applications

* Smart buildings
* Industrial automation
* Distributed embedded control systems

---
## ⚡ How to Run

### 🔹 Setup

* Connect all nodes via CAN bus (CANH, CANL)
* Ensure proper termination resistors (120Ω)

### 🔹 Execution

1. Power ON all nodes
2. Press floor button
3. Observe CAN message transmission
4. Elevator motor responds
5. Display updates floor status

---

## 🔧 Future Enhancements

* Add interrupt-based CAN communication
* Implement safety features (door sensors, overload detection)
* Add RTOS support
* Integrate IoT monitoring system
* Expand to multi-elevator system

---

## 📚 Learning Outcomes

* Practical implementation of CAN protocol
* Distributed embedded system design
* Real-time control system development
* Hardware-software integration

---

## 🏁 Conclusion

This project demonstrates a **CAN-based distributed elevator control system** using LPC2129. It highlights how multiple embedded nodes communicate efficiently to control a real-world system with improved reliability and scalability.

---
