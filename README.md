# IR-remote-controlled-light

# 📡 ESP32 + TSOP1738 IR Remote Control Project

This project demonstrates how to use an **IR remote** with an **ESP32** and a **TSOP1738 IR receiver** to control an LED (or any output device). The ESP32 receives IR signals using the **IRremoteESP8266** library and reacts to specific button codes.

---

## 🧰 Hardware Required

- ESP32 Development Board  
- TSOP1738 IR Receiver  
- IR Remote (any standard NEC-compatible remote)  
- LED  
- 330Ω Resistor  
- Breadboard and Jumper Wires  

---

## 🔌 Wiring Diagram

| TSOP1738 Pin | Connect To        |
|--------------|------------------|
| **OUT**      | GPIO 23 (D23)     |
| **VCC**      | 3.3V              |
| **GND**      | GND               |

| LED Pin | Connect To        |
|---------|------------------|
| Anode (+) | GPIO 2 via 330Ω |
| Cathode (-) | GND           |

---

## 🧪 IR Codes Example

When you press a button on your remote, the Serial Monitor will show:

```
Protocol  : NEC  
Code      : 0xFFA25D (32 Bits)  
```

Note: `0xFFA25D` is an example. Use the actual codes from your remote.

---

## 💻 Code Overview

The main code listens for IR signals and controls an LED:

```cpp
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t RECV_PIN = 23;
const int LED_PIN = 2;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    uint32_t code = results.value;
    if (code == 0xFFA25D) {
      digitalWrite(LED_PIN, HIGH); // Turn ON LED
    } else if (code == 0xFF629D) {
      digitalWrite(LED_PIN, LOW);  // Turn OFF LED
    }
    irrecv.resume();
  }
}
```

---

## 📦 Library Used

Install via Arduino Library Manager:

- **IRremoteESP8266** by **Mark Szabo**

[GitHub Link to Library](https://github.com/crankyoldgit/IRremoteESP8266)

---

## 🚀 Getting Started

1. Wire up the components as shown.
2. Upload the code using Arduino IDE.
3. Open Serial Monitor (`115200 baud`).
4. Press buttons on the remote to control the LED.

---

## 🛠️ Customization

- Replace the IR codes (`0xFFA25D`, `0xFF629D`) with codes from your own remote.
- Add more actions like toggling a fan, buzzer, or OLED display.

---

## 🧠 Author

Made by Team Code Dreamers from BITS Kurnool