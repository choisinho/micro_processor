int a1=2;
int a2=3;
int a3;
void setup() {
  // put your setup code here, to run once:
  a3=sum(a1, a2);
  Serial.begin(9600);
  Serial.println(a3);
}

void loop() {
  // put your main code here, to run repeatedly:

}

int sum(int a, int b) {
  int c = a+b;
  return c;
}
