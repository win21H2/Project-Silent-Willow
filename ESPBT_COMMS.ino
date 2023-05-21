#include <BluetoothSerial.h>
#include <AccelStepper.h>

// Constants
const int motor1PinSTEP = 14;
const int motor1PinDIR = 12;

const int motor2PinSTEP = 27;
const int motor2PinDIR = 26;

const int motor3PinSTEP = 25;
const int motor3PinDIR = 33;

const int motor4PinSTEP = 32;
const int motor4PinDIR = 23;

BluetoothSerial SerialBT;
AccelStepper stepper1(AccelStepper::DRIVER, motor1PinSTEP, motor1PinDIR);
AccelStepper stepper2(AccelStepper::DRIVER, motor2PinSTEP, motor2PinDIR);
AccelStepper stepper3(AccelStepper::DRIVER, motor3PinSTEP, motor3PinDIR);
AccelStepper stepper4(AccelStepper::DRIVER, motor4PinSTEP, motor4PinDIR);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_TEST");

  stepper1.setMaxSpeed(3000);
  stepper1.setAcceleration(500);
  stepper2.setMaxSpeed(3000);
  stepper2.setAcceleration(500);
  stepper3.setMaxSpeed(3000);
  stepper3.setAcceleration(500);
  stepper4.setMaxSpeed(3000);
  stepper4.setAcceleration(500);

  pinMode(motor1PinSTEP, OUTPUT);
  pinMode(motor1PinDIR, OUTPUT);
  pinMode(motor2PinSTEP, OUTPUT);
  pinMode(motor2PinDIR, OUTPUT);
  pinMode(motor3PinSTEP, OUTPUT);
  pinMode(motor3PinDIR, OUTPUT);
  pinMode(motor4PinSTEP, OUTPUT);
  pinMode(motor4PinDIR, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char data = SerialBT.read();
    if (data == 'q') {
      stepper1.moveTo(1000);
      stepper1.runToPosition();
    }

    if (data == 'w') {
      stepper2.moveTo(1000);
      stepper2.runToPosition();
    }

    if (data == 'e') {
      stepper3.moveTo(1000);
      stepper3.runToPosition();
    }

    if (data == 'r') {
      stepper4.moveTo(1000);
      stepper4.runToPosition();
    }

    if (data == 't') {
      stepper1.moveTo(0);
      stepper1.runToPosition();
    }

    if (data == 'y') {
      stepper2.moveTo(0);
      stepper2.runToPosition();
    }

    if (data == 'u') {
      stepper3.moveTo(0);
      stepper3.runToPosition();
    }

    if (data == 'i') {
      stepper4.moveTo(0);
      stepper4.runToPosition();
    }
  }
}
