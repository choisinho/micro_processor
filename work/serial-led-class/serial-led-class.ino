#define LED_PIN LED_BUILTIN
#include "Led.h"

Led led(LED_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  led.onLed();
  delay(1000);
  led.offLed();
  delay(1000);
}
