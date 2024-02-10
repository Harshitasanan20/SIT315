int motion = 0; 
int motion1 = 0;    
int motion2 = 0;    
int motionPin = 8;      
int motionPin1 = 9;       
int motionPin2 = 3;  
int led1 = 13;             
int led2 = 12;
int led3 = 11;
int led4 = 10;


void setup()  
{

  pinMode(motionPin, INPUT);   
  pinMode(motionPin1, INPUT);  
   pinMode(motionPin2, INPUT);          
  Serial.begin(9600);          
  PCICR |= B00000101;          
  PCMSK0 |= B00000011;
  PCMSK2 |= B00001000;
  startTimer();
}

void loop() {  
}

ISR(PCINT0_vect) {
  motionInterrupt();
  motionInterrupt1();
}

ISR(PCINT2_vect) {
  motionInterrupt2();
}

void motionInterrupt() {
  int val = digitalRead(motionPin);               
  if (val == HIGH)
  
  {
    digitalWrite(led1, HIGH);
    if (motion == LOW) {                        
      Serial.println("Motion 1 detected Sensor0!");
      motion = HIGH;  
     
    }
    
  } else { 
    digitalWrite(led1, LOW);
    if (motion == HIGH) {
      Serial.println("Motion 1 ended Sensor0!");  
      motion = LOW;                         
    }
  }
}

void motionInterrupt1() {
  int val = digitalRead(motionPin1);                
  if (val == HIGH) 
  
  {
     digitalWrite(led2, HIGH);
    if (motion1 == LOW) {
      
      Serial.println("Motion 2 detected Sensor1!");  
      motion1 = HIGH;                            
    }
  } else {  
    digitalWrite(led2, LOW);
    if (motion1 == HIGH) {                    
      Serial.println("Motion 2 ended Sensor1!"); 
      motion1 = LOW;                          
    }
  }
}


void motionInterrupt2() { 
  motion2 = digitalRead(motionPin2);  
  if (motion2 == 1) {                 
    Serial.println("Motion 3 Detected");
    digitalWrite(led3, HIGH);
  } else {
    Serial.println("Motion 3 is not Detected");
    digitalWrite(led3, LOW);
  }
}

void startTimer() {
  noInterrupts();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

 
  OCR1A = 31249;


  TCCR1B |= (1 << CS12) | (1 << CS10);

  TIMSK1 |= (1 << OCIE1A);
 
  TCCR1B |= (1 << WGM12);
  interrupts();
}

int led = 0;  
ISR(TIMER1_COMPA_vect) {
 
  if (led == 0) {
    digitalWrite(led4, HIGH);
    led = 1;
  } else {
    digitalWrite(led4, LOW);
    led = 0;
  }
}
