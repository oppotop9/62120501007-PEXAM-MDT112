#include "CytronMotorDriver.h"
CytronMD motor(PWM_PWM, 5, 3);   //motor

void setup(){
tone(8,800,400);
Serial.begin(9600);
Serial.println("Hello MDT");
motor.setSpeed(255);
Serial.println("Turn CCW");
delay(2000);
motor.setSpeed(0);
}

void loop(){

}