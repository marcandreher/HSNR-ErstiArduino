const int B_1 = 0;
const int A_1 = 1;

const int LS = 100;
const int MS = 170;
const int HS = 255;

void setup() {
  pinMode(B_1, OUTPUT);
  pinMode(A_1, OUTPUT);

}

// void loop() {
//   digitalWrite(B_1, LOW);
//   digitalWrite(A_1, HIGH);
//   delay(5000);
//   digitalWrite(B_1, LOW);
//   digitalWrite(A_1, LOW);
//   delay(5000);
//   digitalWrite(B_1, HIGH);
//   digitalWrite(A_1, LOW);
//   delay(5000);
//   digitalWrite(B_1, LOW);
//   digitalWrite(A_1, LOW);
//   delay(2500);
// }

// void loop() {
//   digitalWrite(B_1, LS);
//   digitalWrite(A_1, LOW);

//   delay(1000);

//   digitalWrite(B_1, LOW);
//   digitalWrite(A_1, LOW);

//   digitalWrite(B_1, MS);
//   digitalWrite(A_1, LOW);

//   delay(1000);

//   digitalWrite(B_1, LOW);
//   digitalWrite(A_1, LOW);

//   digitalWrite(B_1, HS);
//   digitalWrite(A_1, LOW);

//   delay(1000);

//   digitalWrite(B_1, LOW);
//   digitalWrite(A_1, LOW);
// }

void loop() {
  digitalWrite(A_1, LOW);

  for(int i = 0; i < 255; i++) {
    digitalWrite(B_1, i);
    delay(50);
  }

  for(int i = 255; i > 0; i--) {
    digitalWrite(B_1, i);
    delay(50);
  }
}