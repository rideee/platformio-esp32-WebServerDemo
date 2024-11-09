#include "handlers.h"

#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>
#include <WebServer.h>

#include "config.h"

// Function to handle the root URL "/"
void handleRoot() {
  // Open the HTML file from SPIFFS
  File file = SPIFFS.open("/index.html", "r");
  if (!file) {
    Serial.println("Failed to open file");
    server.send(500, "text/plain", "Failed to open file");
    return;
  }

  // Read the file content
  String html = file.readString();
  file.close();

  // Replace placeholders with actual values
  html.replace("{{IP}}", WiFi.localIP().toString());
  html.replace("{{hostname}}", hostname);
  html.replace("{{LED_STATUS}}", ledState ? "ON" : "OFF");

  // Send the HTML content with a 200 OK status
  server.send(200, "text/html", html);
  Serial.println("Client handled");
}

// Function to handle the "/on" URL
void handleOn() {
  ledState = HIGH;
  digitalWrite(LED_BUILTIN, ledState);
  server.send(200, "text/plain", "LED is ON");
  Serial.println("LED turned ON");
}

// Function to handle the "/off" URL
void handleOff() {
  ledState = LOW;
  digitalWrite(LED_BUILTIN, ledState);
  server.send(200, "text/plain", "LED is OFF");
  Serial.println("LED turned OFF");
}

// Function to handle the "/LEDstatus" URL
void handleLEDStatus() {
  server.send(200, "text/plain", ledState ? "ON" : "OFF");
}

// Function to handle the "/style.css" URL
void handleStyle() {
  // Open the CSS file from SPIFFS
  File file = SPIFFS.open("/style.css", "r");
  if (!file) {
    Serial.println("Failed to open file");
    server.send(500, "text/plain", "Failed to open file");
    return;
  }

  // Read the file content
  String css = file.readString();
  file.close();

  // Send the CSS content with a 200 OK status
  server.send(200, "text/css", css);
}

// Function to handle the "/script.js" URL
void handleScript() {
  // Open the JavaScript file from SPIFFS
  File file = SPIFFS.open("/script.js", "r");
  if (!file) {
    Serial.println("Failed to open file");
    server.send(500, "text/plain", "Failed to open file");
    return;
  }

  // Read the file content
  String js = file.readString();
  file.close();

  // Send the JavaScript content with a 200 OK status
  server.send(200, "application/javascript", js);
}