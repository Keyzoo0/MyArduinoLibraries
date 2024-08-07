#include <Wire.h>
#include <Motor.h>
#include <Omnidirection.h>

Motor Encoder1 ( 2 , 3, 135, 1000);
Motor Encoder2 ( 2 , 3, 135, 1000);
Motor Encoder3 ( 2 , 3, 135, 1000);
Motor Encoder4 ( 2 , 3, 135, 1000);
Omnidirection kinematik (45, -45 , -135 , 135, 0.2 , 0.1, 0.2, 0.3, 0.1) ; 
float xpos,ypos,th;
const int masterAddress = 0 ;
// int rpm[5];