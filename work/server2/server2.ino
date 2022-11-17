#include <SoftwareSerial.h>
SoftwareSerial Serial1(2,3);

int firstSensor = 0;
int secondSensor = 0;
int thirdSensor = 0;
int inByte = 0;
int outByte = 0;

void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);

  while(!Serial1) {
    ;
  }
  Serial.println("서버, 시리얼포트-2 Ready & HandShake !");
    
  Serial.println("서버, 클라이언트 제어신호-요청신호 수신 Processing!");
  serverCallRece();
  Serial.println();
  
  Serial.println("서버, 제어신호-응답신호 송신 Processing!");
  serverCallResponse();
  Serial.println();

  Serial.println("서버, 클라이언트 제어신호-인지신호 수신 Processing ! ");
  serverAckRece();
  Serial.println();

  Serial.println("서버-클라이언트, '연결설정' ! ");
//  while(Serial1.available() > 0) {
//    ;
//  }
}

void loop() {  
  if(Serial1.available() > 0){   
    firstSensor = Serial1.read();
    secondSensor = Serial1.read();
    thirdSensor = Serial1.read();

    Serial.print("수신 데이터-firatSensor = ");
    Serial.print(firstSensor);
    Serial.print("  ");
      
    Serial.print("secondSensor = ");
    Serial.print(secondSensor);
    Serial.print("  ");
      
    Serial.print("thirdSensor = ");
    Serial.println(thirdSensor);
    }    
  //delay(1000);
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

void serverAckRece() {
  while(1){
    int inByte = Serial1.read();

    if (inByte <= 0 || inByte == 255){
      Serial.println("서버, 클라이언트 제어신호-인지신호 미수신 ! ");
      }
    else{
      Serial.print("서버, 클라이언트 제어신호-인지신호 수신 ! ");
      Serial.println(inByte);
      break;
    }
  }
}
