void setupBluetooth(){
  SerialBT.begin("ESP32_Controller"); // Nama perangkat Bluetooth
  Serial.println("Bluetooth Started sending data to Master Device");
}

void sendData(){
    // Membuat string data yang akan dikirim
  String dataToSend = String(x) + "," + String(y) + "," + String(teta) + "," + String(state1) + "," + String(state2) + "," + String(state3);
  
  // Mengirim data melalui Bluetooth
  SerialBT.println(dataToSend);

  // Mengecek apakah ada data yang diterima
  if (SerialBT.available()) {
    // Membaca data yang diterima
    String receivedData = SerialBT.readStringUntil('\n');
    Serial.println("Received: " + receivedData);
    
    // Mem-parsing data
    sscanf(receivedData.c_str(), "%f,%f,%f", &xpos, &ypos, &th);
    
    // Menampilkan data yang diterima di serial monitor
    // Serial.print("xpos: "); Serial.println(xpos);
    // Serial.print("ypos: "); Serial.println(ypos);
    // Serial.print("th: "); Serial.println(th);
  }

}