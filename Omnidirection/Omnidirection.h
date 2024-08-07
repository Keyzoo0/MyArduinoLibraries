#ifndef OMNIDIRECTION_H
#define OMNIDIRECTION_H

#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>


class Omnidirection {

public:
    // Constructor
    Omnidirection(int angle1, int angle2, int angle3, int angle4, int lamdaFar, int lamdaNear, float rWheel, int LengthAlpha, float scaleX, float scaleY, float scaleTh, float ts);
    Omnidirection(float angle1, float angle2, float angle3, float angle4 , float LengthAlpha , float LamdaFar);
    Omnidirection(int angle1, int angle2, int angle3, int angle4, float rWheel,float scaleX, float scaleY, float scaleTh, float ts) ;

    void setup();
    void computeSpeed();
    void computePwm(float x , float y , float teta );
    void computePosition(int rpm1, int rpm2, int rpm3, int rpm4 );

    // Getters for PWM
    int pwm1();
    int pwm2();
    int pwm3();
    int pwm4();

    // Getters for RPM
    int rpm1();
    int rpm2();
    int rpm3();
    int rpm4();

    // Getters for odometry
    float xdot();
    float ydot();
    float thdot();
    float xpos();
    float ypos();
    float th();

    // Getters for current setpoints
    int x();
    int y();
    int teta();

private:
    float _angle1;
    float _angle2;
    float _angle3;
    float _angle4;
    int _x;
    int _y;
    int _teta;
    int _pwm1;
    int _pwm2;
    int _pwm3;
    int _pwm4;
    int _rpm1;
    int _rpm2;
    int _rpm3;
    int _rpm4;
    int _lamdaFar;
    int _lamdaNear;
    float _lenghtAlpha;
    float _rWheel;
    float _xdot;
    float _ydot;
    float _thdot;
    float _scaleX;
    float _scaleY;
    float _scaleTh;
    float _ts;
    float _xpos;
    float _ypos;
    float _th;
    float readYaw();
    Adafruit_BNO055 bno ;

};



#endif
