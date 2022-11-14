#include "SoftwareSerial.h"

SoftwareSerial Serial1(2, 3);

int firstSensor = 0;
int secondSensor = 0;
int thirdSensor = 0;
int inByte = 0;
int outByte = 0;

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(7, INPUT);
  Serial.println("클라이언트, 시리얼포트-1 Ready & HandShake!");
  
  Serial.println("클라이언트, 제어신호-요청신호 송신 및 서버 제어번호-응답신호 수신 Processing!");
  clientCallTransResponseRece();
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void clientCallTransResponseRece() {
  while(1) {
    inByte = Serial1.read();
    outByte = Serial.read();

    if(inByte <= 0 || inByte == 255) {
      Serial1.write(outByte);
      Serial.print("클라이언트, 서버 제어신호-응답신호 미수신 => ");
      Serial.print("제어신호-요청신호송신 = ");
      Serial.println("outByte");
      delay(300);
    } else {
      Serial.println();
      Serial.print("클라이언트, 서버 제어신호-응답신호수신 != ");
      Serial.println(inByte);
      delay(300);
      break;
    }
  }
}
