# 🚀 Arduino LoRa Communication with RA-02 SX1278

This project demonstrates **basic point-to-point LoRa communication** using two Arduino UNO boards and RA-02 SX1278 LoRa modules. It uses the **RadioHead** library for SPI communication between the microcontroller and LoRa module.

## 📦 Project Structure

/lora-arduino-project/
│
├── tx_lora.ino # Transmitter Arduino code
├── rx_lora.ino # Receiver Arduino code
└── README.md # This documentation file


---

## 🧰 Requirements

### Hardware
- 2x Arduino UNO
- 2x LoRa RA-02 SX1278 Modules (433MHz)
- Breadboard + Jumper Wires
- Power supply (3.3V for RA-02 modules)
- 2x 10µF capacitor (optional but recommended for voltage stability)
- 2x 433MHz Antenna

### Software
- Arduino IDE
- [RadioHead Library](http://www.airspayce.com/mikem/arduino/RadioHead/)

To install the library:

1. Open **Arduino IDE**
2. Go to **Sketch > Include Library > Manage Libraries**
3. Search for **"RadioHead"** and install it

---

## 🔌 Wiring Diagram

> 💡 RA-02 SX1278 operates at **3.3V**. Do NOT connect to 5V.

| RA-02 SX1278 | Arduino UNO |
|--------------|-------------|
| VCC          | 3.3V        |
| GND          | GND         |
| SCK          | D13         |
| MISO         | D12         |
| MOSI         | D11         |
| NSS / CS     | D10         |
| RESET        | D9          |
| DIO0         | D2          |

Ensure the antenna is connected to avoid damage to the module.

---

## 📤 Transmitter Code

File: `tx_lora.ino`  
- Sends `"Halo dari pengirim!"` every 3 seconds
- Uses SPI and interrupts for efficient communication

---

## 📥 Receiver Code

File: `rx_lora.ino`  
- Listens for incoming messages
- Displays received data via Serial Monitor

---

## 📡 Frequency Configuration

Ensure both transmitter and receiver are using the **same frequency**:

```cpp
#define RF95_FREQ 433.0  // MHz
