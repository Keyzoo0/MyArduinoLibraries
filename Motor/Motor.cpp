#include "Motor.h"

// Konstruktor untuk inisialisasi pin dan variabel
Motor::Motor(int pinEnable, int pinMotorA, int pinMotorB, int pinEncoderA, int pinEncoderB, int chanA, int chanB, long freq, int res, int encodeScale, int interval)
    : _pinEnable(pinEnable), 
    _pinMotorA(pinMotorA), 
    _pinMotorB(pinMotorB), 
    _pinEncoderA(pinEncoderA), 
    _pinEncoderB(pinEncoderB), 
    _chanA(chanA), 
    _chanB(chanB), 
    _freq(freq), 
    _res(res), 
    _pwm(0), 
    _rpm(0),
    _maxPWM(pow(2, res)),
    _minPWM(pow(2, res)*-1),
    _encodeScale(encodeScale),
    _encoder(pinEncoderA, pinEncoderB),
    _encoderVal(0),
    _rpmVal(0),
    _curr(0),
    _prev(0),
    _interval(interval)
{
}

Motor::Motor( int pinEncoderA, int pinEncoderB,  int encodeScale, int interval)
    :
    _pinEncoderA(pinEncoderA), 
    _pinEncoderB(pinEncoderB), 
    // _chanA(chanA), 
    // _chanB(chanB), 
    // _freq(freq), 
    // _res(res), 
    // _pwm(0), 
    _rpm(0),
    // _maxPWM(pow(2, res)),
    // _minPWM(pow(2, res)*-1),
    _encodeScale(encodeScale),
    _encoder(pinEncoderA, pinEncoderB),
    _encoderVal(0),
    _rpmVal(0),
    _curr(0),
    _prev(0),
    _interval(interval)
{
}

Motor::Motor(int pinEnable, int pinMotorA, int pinMotorB, int chanA, int chanB, long freq , int res):
    _pinEnable(pinEnable), 
    _pinMotorA(pinMotorA), 
    _pinMotorB(pinMotorB), 
    _chanA(chanA), 
    _chanB(chanB), 
    _freq(freq), 
    _res(res), 
    _pwm(0), 
    _maxPWM(pow(2, res)),
    _minPWM(pow(2, res)*-1),
    _encoder(0 , 0)
{
}

// Fungsi setup untuk inisialisasi pin
void Motor::setup() {
    pinMode(_pinEnable, OUTPUT);
    pinMode(_pinMotorA, OUTPUT);
    pinMode(_pinMotorB, OUTPUT);
    pinMode(_pinEncoderA, INPUT);
    pinMode(_pinEncoderB, INPUT);
    ledcAttachPin(_pinMotorA, _chanA);
    ledcSetup(_chanA, _freq, _res);
    ledcAttachPin(_pinMotorB, _chanB);
    ledcSetup(_chanB, _freq, _res);
}
void Motor::setupMotor() {
    pinMode(_pinEnable, OUTPUT);
    pinMode(_pinMotorA, OUTPUT);
    pinMode(_pinMotorB, OUTPUT);
    ledcAttachPin(_pinMotorA, _chanA);
    ledcSetup(_chanA, _freq, _res);
    ledcAttachPin(_pinMotorB, _chanB);
    ledcSetup(_chanB, _freq, _res);
}

void Motor::setupEncoder(){
    pinMode(_pinEncoderA, INPUT);
    pinMode(_pinEncoderB, INPUT);
    
}

void Motor::enable() {
    digitalWrite(_pinEnable, HIGH);
}

void Motor::disable() {
    digitalWrite(_pinEnable, LOW);
}

// Setter untuk PWM
void Motor::setPWM(int pwm) {
    _pwm = pwm;
    if (_pwm > 0) {
        if (pwm > _maxPWM) pwm = _maxPWM;
        enable();  
        ledcWrite(_chanA, abs(_pwm));
        ledcWrite(_chanB, 0);
    } else if (_pwm < 0) {
        if (pwm < _minPWM) pwm = _minPWM;  
        enable();
        ledcWrite(_chanB, abs(_pwm));
        ledcWrite(_chanA, 0);
    } else {
        disable();
        ledcWrite(_chanB, 0);
        ledcWrite(_chanA, 0);        
    }
}

// Getter untuk PWM
int Motor::pwm() {
    return _pwm;
}

// Getter untuk RPM
int Motor::rpm() {
    readRPM();
    return _rpm;
}

// Fungsi private untuk pembacaan encoder dan update RPM
void Motor::readRPM() {
    _encoderVal = _encoder.read();
    _curr = millis();
    if (_curr - _prev > _interval) {
        _prev = _curr;
        // Perhitungan RPM, pastikan untuk menyesuaikan dengan encoder yang Anda gunakan
        _rpm = (float)(_encoderVal * 60000 / _encodeScale) / _interval;
        _encoderVal = _encoder.readAndReset();
    }
}

