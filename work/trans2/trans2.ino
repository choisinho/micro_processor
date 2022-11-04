#include <SoftwareSerial.h>
SoftwareSerial Serial1(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  while(!Serial1) {
    ;
  }
  Serial.println("시리얼포트-1, 인에이블!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >0) {
    Serial.print("시리얼포트=0, 데이터전송 !=");
    int TransChar = Serial.read();
    Serial1.write(TransChar);
    Serial.println(TransChar);
  }
}
