void setupAnalog(){
  // Set analog pins as input (optional as analog pins are input by default)
  pinMode(lxPin, INPUT);
  pinMode(lyPin, INPUT);
  pinMode(rxPin, INPUT);
  pinMode(ryPin, INPUT);

}

void readAnalog(){
   // Read analog values from joysticks
   lxValue = analogRead(lxPin);
   lyValue = analogRead(lyPin);
   rxValue = analogRead(rxPin);
   ryValue = analogRead(ryPin);

  //  // Print analog values
  // Serial.print("LX: ");
  // Serial.print(lxValue);
  // Serial.print("LY: ");
  // Serial.print(lyValue);
  // Serial.print("RX: ");
  // Serial.print(rxValue);
  // Serial.print("RY: ");
  // Serial.println(ryValue);

} 