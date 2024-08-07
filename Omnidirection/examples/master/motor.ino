void setupMotor(){
  motor1.setupMotor();
  motor2.setupMotor();
  motor3.setupMotor();
  motor4.setupMotor();

}

void computeSpeed(){
  kinematik.computePwm(x, y, teta);
  int pwm[5] = { NULL, kinematik.pwm1(), kinematik.pwm2(), kinematik.pwm3(), kinematik.pwm4() };
  motor1.setPWM(pwm[1]);
  motor2.setPWM(pwm[2]);
  motor3.setPWM(pwm[3]);
  motor4.setPWM(pwm[4]);
  // Serial.printf("x:%4dy:%4dth:%4d | pwm1:%4d pwm2:%4d pwm3:%4d pwm4:%4d\n", x, y, teta, pwm[1], pwm[2], pwm[3], pwm[4]);

}