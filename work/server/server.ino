#include <SoftwareSerial.h>
SoftwareSerial Serial1(2,3);

int firstSensor = 0;
int secondSensor = 0;
int thirdSensor = 0;
int inByte = 0;
int outByte = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);

  while(!Serial1) {
    
  }
  Serial.println("서버, 시리얼포트-2 Ready & HandShake !");
    
  Serial.println("서버, 클라이언트 제어신호-요청신호 수신 Processing!");
  serverCallRece();
  Serial.println();
  
  Serial.println("서버, 제어신호-응답신호 송신 Processing!");
  serverCallResponse();
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void serverCallRece() {
  while(1) {
    int inByte = Serial1.read();

    if(inByte <= 0 || inByte == 255) {
      Serial.println("서버, 클라이언트 제어신호-요청신호 미수신 !");      
    } else {
      Serial.print("서버, 클라이언트 제어신호-요청신호 수신 !=");
      Serial.println(inByte);
      break;
    }
  }
}

void serverCallResponse() {
  while(1) {
    outByte = Serial.read();

    if(outByte <= 0 || outByte == 255) {
      Serial1.write(outByte);
      Serial.print("서버, 클라이언트 제어신호-응답신호 미입력 =>");
      Serial.print("제어신호-응답신호 송신 = ");
      Serial.println(outByte);
      delay(300);
    } else {
      Serial1.write(outByte);
      Serial.println();
      Serial.print("서버, 클라이언트 제어신호-응답신호 송신 != ");
      Serial.println(outByte);
      delay(300);
      break;
    }
  }
}
