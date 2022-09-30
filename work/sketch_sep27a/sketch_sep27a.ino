void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int n = 123;
  float f = 3.14;

  Serial.println(n, BIN);
  Serial.println(n, DEC);
  Serial.println(n, HEX);

  Serial.println();
  Serial.println(f);
  Serial.println(f, 4);
}

void loop() {
  // put your main code here, to run repeatedly:

}
