#include "BluetoothSerial.h"

// Membuat instance BluetoothSerial
BluetoothSerial SerialBT;

// Variabel yang akan dikirim
float x ;
float y ;
float teta ;
int state1 ;
int state2 ;
int state3 ;

// Variabel yang akan diterima
float xpos, ypos, th;


// Define pin connections
const int button1Pin = 25; 
const int button2Pin = 26; 
const int button3Pin = 23; 

const int lxPin = 14; 
const int lyPin = 27; 
const int rxPin = 35; 
const int ryPin = 32; 

// Variables to hold button states
bool button1State = false;
bool button2State = false;
bool button3State = false;

float lxValue;
float lyValue;
float rxValue;
float ryValue;

float atanVal;
int inv_yR ;


