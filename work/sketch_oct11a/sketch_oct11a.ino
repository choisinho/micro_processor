void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int r = Serial.read();

    if (r == 0)
      exit(0);
      
    Serial.write(r);

    Serial.print(", dec: ");    
    Serial.print(r, DEC);

    Serial.print(", hex: ");    
    Serial.print(r, HEX);

    Serial.print(", oct: ");    
    Serial.print(r, OCT);

    Serial.print(", oct: ");    
    Serial.print(r, BIN);

    Serial.print(", bin: ");    
    Serial.print(r, BIN);
    Serial.println();      
  }
}

//끝부분에 널문자가 나와야함
