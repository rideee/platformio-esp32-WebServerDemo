#include <Arduino.h>
#include <ESPmDNS.h>
#include <FS.h>
#include <SPIFFS.h>
#include <WebServer.h>
#include <WiFi.h>

#include "config.h"
#include "handlers.h"

void connectToWiFi() {
  Serial.print("\nConnecting to WiFi ");
  WiFi.begin(ssid, password);

  // Blink the LED while connecting to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Blink LED
    delay(500);
    Serial.print(".");
  }

  // Print the IP address once connected
  Serial.print(" OK\n");
  Serial.println("IP address: " + WiFi.localIP().toString());
  Serial.println("Hostname: " + String(hostname));

  // Initialize mDNS
  if (!MDNS.begin(hostname)) {
    Serial.println("Error setting up MDNS responder!");
    return;
  }
  Serial.println("mDNS responder started: open http://" + String(hostname) +
                 ".local to see the website");
}

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState);

  // Start the serial communication
  Serial.begin(115200);

  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("\nAn error has occurred while mounting SPIFFS");
    return;
  }
  Serial.println("\nSPIFFS mounted successfully");

  // List all files in SPIFFS for debugging
  File root = SPIFFS.open("/");
  File file = root.openNextFile();
  while (file) {
    Serial.print("FILE: ");
    Serial.println(file.name());
    file = root.openNextFile();
  }

  // Set hostname
  WiFi.setHostname(hostname);

  // Connect to WiFi
  connectToWiFi();

  // Define the URL endpoints and the handler functions
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/LEDstatus", handleLEDStatus);
  server.on("/style.css", handleStyle);
  server.on("/script.js", handleScript);

  // Start the web server
  server.begin();
  Serial.println("\nHTTP server started");
}

void loop() {
  // Set LED to the value from the previous state
  digitalWrite(LED_BUILTIN, ledState);

  // Handle client requests
  server.handleClient();

  // Reconnect to WiFi if disconnected
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection lost. Reconnecting...");
    connectToWiFi();
  }
}