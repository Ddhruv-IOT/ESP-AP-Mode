# 📡 ESP8266 Wi-Fi Setup with AP Mode & LED Indicator

This project allows an **ESP8266** to connect to a Wi-Fi network using **WiFiManager**. If no credentials are saved, the ESP starts in **Access Point (AP) mode**, where users can enter their Wi-Fi details. The onboard **LED turns ON when in AP mode** and **OFF when connected to Wi-Fi**.

## 🚀 Features
- 📶 **Wi-Fi AutoConnect**: Tries to connect to the last saved network.
- 🔒 **Password-Protected AP Mode**: Users enter Wi-Fi credentials via a web portal.
- 💡 **LED Indicator**:
  - **ON (LOW)** → AP Mode (Wi-Fi setup required)
  - **OFF (HIGH)** → Connected to Wi-Fi
- 🔄 **Auto Reconnect**: Saves credentials and reconnects automatically.

## 🛠 Hardware Requirements
- ESP8266 (NodeMCU, Wemos D1 Mini, etc.)
- Micro USB cable
- Computer with Arduino IDE

## 📝 Installation
1. **Install Dependencies**:
   - Install **WiFiManager** library in Arduino IDE.
   - Add **ESP8266 Board Package** via **Boards Manager**.

2. **Flash the Code**:
   - Open the `.ino` file in Arduino IDE.
   - Select **Board: "NodeMCU 1.0 (ESP-12E Module)"**.
   - Connect ESP8266 and **upload** the code.

## 📜 Code Overview
```cpp
#include <ESP8266WiFi.h>
#include <WiFiManager.h>  

#define LED_PIN 2  // Onboard LED (D4 on NodeMCU)

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);  // Default OFF (ESP8266 LED is active LOW)

    WiFiManager wifiManager;

    // Set up AP mode with password protection
    wifiManager.setAPCallback(configModeCallback);

    if (!wifiManager.autoConnect("ESP_Config", "MySecretPass")) {
        Serial.println("Failed to connect. Restarting...");
        ESP.restart();
    }

    Serial.println("Connected to Wi-Fi!");
    digitalWrite(LED_PIN, HIGH);  // Turn OFF LED
}

// Function called when AP mode is activated
void configModeCallback(WiFiManager *myWiFiManager) {
    Serial.println("ESP in AP Mode. Connect to 'ESP_Config' to set Wi-Fi.");
    digitalWrite(LED_PIN, LOW);  // Turn ON LED
}

void loop() {
    // Main code execution
}
