#include "variabel.h"
void setup() {
  Serial.begin(115200);
  setupBluetooth();
  setupAnalog();
  setupButton();
 }

void loop() {
  readAnalog();
  readButton();
  computeForward();
  sendData();
}
