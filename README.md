# 🚗 Reverse Car Parking System using CAN Protocol

## 📌 Project Overview
The **Reverse Car Parking System** is an embedded systems project designed to improve vehicle safety while reversing.  
It uses an **ultrasonic sensor** to detect obstacles and communicates data between two microcontroller nodes via the **CAN (Controller Area Network) protocol**.  
Real-time feedback is provided to the driver through buzzer alerts and display messages.

---

## ⚙️ How It Works  

### 1️⃣ Distance Measurement  
- The **ultrasonic sensor** measures the distance between the vehicle and obstacles.  
- Distance is calculated based on the time taken for sound waves to reflect back.  

### 2️⃣ Node A (Transmitter)  
- Connected to the ultrasonic driver.  
- Reads distance data from the sensor.  
- Uses the **CAN driver** to transmit the data to Node B via the CAN bus.  

**Files:**  
- `can driver.c`, `can header.c` → CAN protocol handling.  
- `Tx Node A.c` → Application code for transmitting data.  
- `node A.hex`, `tx.hex` → Compiled firmware for Node A.  

### 3️⃣ Node B (Receiver)  
- Listens to the CAN bus for messages sent by Node A.  
- Processes the received data.  
- Triggers **alerts** (buzzer + LCD/LED display) when obstacles are too close.  

**Files:**  
- `can driver.c`, `can header.c` → CAN protocol handling.  
- `Rx Node B.c` → Application code for receiving data.  
- `node B.hex`, `rx.hex` → Compiled firmware for Node B.  

### 4️⃣ Workflow  
1. Car is put in reverse gear.  
2. Ultrasonic sensor measures the distance.  
3. Node A transmits the data via CAN bus.  
4. Node B receives the data and checks safety limits.  
5. Driver is alerted with **real-time feedback** (sound/display).  

---

## 🛠️ Technologies Used  
- **Microcontroller**: LPC2129 (ARM7)  
- **Protocol**: CAN (Controller Area Network)  
- **Sensor**: Ultrasonic sensor  
- **Outputs**: Buzzer + LCD Display  
- **Tools/Software**: Keil uVision, Proteus (for simulation)  

---

## 🚦 Outcome  
- Provides real-time obstacle detection while reversing.  
- Modular and scalable design using **CAN bus**.  
- Enhances driver safety with reliable, noise-resistant communication.  
---

## 🎥 Demo

Here’s how the Reverse car parking system using CAn protocol looks in action:

### 🎥 Demo Video

[![Watch the video](https://img.shields.io/badge/▶-Click%20to%20Play-red)](demo/demo.mp4)


### 🎬 GIF Preview

![App Demo](demo/demo.gif)

