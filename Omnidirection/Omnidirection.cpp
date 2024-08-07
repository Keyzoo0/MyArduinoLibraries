#include "Omnidirection.h"


float xstar[2] = {2.0, 2.0}, ystar[2] = {-0.5, -2.0}, thstar[2] = {0., 0.};
int limitcounter = 1, counter = 0;
float error_x = 0, error_y = 0, error_th = 0, gain = 0, error_norm1 = 0, error_norm2 = 0, xstars = 0, ystars = 0, thstars=0;


float d2r(int degree){
  float radians = degree * 0.0174533;
  return radians;
}
Omnidirection::Omnidirection(int angle1, int angle2, int angle3, int angle4, int lamdaFar, int lamdaNear, float rWheel, int LengthAlpha, float scaleX, float scaleY, float scaleTh, float ts) :
    _angle1(angle1),
    _angle2(angle2),
    _angle3(angle3),
    _angle4(angle4),
    _x(0),
    _y(0),
    _teta(0),
    _pwm1(0),
    _pwm2(0),
    _pwm3(0),
    _pwm4(0),
    _rpm1(0),
    _rpm2(0),
    _rpm3(0),
    _rpm4(0),
    _lamdaFar(lamdaFar),
    _lamdaNear(lamdaNear),
    _lenghtAlpha(LengthAlpha),
    _rWheel(rWheel),
    _xdot(0),
    _ydot(0),
    _thdot(0),
    _scaleX(scaleX),
    _scaleY(scaleY),
    _scaleTh(scaleTh),
    _ts(ts),
    _xpos(0),
    _ypos(0),
    _th(0),
    bno(Adafruit_BNO055(55))
{
}
Omnidirection::Omnidirection(int angle1, int angle2, int angle3, int angle4, float rWheel,float scaleX, float scaleY, float scaleTh, float ts) :
    _angle1(angle1),
    _angle2(angle2),
    _angle3(angle3),
    _angle4(angle4),
    _x(0),
    _y(0),
    _teta(0),
    _rpm1(0),
    _rpm2(0),
    _rpm3(0),
    _rpm4(0),
    _rWheel(rWheel),
    _xdot(0),
    _ydot(0),
    _thdot(0),
    _scaleX(scaleX),
    _scaleY(scaleY),
    _scaleTh(scaleTh),
    _ts(ts),
    _xpos(0),
    _ypos(0),
    _th(0),
    bno(Adafruit_BNO055(55))
{
}

Omnidirection::Omnidirection(float angle1, float angle2, float angle3, float angle4 , float LengthAlpha , float lamdaFar):
  _angle1(angle1),
    _angle2(angle2),
    _angle3(angle3),
    _angle4(angle4),
    _x(0),
    _y(0),
    _teta(0),
    _pwm1(0),
    _pwm2(0),
    _pwm3(0),
    _pwm4(0),
    _rpm1(0),
    _rpm2(0),
    _rpm3(0),
    _rpm4(0),
    _lamdaFar(lamdaFar),
    _lamdaNear(0),
    _lenghtAlpha(LengthAlpha),
    _rWheel(0),
    _xdot(0),
    _ydot(0),
    _thdot(0),
    _scaleX(0),
    _scaleY(0),
    _scaleTh(0),
    _ts(0),
    _xpos(0),
    _ypos(0),
    _th(0),
    bno(Adafruit_BNO055(55))
  
{}


void Omnidirection::setup(){
     bno.setExtCrystalUse(true);
}

void Omnidirection::computePosition(int rpm1, int rpm2, int rpm3, int rpm4){
  _th = readYaw();
  _xdot = 0; _ydot = 0; _thdot = 0;
  _rpm1 = rpm1; _rpm2 = rpm2; _rpm3 = rpm3; _rpm4 = rpm4;

_xdot = _rWheel * ((cos(_th) * (cos(d2r(_angle1)) * _rpm1 + cos(d2r(_angle2)) * _rpm2 + cos(d2r(_angle3)) * _rpm3 + cos(d2r(_angle4)) * _rpm4)) + 
                   (sin(_th) * (sin(d2r(_angle1)) * _rpm1 + sin(d2r(_angle2)) * _rpm2 + sin(d2r(_angle3)) * _rpm3 + sin(d2r(_angle4)) * _rpm4)));
                   
_ydot = _rWheel * ((-sin(_th) * (cos(d2r(_angle1)) * _rpm1 + cos(d2r(_angle2)) * _rpm2 + cos(d2r(_angle3)) * _rpm3 + cos(d2r(_angle4)) * _rpm4)) + 
                   (cos(_th) * (sin(d2r(_angle1)) * _rpm1 + sin(d2r(_angle2)) * _rpm2 + sin(d2r(_angle3)) * _rpm3 + sin(d2r(_angle4)) * _rpm4)));
                   
// _thdot = _rWheel * _lenghtAlpha * (_rpm1 + _rpm2 + _rpm3 + _rpm4);
  
  // odometry scale
  _xdot = _xdot * _scaleX;
  _ydot = _ydot * _scaleY;
//   _thdot = _thdot * _scaleTh;
  _thdot = readYaw();
  // update position
  _xpos = _xpos + _xdot * _ts;
  _ypos = _ypos + _ydot * _ts;
  _th = _th + _thdot * _ts;
  
//   if(_th > 180) _th = _th - 360;
//   else if(_th < -180) _th = _th + 360;
}

