// motor.h

#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "Encoder.h"

class Motor {
public:
    // Constructors
    Motor(int pinEnable, int pinMotorA, int pinMotorB, int pinEncoderA, int pinEncoderB, int chanA, int chanB, long freq, int res, int encodeScale, int interval);
    Motor(int pinEnable, int pinMotorA, int pinMotorB, int chanA, int chanB, long freq, int res);//7
    Motor(int pinEncoderA, int pinEncoderB, int encodeScale, int interval);//4
  
    void setup();
    void setupMotor();
    void setupEncoder();
    void setAngle(int angle);
    void setPWM(int pwm);
    void readRPM();
    int pwm();
    int rpm();
    void enable();
    void disable();
    
private:
    int _pinEnable;
    int _pinMotorA;
    int _pinMotorB;
    int _pinEncoderA;
    int _pinEncoderB;
    int _pwm;
    int _rpm;
    long _freq;
    int _res;
    int _chanA;
    int _chanB;
    int _maxPWM;
    int _minPWM;
    int _encodeScale;
    Encoder _encoder;
    int _encoderVal;
    int _rpmVal;
    int _curr;
    int _prev;
    int _interval; 
};

#endif
