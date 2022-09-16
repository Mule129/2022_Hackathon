int pin_d0 = 0;
int pin_d1 = 1;
int pin_x = a5;
int pin_y = a4;

void setup() {

  pinMode(pin_x, INPUT);
  pinMode(pin_y, INPUT);
  pinMode(pin_d0, OUTPUT);
  pinMode(pin_d1, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(1, 1);
  delay(1000);
  digitalWrite(1, 0);
  delay(1000);

}
