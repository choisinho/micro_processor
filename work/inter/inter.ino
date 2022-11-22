const byte ledPin = 13;
const byte intPin = 2;
volatile byte ledStatus = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(intPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(intPin), blink, CHANGE);  
}

void loop() {
  Serial.println(ledStatus);
  digitalWrite(ledPin, ledStatus);  
  // put your main code here, to run repeatedly:
}

void blink() {
  ledStatus = !ledStatus;
}
