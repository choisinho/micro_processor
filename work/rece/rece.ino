#include "SoftwareSerial.h"
SoftwareSerial Serial1(2,3);

char ReceChar[30];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  while(!Serial1) {
    ;
  }
  Serial.println("수신준비 완료!");
}

void loop() {
  // put your main code here, to run repeatedly:  
  Serial1.readBytes(ReceChar, 30);
  Serial.println(ReceChar);
  Serial.println("수신완료!");
  Serial.println();
}
