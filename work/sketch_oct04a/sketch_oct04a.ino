int thisByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial) {    
  }
  Serial.println("ASCII Table ~ Character Map");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print(", dec: ");  
  Serial.print(thisByte, DEC);
  Serial.print(", hex: ");  
  Serial.print(thisByte, HEX);
  Serial.print(", oct: ");  
  Serial.print(thisByte, OCT);
  Serial.print(", letter: ");  
  Serial.write(thisByte);
  Serial.println();
  
  if(thisByte == 127) {
    while(true)
      continue;
  }

  thisByte++;
}
