const int greenLEDPIN = 10;
const int greenLEDBrightness = 128;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int i = 0; i <= 255; i++) {
    analogWrite(greenLEDPIN, i);
    delay(25);
  }

  for(int i = 255; i >= 0; i--) {
    analogWrite(greenLEDPIN, i);
    delay(25);
  }
}
