const int sensorPin = A0;  
const int intPin = 2;
int tempt = 0;

void setup() {
  pinMode(intPin, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(sensorPin, INPUT);  
  Serial.begin(9600);         
  attachInterrupt(digitalPinToInterrupt(intPin), temp, RISING);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureCelsius = (voltage - 0.5) * 100.0;

  
  if (temperatureCelsius > 50) {  
    digitalWrite(4, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(1000);
}

void temp() {
  tempt = digitalRead(intPin);
  if (tempt == 1) {
    Serial.println("Temperature Rising");
  }
}
