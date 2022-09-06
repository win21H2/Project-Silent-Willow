// #include <SoftwareSerial.h>
// #include <AccelStepper.h>

// AccelStepper w1(1, 41, 40);
// AccelStepper w2(1, 43, 42);
// AccelStepper w3(1, 45, 44);
// AccelStepper w4(1, 47, 46);

// int wheelSpeed = 1500;

// const int clockPin = 10;
// const int dataPin = 11;
// const int latchPin = 12;

// void setup() {
//   w1.setMaxSpeed(3000);
//   w2.setMaxSpeed(3000);
//   w3.setMaxSpeed(3000);
//   w4.setMaxSpeed(3000);

//   pinMode(latchPin,OUTPUT);
//   pinMode(clockPin,OUTPUT);
//   pinMode(dataPin,OUTPUT);
//   Serial.begin(11520);

//   digitalWrite(clockPin, HIGH);
//   digitalWrite(clockPin, LOW);
//   digitalWrite(latchPin,LOW);
//   shiftOut(dataPin,clockPin,MSBFIRST, 252);
//   digitalWrite(latchPin,HIGH);
// }

// void loop() {
//   if (Serial.available() > 0) {
//     int inByte = Serial.read();
//     switch (inByte) {
//       case 'A':
//         w1.setSpeed(wheelSpeed);
//         w2.setSpeed(wheelSpeed);
//         w3.setSpeed(-wheelSpeed);
//         w4.setSpeed(-wheelSpeed);
//         break;
//       case 'B':
//         w1.setSpeed(-wheelSpeed);
//         w2.setSpeed(-wheelSpeed);
//         w3.setSpeed(wheelSpeed);
//         w4.setSpeed(wheelSpeed);
//         break;
//       case 'N':
//         w1.setSpeed(0);
//         w2.setSpeed(0);
//         w3.setSpeed(0);
//         w4.setSpeed(0);
//         break;
//     }
//   }
//   w1.runSpeed();
//   w2.runSpeed();
//   w3.runSpeed();
//   w4.runSpeed();
// }