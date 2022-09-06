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
}

void loop(){

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