void Omnidirection::computeSpeed(){
  error_x = 0, error_y = 0, error_th = 0, gain = 0, error_norm1 = 0, error_norm2 = 0, xstars = 0, ystars = 0, thstars=0;
  xstars = xstar[counter];
  ystars = ystar[counter];
  thstars = thstar[counter];
  error_x = xstars - _xpos;
  error_y = ystars - _ypos;
  error_th = thstars - _th;
  error_norm1 = sqrt(error_x*error_x + error_y*error_y);
  error_norm2 = sqrt(error_x*error_x + error_y*error_y + error_th * error_th);
  if(error_norm1 < 0.4){
    gain = 0;
    if(++counter>limitcounter)counter=limitcounter;
    else Serial.println("sampai");
  }
  else if(error_norm1<0.7)gain = _lamdaNear;
  else gain = _lamdaFar;
  _pwm4 = (1/_rWheel)*gain*(cos(d2r(135.)) * (cos(_th) * error_x - sin(_th) * error_y)) + (sin(d2r(135.)) * (sin(_th) * error_x + cos(_th) * error_y )) + (_lenghtAlpha * error_th);
  _pwm3 = (1/_rWheel)*gain*(cos(d2r(-135.)) * (cos(_th) * error_x - sin(_th) * error_y)) + (sin(d2r(-135.)) * (sin(_th) * error_x + cos(_th) * error_y )) + (_lenghtAlpha * error_th);
  _pwm2 = (1/_rWheel)*gain*(cos(d2r(-45.)) * (cos(_th) * error_x - sin(_th) * error_y)) + (sin(d2r(-45.)) * (sin(_th) * error_x + cos(_th) * error_y )) + (_lenghtAlpha * error_th);
  _pwm1 = (1/_rWheel)*gain*(cos(d2r(45.)) * (cos(_th) * error_x - sin(_th) * error_y)) + (sin(d2r(45.)) * (sin(_th) * error_x + cos(_th) * error_y )) + (_lenghtAlpha * error_th);

//   Serial.print(xpos);Serial.print("\t");Serial.print(ypos);Serial.print("\t");Serial.print(th);
//   Serial.print("\t");Serial.print(xstars);Serial.print("\t");Serial.print(ystars);Serial.print("\t");Serial.print(thstars);
//   Serial.print("\t");Serial.print(pwm[0]);Serial.print("\t");Serial.print(pwm[1]);Serial.print("\t");Serial.print(pwm[2]);Serial.print("\t");Serial.print(pwm[3]);
//   Serial.print("\t");Serial.print(gain);Serial.print("\t");Serial.print(error_norm1);Serial.print("\t");Serial.print(error_x);Serial.print("\t");
//   Serial.print(error_y);Serial.print("\t");Serial.print(error_th);Serial.print("\t");Serial.println(counter);
}

void Omnidirection::computePwm(float x , float y , float teta){
  _pwm4 = _lamdaFar * (cos(d2r(_angle4))*x + sin(d2r(_angle4))*y  + teta);
  _pwm3 = _lamdaFar * (cos(d2r(_angle3))*x + sin(d2r(_angle3))*y  + teta);
  _pwm2 = _lamdaFar * (cos(d2r(_angle2))*x + sin(d2r(_angle2))*y  + teta);
  _pwm1 = _lamdaFar * (cos(d2r(_angle1))*x + sin(d2r(_angle1))*y    + teta);

}

int Omnidirection::pwm1() { return _pwm1; }
int Omnidirection::pwm2() { return _pwm2; }
int Omnidirection::pwm3() { return _pwm3; }
int Omnidirection::pwm4() { return _pwm4; }

int Omnidirection::rpm1() { return _rpm1; }
int Omnidirection::rpm2() { return _rpm2; }
int Omnidirection::rpm3() { return _rpm3; }
int Omnidirection::rpm4() { return _rpm4; }

float Omnidirection::xdot() { return _xdot; }
float Omnidirection::ydot() { return _ydot; }
float Omnidirection::thdot() { return _thdot; }
float Omnidirection::xpos() { return _xpos; }
float Omnidirection::ypos() { return _ypos; }
float Omnidirection::th() { return _th; }

int Omnidirection::x() { return _x; }
int Omnidirection::y() { return _y; }
int Omnidirection::teta() { return _teta; }

float Omnidirection::readYaw(){
  sensors_event_t event;
  bno.getEvent(&event);
  return event.orientation.x;
}