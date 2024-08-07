
#include <Omnidirection.h>
#include <Motor.h>
#include "BluetoothSerial.h"
#include  <Wire.h>

// From Controller
BluetoothSerial SerialBT;

float x, y, teta;
int state1, state2, state3;

// From Slave 
const int masterAddress = 0;
float xpos,ypos,th; 

Omnidirection kinematik(45., -45., -135., 135., 0.1 , 1);
Motor motor1(26, 14, 27, 0, 1, 15000, 10);
Motor motor2(32, 25, 33, 2, 3, 15000, 10);
Motor motor3(15, 13, 12, 4, 5, 15000, 10);
Motor motor4(19, 5,  18, 6, 7, 15000, 10);
