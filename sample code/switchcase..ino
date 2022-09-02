int incomingByte = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    //? make an init switch which compares if the iB is 'O' and if so, start running the code in switch case 'O'
    //! it then compares if the case is 'A' and if so, run the code in case 'A' (THIS IS FOR THE BLUETOOTH CONTROL)

    switch (incomingByte) {
        case 'O':
            Serial.println("IN CASE: O");
            switch (incomingByte) {
                case 'A':
                    Serial.println("A2");
                    break;
                case 'B':
                    Serial.println("B2");
                    break;
            }
            break;


        case 'L':
            Serial.println("IN CASE: L");
            switch (incomingByte) {
                case 'A':
                    Serial.println("A1");
                    break;
                case 'B':
                    Serial.println("B1");
                    break;
            }
            break;
    }
  }
}


// void loop() {
//   if (Serial.available() > 0) {
//     int inByte = Serial.read();
//     switch (inByte) {
//       case 'A':
//         // DO STUFF
//         break;
//       case 'B':
//         // DO STUFF
//         break;
//       case 'N':
//         // DO STUFF
//         break;
//     }
//   }
// }