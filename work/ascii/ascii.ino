void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
  String str = Serial.readStringUntil('\n');
  
  int i = 0;
  while (i <= str.length()) {
    int s = (int) str[i];
    Serial.write(s);

    Serial.print(", dec: ");    
    Serial.print(s, DEC);

    Serial.print(", hex: ");    
    Serial.print(s, HEX);

    Serial.print(", oct: ");    
    Serial.print(s, OCT);

    Serial.print(", oct: ");    
    Serial.print(s, BIN);

    Serial.print(", bin: ");    
    Serial.print(s, BIN);
    Serial.println();
         
    i++;
    }
  }
}
