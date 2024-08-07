/*
Jobdesk ESP32 Controller (FreeRTOS)
  Core1 :
  Read ADC Analog dan State Button
  drawing Xpos,Ypos dan Th on Oled

  Core2 : 
  Send Data X,Y ,teta dan state button to Master
  Receive Xpos,Ypos dan Th from Master
  
Jobdesk ESP32 Master (FreeRTOS)
  Core1 :
  Receive Data X,Y dan teta From Controler
  Receive Xpos,Ypos dan Th from Slave
  Send Xpos,Ypos dan Th to Controler

  Core2 : 
  ComputeSpeed
  setPWM 4 Motor

Jobdesk ESP32 Slave (FreeRTOS)
  Core1 :
  Read Encoder (RPM) 
  Read IMU  (Degree)

  Core2 :
  ComputePosition 
  Send Xpos,Ypos dan Th to master

Komunikasi 
Controller -> Master = Bluetooth Serial
Master -> Slave = I2C Tranmiission
Slave -> Master = I2C Request
Master -> Controller -> Bluetooth Serial
*/
