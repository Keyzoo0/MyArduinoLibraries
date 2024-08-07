#include <Motor.h>
#include <Omnidirection.h>

Motor motor1(1, 2, 3, 4, 5, 0, 1, 15000, 10, 135, 1000);
Motor motor2(6, 7, 8, 9, 10, 2, 3, 15000, 10, 135, 1000);
Motor motor3(11, 12, 13, 14, 15, 4, 5, 15000, 10, 135, 1000);
Motor motor4(16, 17, 18, 19, 20, 6, 7, 15000, 10, 135, 1000);
Omnidirection kinematik(45., 315., 225., 135., 2, 1, 0.5, 0.1, 0.123, 0.345, 0.456, 0.5);

void setup(){
  motor1.setup();
  motor1.enable();
  motor2.setup();
  motor2.enable();
  motor3.setup();
  motor3.enable();
  motor4.setup();
  motor4.enable();
  kinematik.setup();
}

void loop(){
  kinematik.computeSpeed();
  motor1.setPWM(kinematik.pwm1());
  motor2.setPWM(kinematik.pwm2());
  motor3.setPWM(kinematik.pwm3());
  motor4.setPWM(kinematik.pwm4());
  kinematik.computePosition(motor1.rpm(), motor2.rpm(), motor3.rpm(), motor4.rpm());
}
