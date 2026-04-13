# 🚗 CAN Bus Transmitter Node

## 📌 Overview

This project implements a Controller Area Network (CAN) Transmitter Node using a microcontroller. The transmitter node is responsible for collecting data (such as sensor values or commands) and sending it over the CAN bus to other nodes in the network.

The CAN protocol is widely used in automotive and industrial applications due to its robustness, reliability, and real-time communication capability.

---

## 🎯 Objective

* To design and develop a CAN-based transmitter node
* To understand CAN protocol frame structure and communication
* To transmit real-time data over a CAN network

---

## 🧠 System Description

The transmitter node reads input data (e.g., sensor values, switches, or ADC readings) and sends it to the CAN bus using a CAN controller.

### 🔁 Working Principle

1. Input data is read from peripherals (GPIO / ADC)
2. Data is formatted into a **CAN frame**
3. CAN controller transmits the frame onto the CAN bus
4. Other nodes (receiver) read and process the data

---

## ⚙️ Hardware Components

* Microcontroller (e.g., ARM7 / STM32 / Arduino)
* CAN Controller (e.g., MCP2515)
* CAN Transceiver (e.g., TJA1050)
* Crystal Oscillator
* Power Supply
* Connecting wires

---

## 💻 Software Requirements

* Embedded C programming
* Keil / STM32CubeIDE / Arduino IDE
* CAN driver libraries

---

## 📡 CAN Frame Format Used

* Identifier (ID): Defines message priority
* DLC (Data Length Code): Number of data bytes (0–8)
* Data Field: Actual transmitted data
* CRC:Error detection
* ACK: Acknowledgement from receiver

🚀 Features

* Reliable communication using CAN protocol
* Real-time data transmission
* Error detection and handling
* Multi-node communication support

🧪 Applications

* Automotive systems (ECU communication)
* Industrial automation
* Battery management systems
* IoT and embedded networking

📚Conclusion

This project demonstrates the implementation of a CAN transmitter node capable of sending data efficiently across a CAN network. It helps in understanding **low-level communication protocols** used in real-world embedded systems.

