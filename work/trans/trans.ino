#include "SoftwareSerial.h"
SoftwareSerial Serial1(2,3);

char TransChar[30] = "KNUT";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  while(!Serial1){
    ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("전송시작!");
  Serial1.write(TransChar, 30);
  Serial.println("전송완료!");
  Serial.println(TransChar);
  delay(1000);
}
