#include <ESP8266WiFi.h>
#include <WiFiManager.h>  // Install WiFiManager library

#define LED_PIN 2

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
  
    WiFiManager wifiManager;
    
    // Reset WiFi settings (for testing purposes, remove this in production)
    // wifiManager.resetSettings();

    wifiManager.setAPCallback(configModeCallback);

    // AutoConnect with a custom AP name
    if (!wifiManager.autoConnect("ESP_Config", "ESP_01_Password")) {
        Serial.println("Failed to connect. Restarting...");
        ESP.restart();
    }

    Serial.println("Connected to Wi-Fi!");
    digitalWrite(LED_PIN, HIGH);
}

void configModeCallback(WiFiManager *myWiFiManager) {
    Serial.println("ESP in AP Mode. Connect to 'ESP_Config' to set Wi-Fi.");
    digitalWrite(LED_PIN, LOW);  // Turn ON LED
}

void loop() {
    // Your main code
}
