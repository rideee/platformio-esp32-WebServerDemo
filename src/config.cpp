#include "config.h"

// WiFi credentials
const char *ssid = "your_ssid";
const char *password = "your_password";

// Hostname
const char *hostname = "esp32";

// Web server object
WebServer server(80);

// Built-in LED pin
const int LED_BUILTIN = 2;
bool ledState = LOW;