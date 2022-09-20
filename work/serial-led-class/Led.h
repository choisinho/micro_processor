#define LED_OFF LOW
#define LED_ON HIGH

class Led {
  public:
    Led(int pin);
    void onLed();
    void offLed();
  private:
    int pin;
};

//Led::Led(int INpin) {
//  pin = INpin;
//  pinMode(pin, OUTPUT);
//}
//
//void Led::onLed() {
//  digitalWrite(LED_PIN, LED_ON);  
//}
//
//
//void Led::offLed(){
//  digitalWrite(LED_PIN, LED_OFF);
//}
