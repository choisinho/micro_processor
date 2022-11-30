#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4,5);

int in = A0;
int temp = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(in, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(in);
  if(BTSerial.available()) {
    //받을 때
    Serial.write(BTSerial.read());
    delay(300);    
  }
  if(Serial.available()) {
    //보낼 때
    String s = String(temp);
    BTSerial.println(s);
    delay(300);       
  }
}
