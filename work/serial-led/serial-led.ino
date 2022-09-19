#define LED_PIN LED_BUILTIN
#define LED_OFF LOW
#define LED_ON HIGH

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, LED_ON);
  delay(1000);
  digitalWrite(LED_PIN, LED_OFF);
  delay(1000);
}
