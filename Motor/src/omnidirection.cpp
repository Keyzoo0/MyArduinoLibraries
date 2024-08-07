#include "omnidirection.h"

// Konstruktor
Omnidirection::Omnidirection(int pinEnable, int pinMotorA, int pinMotorB, int pinEncoderA, int pinEncoderB)
    : _pinEnable(pinEnable), 
    _pinMotorA(pinMotorA),
     _pinMotorB(pinMotorB), 
     _pinEncoderA(pinEncoderA), 
     _pinEncoderB(pinEncoderB), 
     _angle(0),
      _pwm(0), 
      _rpm(0) {
}

// Fungsi setup
void Omnidirection::setup() {
    pinMode(_pinEnable, OUTPUT);
    pinMode(_pinMotorA, OUTPUT);
    pinMode(_pinMotorB, OUTPUT);
    pinMode(_pinEncoderA, INPUT);
    pinMode(_pinEncoderB, INPUT);
}

// Setter untuk sudut
void Omnidirection::setAngle(int angle) {
    _angle = angle;
    // Tambahkan kode untuk mengatur sudut motor di sini
}

// Setter untuk PWM
void Omnidirection::setPWM(int pwm) {
    _pwm = pwm;
    analogWrite(_pinEnable, _pwm);
}

// Getter untuk sudut
int Omnidirection::angle() {
    return _angle;
}

// Getter untuk PWM
int Omnidirection::pwm() {
    return _pwm;
}

// Getter untuk RPM
int Omnidirection::rpm() {
    updateRPM();
    return _rpm;
}

// Fungsi private untuk pembacaan encoder dan update RPM
void Omnidirection::updateRPM() {
    // Tambahkan kode untuk pembacaan encoder dan update RPM di sini
}
