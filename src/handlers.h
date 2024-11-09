#ifndef HANDLERS_H
#define HANDLERS_H

#include <WebServer.h>

extern WebServer server;
extern bool ledState;

void handleRoot();
void handleOn();
void handleOff();
void handleLEDStatus();
void handleStyle();
void handleScript();

#endif  // HANDLERS_H