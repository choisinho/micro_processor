int a1=2;
int a2=3;
int a3;

void setup() {
  // put your setup code here, to run once:
  sum(a1, a2, a3);
  Serial.begin(9600);
  Serial.println(a3);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void sum(int a, int b, int& c) {
  c = a+b;
}
