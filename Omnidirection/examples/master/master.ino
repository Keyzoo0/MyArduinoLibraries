#include "variabel.h"

void setup() {
  Serial.begin(9600);
  setupWire();
  setupBT();
  setupMotor();
}

void loop() {
  readForward();
  sendPosition();
  computeSpeed();
}

