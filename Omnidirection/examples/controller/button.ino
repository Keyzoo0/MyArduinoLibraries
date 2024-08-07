void setupButton(){
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
} 

void readButton(){
    // Read button states
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
//  // Print button states
//   Serial.print("Button 1: ");
//   Serial.println(button1State);
//   Serial.print("Button 2: ");
//   Serial.println(button2State);
//   Serial.print("Button 3: ");
//   Serial.println(button3State);

 
}