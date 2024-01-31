const int Temp = A0;      
const int sound = 11;       
const int motion = 8;       
const int intTemp = 2;      
const int intMotion = 3;    

volatile bool motionDetected = false;  
volatile bool tempRising = false;      

void setup() {
  pinMode(intTemp, INPUT_PULLUP);
  pinMode(intMotion, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(Temp, INPUT);     
  pinMode(sound, OUTPUT);    
  pinMode(LED_BUILTIN, OUTPUT);   

  attachInterrupt(digitalPinToInterrupt(intTemp), tempInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(intMotion), motionInterrupt, RISING);

  Serial.begin(9600);          
}

void loop() {
  

  checkTemperature();  

  if (tempRising) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED turned ON due to temperature rise");
    tempRising = false;  
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED turned OFF");
  }

  if (motionDetected) {
    tone(sound, 1000);  
    Serial.println("Motion detected - Sound ON");
    delay(2000);          
    noTone(sound);   
    motionDetected = false; 
  }
}

void tempInterrupt() {
  tempRising = true;  
}

void motionInterrupt() {
  motionDetected = true;  
}

void checkTemperature() {
  int TempValue = analogRead(Temp);
  float voltage = TempValue * (5.0 / 1023.0);
  float temperatureCelsius = (voltage - 0.5) * 100.0;

  if (temperatureCelsius > 50) {
    tempRising = true;
  } else {
    tempRising = false;
  }
}
