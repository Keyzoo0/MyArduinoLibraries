void setupBT(){
  SerialBT.begin("ESP32_Master"); // Nama perangkat Bluetooth
}

void readForward(){
     if (SerialBT.available()) {
    // Membaca data yang diterima
    String receivedData = SerialBT.readStringUntil('\n');
    Serial.println("Received: " + receivedData);
    
    // Mem-parsing data
    sscanf(receivedData.c_str(), "%f,%f,%f,%d,%d,%d", &x, &y, &teta, &state1, &state2, &state3);
    
    // Menampilkan data yang diterima di serial monitor
  //   Serial.print("x: "); Serial.print(x);
  //   Serial.print(" y: "); Serial.print(y);
  //   Serial.print(" teta: "); Serial.print(teta);
  //   Serial.print(" state1: "); Serial.print(state1);
  //   Serial.print(" state2: "); Serial.print(state2);
  //   Serial.print(" state3: "); Serial.println(state3);
  }
}

void sendPosition(){
  String dataToSend = String(xpos) + "," + String(ypos) + "," + String(th);
  
  // Mengirim data melalui Bluetooth
  SerialBT.println(dataToSend);

}