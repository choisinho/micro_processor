const byte ledPin = 13;
const byte intPin = 2;

volatile byte ledStatus = LOW;
volatile byte switchStatus = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(intPin, INPUT);
  }

void loop() {
  Serial.println(ledStatus);
  digitalWrite(ledPin, ledStatus);
  if(digitalRead(intPin) == HIGH) {
    if(switchStatus == LOW) {
      switchStatus = HIGH;
      if(ledStatus == LOW) {
        blink();
      } else {
        blink();
      }
    }    
  } else {
    switchStatus = LOW;  
  }
}

void blink() {
  ledStatus = !ledStatus;
}
