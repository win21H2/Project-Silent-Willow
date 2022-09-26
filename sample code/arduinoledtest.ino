int rled = 2;
int gled = 3;

void setup() {
  Serial.begin(11520);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case 'R':
        digitalWrite(rled, HIGH);
        digitalWrite(gled, LOW);
        break;
      case 'B':
        digitalWrite(rled, LOW);
        digitalWrite(gled, HIGH);
        break;
      case 'O':
        digitalWrite(rled, LOW);
        digitalWrite(gled, LOW);
        break;
    }
  }
}
