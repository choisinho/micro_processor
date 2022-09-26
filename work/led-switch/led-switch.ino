#define LED_PIN LED_BUILTIN
#define SWITCH 5
#include "Led.h"

Led led(LED_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SWITCH) == LOW)
    led.onLed();
  else
    led.offLed();  
}
