void setupEncoder(){
  Encoder1.setupEncoder();
  Encoder2.setupEncoder();
  Encoder3.setupEncoder();
  Encoder4.setupEncoder();

} 

void readRPM(){
  Encoder1.readRPM();
  Encoder2.readRPM();
  Encoder3.readRPM();
  Encoder4.readRPM();
  int rpm[5] = {0, Encoder1.rpm() , Encoder2.rpm() , Encoder3.rpm() , Encoder4.rpm()};
  kinematik.computePosition(rpm[1] , rpm[2] , rpm[3] , rpm[4] );
  
}
void readPosition(){
  xpos = kinematik.xpos();
  ypos = kinematik.ypos();
  th = kinematik.th();
  // Serial.printf("RPM1 = %4d | RPM1 = %4d | RPM1 = %4d | RPM1 = %4d | Xpos = %3d | Ypos = %3d | th = %3d",rpm[1],rpm[2],rpm[3],rpm[4], xpos , ypos , th );
}
void sendPosition() {
    Wire.beginTransmission(masterAddress);
  
  // Mengirimkan data float sebagai byte array
  Wire.write((byte*)&xpos, sizeof(xpos));
  Wire.write((byte*)&ypos, sizeof(ypos));
  Wire.write((byte*)&th, sizeof(th));
  
  Wire.endTransmission();
  
  // Print the sent data for debugging purposes
  // Serial.print("Sent xpos: ");
  // Serial.print(xpos);
  // Serial.print(", ypos: ");
  // Serial.print(ypos);
  // Serial.print(", th: ");
  // Serial.println(th);

}