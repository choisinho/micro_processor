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
