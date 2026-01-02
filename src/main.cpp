#define MAX_PWM 255
//from here for the left side
#define L_RPWM 25 
#define L_LPWM 26
#define L_REN 27
#define L_LEN 14
//from here for the right side
#define R_RPWM 32
#define R_LPWM 33
#define R_REN 12
#define R_LEN 13

void setup(){
  pinMode(L_RPWM, OUTPUT);
  pinMode(L_LPWM, OUTPUT);
  pinMode(L_REN, OUTPUT);
  pinMode(L_LEN,OUTPUT);
  pinMode(R_RPWM, OUTPUT);
  pinMode(R_LPWM, OUTPUT);
  pinMode(R_REN, OUTPUT);
  pinMode(R_LEN, OUTPUT);
  
  digitalWrite(L_REN,HIGH);
  digitalWrite(L_LEN,HIGH);
  digitalWrite(R_REN,HIGH);
  digitalWrite(R_LEN,HIGH);
}
void loop(){
  int joyX = analogRead(34);//turn
  int joyY = anmalogRead(35);//forward

  joyX = map(joyX, 0, 4095, -255, 255);//set the coordinate maps for x joystic i have given an avg value
  joyY = map(joyY, 0, 4095, -255, 255);

  int left = joyY + joyX;
  int right = joyY - joyX;

  left = constrain(left, -255, 255);
  right = constrain(right, -255, 255);

  drivelBT2(L_RPWM, L_LPWM, left);
  drivelBT2(R_RPWM, R_LPWM, right);  
}

void drivelBT2(int rpwm, int lpwm, speed){
  if(speed > 0){
    analogWrite(rpwm, speed);
    analogWrite(lpwm, 0);
  }
  else if(speed < 0){
    analogWrite(rpwm, 0);
    analogWrite(lpwm, -speed);
  }
  else{
    analogWrite(rpwm, 0);
    analogWrite(lpwm, 0);
  }
}

