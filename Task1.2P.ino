const int motionSensor = 2;  // digital pin for the motion sensor
const int led = 13;          // digital pin for the LED

volatile bool motionDetected = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(motionSensor, INPUT);

  // Set up an interrupt on the motion sensor pin
  attachInterrupt(digitalPinToInterrupt(motionSensor), motionInterrupt, RISING);

  Serial.begin(9600);
}

void loop() {
  checkMotion();
  
}
void checkMotion() {
  if (motionDetected) {
    handleMotion();
    motionDetected = false;
  }
}

void handleMotion() {
  Serial.println("Motion detected!");
  

  digitalWrite(led, HIGH);
  delay(1000); 
  digitalWrite(led, LOW);
}

void motionInterrupt() {

  motionDetected = true;
}
