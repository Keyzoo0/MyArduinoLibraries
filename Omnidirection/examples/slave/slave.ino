#include "variabel.h"
void setup() {
  Wire.begin();
  Serial.begin(9600);
  setupEncoder();
}

void loop() {
  readRPM();
  readPosition();
  sendPosition();
}
