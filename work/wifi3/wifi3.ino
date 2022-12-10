#include <SoftwareSerial.h>
#define DEBUG true
 
SoftwareSerial wifi(2,3); 
  
void setup() {
  Serial.begin(9600);
  wifi.begin(9600);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.write("잠시만 기다려주세요... (와이파이 연결중)\n");  
  sendData("AT+CWJAP=\"Sinho\",\"123456780\"\r\n",10000,DEBUG);  //와이파이 찾아서 연결
  Serial.write("남은 설정이 있습니다...\n");
  delay(10000);
  sendData("AT+CIFSR\r\n",1000,DEBUG);          // 아두이노가 켜지면 ESP8266에 할당된 IP 주소를 받아옵니다.
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG);       // 멀티 커넥션(다중 접속)을 위한 설정
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // 포트 번호 80번으로 설정  
  Serial.write("연결 작업 마침. 오류를 확인하세요.\n");
}
  
void loop() {
  // esp8266에 웹에서 메시지가 왔는지 파악
  if(wifi.available()) {      
    if(wifi.find("+IPD,")) {
      delay(1000); // 시리얼 버퍼에 보내져온 데이터가 찰 때 까지 기다림
      // connect id를 알아냄
      // 아스키 코드값으로 되어있기 때문에 48을 뺌
      int connectionId = wifi.read()-48;
      wifi.find("pin=");
      int pinNumber = (wifi.read()-48)*10;           // 웹에서 보내온 11 12 13 3가지의 숫자를 보내는데 10의 자릿수를 판별
      pinNumber += (wifi.read()-48);                 // 1의 자릿수 판별
      digitalWrite(pinNumber, !digitalRead(pinNumber)); // LED 토글
      
      // make close command
      String closeCommand = "AT+CIPCLOSE="; 
      closeCommand+=connectionId;        // append connection id
      closeCommand+="\r\n";
      sendData(closeCommand,1000,DEBUG); // close connection
    }
  }
}
 
// ESP8266의 정보를 알아내고 설정하기 위한 함수
// 할당된 IP 주소, 포트번호 설정 등
String sendData(String command, const int timeout, boolean debug) {
    String response = "";
    wifi.print(command);
    long int time = millis();
     
    while( (time+timeout) > millis()) {
      while(wifi.available()) {
        char c = wifi.read();
        response+=c;
      }
    }    
    if(debug) {
      Serial.print(response);
    }
    return response;
}
