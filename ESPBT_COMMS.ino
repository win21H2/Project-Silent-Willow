#include <BluetoothSerial.h>
#include <AccelStepper.h>

// Constants
const int motorPinSTEP = 14;
const int motorPinDIR = 12;

const int motor1PinSTEP = 27;
const int motor1PinDIR = 26;

BluetoothSerial SerialBT;
AccelStepper stepper(AccelStepper::DRIVER, motorPinSTEP, motorPinDIR);
AccelStepper stepper1(AccelStepper::DRIVER, motor1PinSTEP, motor1PinDIR);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_TEST");

  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(500);
  stepper1.setMaxSpeed(3000);
  stepper1.setAcceleration(500);

  pinMode(motorPinSTEP, OUTPUT);
  pinMode(motorPinDIR, OUTPUT);
  pinMode(motor1PinSTEP, OUTPUT);
  pinMode(motor1PinDIR, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char data = SerialBT.read();
    if (data == 'h') {
      stepper.moveTo(1000);
      stepper.runToPosition();
    }

    if (data == 'u') {
      stepper1.moveTo(1000);
      stepper1.runToPosition();
    }

    if (data == 'a') {
      stepper.moveTo(0);
      stepper.runToPosition();
    }

    if (data == 'v') {
      stepper1.moveTo(0);
      stepper1.runToPosition();
    }
  }
}
