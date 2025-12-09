int forward = 1;
int reverse = 0;
int left = 0;
int right = 1;
int etu_m = 0
int taka_m = 1;

int dirA = 12;
int pwmA = 3;
int dirB = 13;
int pwmB = 11;

void setup(){
  setupArdu();
}
void loop{
  delay(5000);
  drive(taka_m, forward, 150);
  delay(2000);
  stop(taka_m);
  delay(10);
  drive(taka_m, reverse, 150);
  delay(2000);
  stop(taka_m);
  delay(10);

  drive(etu_m, left, 200);
  delay(2000);
  drive(etu_m, right, 200);
  delay(2000);
  stop(etu_m);
  delay(10);
}

void drive(byte motor, byte dir, byte spd){
  if(motor == etu_m){
    digitalWrite(dirA, dir);
    analogWrite(pwmA, spd);
  }
  else if (motor == taka_m){
    digitalWrite(dirB, dir);
    analogWrite(pwmB, spd);
  }
}
void stop(byte motor){
  drive(motor, 0, 0);
}
void setupArdu(){
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);

  digitalWrite(pwmA, LOW);
  digitalWrite(pwmB, LOW);
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
}

