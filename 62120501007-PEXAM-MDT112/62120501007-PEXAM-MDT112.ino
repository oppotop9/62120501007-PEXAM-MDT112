#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); //lcd
#include "CytronMotorDriver.h"
CytronMD motor(PWM_PWM, 5, 3);   //motor
bool lastState = true;
int Push = 1;

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

pinMode(2,INPUT_PULLUP);
}

void loop(){
     bool currentState = digitalRead(2);
    int speedtime = Push*51; //255=fullspeed , 51=20% speedmotor
     if(lastState > currentState)
    {
        if (Push<=5) {
        int speed = speedtime*-1;
        motor.setSpeed(speed);
        Push++;
        }
        else if (Push>5) {
            if (Push==6) {
                motor.setSpeed(-204);
                Push++;
            }
            else if (Push==7) {
                motor.setSpeed(-153);
                Push++;
            }
            else if (Push==8) {
                motor.setSpeed(-102);
                Push++;
            }
            else if (Push==9) {
                motor.setSpeed(-51);
                Push++;
            }
            else if (Push==10) {
                motor.setSpeed(0);
                Push=1;
            }
        }
    }
    else if(lastState < currentState)
    {
        
    }

    lastState = currentState;
    delay(50);
}