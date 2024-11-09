#ifndef CONFIG_H
#define CONFIG_H

#include <WebServer.h>

// WiFi credentials
extern const char *ssid;
extern const char *password;

// Hostname
extern const char *hostname;

// Web server object
extern WebServer server;

// Built-in LED pin
extern const int LED_BUILTIN;
extern bool ledState;

#endif  // CONFIG_H