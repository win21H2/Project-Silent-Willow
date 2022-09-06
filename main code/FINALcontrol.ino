#include <SoftwareSerial.h>
#include <AccelStepper.h>

SoftwareSerial Bluetooth(A8, 38);
// STEP, DIR
AccelStepper LB(1, 41, 40);
AccelStepper LF(1, 43, 42);
AccelStepper RB(1, 45, 44);
AccelStepper RF(1, 47, 46);

int wheelSpeed = 1500;
int dataIn;

const int clockPin = 10;
const int dataPin = 11;
const int latchPin = 12;

/*
0 - 252
1 - 96
2 - 218
3 - 242
4 - 102
5 - 182
6 - 190
7 - 224
8 - 254
9 - 246
*/

void setup (){
    LB.setMaxSpeed(3000);
    LF.setMaxSpeed(3000);
    RB.setMaxSpeed(3000);
    RF.setMaxSpeed(3000);

    pinMode(latchPin,OUTPUT);
    pinMode(clockPin,OUTPUT);
    pinMode(dataPin,OUTPUT);
    
    Bluetooth.begin(9600);
    Serial.begin(38400);

    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST, 252);
    digitalWrite(latchPin,HIGH);
}

void loop(){
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);

    if (Bluetooth.available() > 0) {
        dataIn = Bluetooth.read();

        /*
        do something like the below:

        take the data in and set it as the value of a variable

        check the value of the variable and if it matches for example the value of the number 8, it turns off the AI system
         */

        if (dataIn == 8) {
            if (dataIn == 0) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, 252);
                digitalWrite(latchPin, HIGH);
                stopmoving();
            }
            if (dataIn == 2) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, 218);
                digitalWrite(latchPin, HIGH);
                forward();
            }
            if (dataIn == 1) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, 96);
                digitalWrite(latchPin, HIGH);
                backward();
            }
            if (dataIn == 3) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, (242));
                digitalWrite(latchPin, HIGH);
                sidewaysleft();
            }
            if (dataIn == 4) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, (102));
                digitalWrite(latchPin, HIGH);
                sidewaysright();
            }
            if (dataIn == 5) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, (182));
                digitalWrite(latchPin, HIGH);
                rotateleft();
            }
            if (dataIn == 6) {
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin,clockPin, MSBFIRST, (190));
                digitalWrite(latchPin, HIGH);
                rotateright();
            }
            if (dataIn >= 9) {
                wheelSpeed = dataIn * 10;
            }

            LB.runSpeed();
            LF.runSpeed();
            RB.runSpeed();
            RF.runSpeed();
        }

        else if (dataIn == 7) {
            if (Serial.available() > 0) {
                int inByte = Serial.read();
                switch (inByte) {
                case 'A':
                    LF.setSpeed(wheelSpeed);
                    LB.setSpeed(wheelSpeed);
                    RF.setSpeed(-wheelSpeed);
                    RB.setSpeed(-wheelSpeed);
                    break;
                case 'B':
                    LF.setSpeed(-wheelSpeed);
                    LB.setSpeed(-wheelSpeed);
                    RF.setSpeed(wheelSpeed);
                    RB.setSpeed(wheelSpeed);
                    break;
                case 'N':
                    LF.setSpeed(0);
                    LB.setSpeed(0);
                    RF.setSpeed(0);
                    RB.setSpeed(0);
                    break;
                }
            }
        }
    }
}

void forward() {
    LF.setSpeed(wheelSpeed);
    LB.setSpeed(wheelSpeed);
    RF.setSpeed(-wheelSpeed);
    RB.setSpeed(-wheelSpeed);
}
void backward() {
    LF.setSpeed(-wheelSpeed);
    LB.setSpeed(-wheelSpeed);
    RF.setSpeed(wheelSpeed);
    RB.setSpeed(wheelSpeed);
}
void sidewaysright() {
    LF.setSpeed(wheelSpeed);
    LB.setSpeed(-wheelSpeed);
    RF.setSpeed(wheelSpeed);
    RB.setSpeed(-wheelSpeed);
}
void sidewaysleft() {
    LF.setSpeed(wheelSpeed);
    LB.setSpeed(wheelSpeed);
    RF.setSpeed(wheelSpeed);
    RB.setSpeed(wheelSpeed);
}
void rotateleft() {
    LF.setSpeed(wheelSpeed);
    LB.setSpeed(wheelSpeed);
    RF.setSpeed(wheelSpeed);
    RB.setSpeed(wheelSpeed);
}
void rotateright() {
    LF.setSpeed(-wheelSpeed);
    LB.setSpeed(-wheelSpeed);
    RF.setSpeed(-wheelSpeed);
    RB.setSpeed(-wheelSpeed);
}
void stopmoving() {
    LF.setSpeed(0);
    LB.setSpeed(0);
    RF.setSpeed(0);
    RB.setSpeed(0);
}