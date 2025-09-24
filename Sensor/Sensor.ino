const int echoPIN = 18;
const int triggerPIN = 19;

const int greenLEDPIN = 10;
const int redLEDPIN = 3;
const int yellowLEDPIN = 2;

long runtime, distance;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  pinMode(greenLEDPIN, OUTPUT);
  pinMode(yellowLEDPIN, OUTPUT);
  pinMode(redLEDPIN, OUTPUT);
}

void loop() {
  digitalWrite(triggerPIN, LOW);
  digitalWrite(triggerPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPIN, LOW);
  runtime = pulseIn(echoPIN, HIGH);

  distance = runtime * 0.017;
  Serial.print(distance); 
  Serial.print("cm\n");

  digitalWrite(greenLEDPIN, LOW);
  digitalWrite(redLEDPIN, LOW);
  digitalWrite(yellowLEDPIN, LOW);

  if(distance <= 10) {
    digitalWrite(redLEDPIN, HIGH);
  }else if(distance <= 20){
    digitalWrite(yellowLEDPIN, HIGH);
  }else {
    digitalWrite(greenLEDPIN, HIGH);
  }

  delay(50);

  
}
