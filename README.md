# ElderlyCopilot: Age-Friendly Service System for Seniors

![System Architecture](system_architecture.png)  
*Figure 1: Three-layer system architecture of ElderlyCopilot*

## 📌 Overview
**ElderlyCopilot** is an IoT-based service system designed to address key challenges faced by elderly communities, including heavy-load transportation, nighttime safety, and fragmented health management. The system integrates **shared logistics**, **smart sensing**, and **extensible health ecosystems** into a unified platform, leveraging modular hardware and adaptive algorithms for elderly-friendly interaction.

---

## ✨ Key Features
### 1. **Shared Load Transport**
- 🚜 **TPU-printed tracked chassis** with 8.23:1 load-to-weight ratio (20kg capacity at 2.43kg自重).
- 🤖 **Nine-axis tilt control** via M5Core2’s MPU6886 accelerometer (35ms latency, 93% success rate in elderly testing).
- 🌐 **BLE 5.0 mesh networking** (50m range) for community-wide shared vehicle access.

### 2. **Smart Nightlight with Behavior Analytics**
- 🌙 **Dual-sensor fusion**: 
  - Passive infrared (5-7m range, ±15° vertical FOV) + ambient light (0.1-1000 Lux). 
  - 98.2% accuracy in detecting nighttime bathroom visits (200h real-world testing).
- 💡 **Adaptive illumination**: 
  - 3-lumen moonlit mode (23:00-5:00) → 10-lumen motion-triggered mode (30s duration).
- 🖼️ **Emotional design**: 
  - Customizable 3D-printed lampshades via [MakerLab](https://makerlab.example.com) (e.g., family photo浮雕).

### 3. **Extensible Health Hub (Upcoming)**
- 🩸 **Bluetooth 5.2/BLE** integration for third-party devices (glucometers, BP monitors).
- 🔒 **Encrypted local storage** (16GB TF card) with time-series health/behavior data.

---

## 🛠️ Technical Implementation
| Module               | Core Components                                                                 |
|----------------------|---------------------------------------------------------------------------------|
| **Smart Hub**        | M5Core2 (ESP32-D0WDQ6-V3, 16MB Flash, MPU6886 IMU, Bluetooth 5.0)              |
| **Shared Cart**      | Arduino Nano → ESP32 (future), L298N motor driver, HC-05 Bluetooth, 12V encoder motors |
| **Smart Nightlight** | ESP32, WS2812B LED strip, AM312 PIR sensor, BH1750 light sensor                |

---

## 📊 Performance Metrics
- **Shared Cart**: 
  - 96% pass rate on 6 terrain types (15° slopes, 5cm obstacles). 
  - 0.3m/s safety speed (±1° steering precision).
- **Nightlight**: 
  - <0.1% false triggers (vs. 23% baseline). 
  - 92% user satisfaction in pilot communities.

---

## 🚀 Future Roadmap
1. **ESP32 upgrade** for carts (ESP-NOW protocol).  
2. **TinyML integration** for voice-controlled AI assistant (fall detection, health alerts).  
3. **Blockchain-based health data sharing** with clinics/hospitals.  

---

## 📂 Repository Structure
