#include <Arduino.h>
#include "Led.h"

int pin;

Led::Led(int INpin) {
  pin = INpin;   
  pinMode(pin, OUTPUT);
}

void Led::onLed() {
  digitalWrite(pin, LED_ON);  
}

void Led::offLed(){
  digitalWrite(pin, LED_OFF);
}
