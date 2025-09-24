const int greenLED = 10;
const int yellowLED = 2;
const int redLED = 3;

const int sensorPIN = A0;

long trafficLightDurationRed = 2;
long trafficLightDurationYellow = 1;
long trafficLightDurationGreen = 2;
 
void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogVal; 
  analogVal = analogRead(A0);
  Serial.println(analogVal);

  // Step 1
  digitalWrite(greenLED, HIGH);
  delay(trafficLightDurationGreen * analogVal);

  // Step 2
  analogVal = analogRead(A0);

  digitalWrite(yellowLED, HIGH);
  delay(trafficLightDurationYellow * analogVal);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  //Step 3
  analogVal = analogRead(A0);

  digitalWrite(redLED, HIGH);
  delay(trafficLightDurationRed * analogVal);
  digitalWrite(yellowLED, HIGH);

  analogVal = analogRead(A0);
  delay(trafficLightDurationYellow * analogVal);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
}
