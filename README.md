
# 🚀 Arduino LoRa Communication with RA-02 SX1278

This project demonstrates **basic point-to-point LoRa communication** using two Arduino UNO boards and RA-02 SX1278 LoRa modules. It uses the **RadioHead** library for SPI communication between the microcontroller and LoRa module.

## 📦 Project Structure

```
/lora-arduino-project/
│
├── tx_lora.ino       # Transmitter Arduino code
├── rx_lora.ino       # Receiver Arduino code
└── README.md         # This documentation file
```

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
```
---

## 🧪 Usage Steps

1. Upload `tx_lora.ino` to one Arduino (Transmitter)
2. Upload `rx_lora.ino` to another Arduino (Receiver)
3. Open **Serial Monitor** on both boards (baud rate: 9600)
4. You should see the transmitter sending messages, and the receiver printing them

---

## 🛠️ Troubleshooting

* **No message received?**

  * Double-check wiring and pin numbers
  * Make sure both use same frequency
  * Ensure both modules are powered with **stable 3.3V**
  * Add decoupling capacitors if voltage drops

* **RA-02 gets hot or fails?**

  * Likely powered with 5V — use 3.3V only

* **Message corrupt or missing?**

  * Keep modules at least 1 meter apart during testing
  * Use antenna to improve signal stability

---

## 📚 Notes

* This example uses **LoRa (not LoRaWAN)**. It’s point-to-point only.
* For LoRaWAN (e.g., The Things Network), consider modules with built-in LoRaWAN stack (RAK811, ESP32 LoRa, etc.)

---

## 🧑‍💻 Author

Developed by Alif Jamaludin
If you use this project, consider crediting or sharing improvements!

---
