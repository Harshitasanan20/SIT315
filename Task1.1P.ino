// C++ code
//
const int tempPin = A0;
const int led = 4;

void setup() {
  Serial.begin(9600);
  pinMode(tempPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;
  
  Serial.print("Current Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");

  if (temperature > 50) {
    digitalWrite(led, HIGH);  
  } else {
    digitalWrite(led, LOW);  
  }

  delay(1000);
}
