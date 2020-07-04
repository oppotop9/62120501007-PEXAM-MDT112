#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); //lcd
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

motor.setSpeed(-255);
Serial.println("Turn CW");
delay(3000);
motor.setSpeed(0);

lcd.init();
lcd.backlight();
lcd.setCursor(3, 0);
lcd.print("Hello MDT");
delay(1000);
lcd.clear();

delay(200);
tone(8,800,500);
}

void loop(){

}