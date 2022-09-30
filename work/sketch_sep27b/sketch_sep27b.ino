void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    int i = Serial.read();    
    if(i>= 65 && i < 97) {
      i += 32;
      Serial.write(i);
    }    
  }
}
