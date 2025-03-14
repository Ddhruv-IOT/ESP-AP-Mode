#include <ESP8266WiFi.h>
#include <WiFiManager.h>  // Install WiFiManager library

void setup() {
    Serial.begin(115200);
    
    WiFiManager wifiManager;
    
    // Reset WiFi settings (for testing purposes, remove this in production)
    // wifiManager.resetSettings();
    
    // AutoConnect with a custom AP name
    if (!wifiManager.autoConnect("ESP_Config")) {
        Serial.println("Failed to connect. Restarting...");
        ESP.restart();
    }

    Serial.println("Connected to Wi-Fi!");
}

void loop() {
    // Your main code
}
