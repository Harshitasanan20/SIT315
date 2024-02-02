int led1 = 11;
int led2 = 12;
const int motionSensor1 = 2; 
const int motionSensor2 = 3;

uint8_t motionState1 = 0;
uint8_t motionState2 = 0;

void setup() { 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(motionSensor2, INPUT_PULLUP);
  pinMode(motionSensor1, INPUT_PULLUP);    
  
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(motionSensor1), motion1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motionSensor2), motion2, CHANGE);
}

void loop(){
  digitalWrite(led1, motionState1);
  digitalWrite(led2, motionState2);
  delay(500);
}

void motion1(){
  motionState1 = !motionState1;
  Serial.println("Motion 1 interrupted!");
}

void motion2(){
  motionState2 = !motionState2;
  Serial.println("Motion 2 interrupted!");
}
