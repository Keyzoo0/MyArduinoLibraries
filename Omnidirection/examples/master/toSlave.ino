void setupWire(){
  Wire.begin(masterAddress);     // Memulai I2C sebagai master 
  Wire.onReceive(receiveEvent); // Handler untuk menerima data dari slave
}  


//menerima data dari slave
void receiveEvent(int bytes) {
  if (bytes == sizeof(float) * 3) {
    Wire.readBytes((char*)&xpos, sizeof(xpos));
    Wire.readBytes((char*)&ypos, sizeof(ypos));
    Wire.readBytes((char*)&th, sizeof(th));
    // Serial.print("xpos : "); Serial.print(xpos);   
    // Serial.print("ypos : "); Serial.print(ypos);   
    // Serial.print("th : "); Serial.print(th);   
  }
}