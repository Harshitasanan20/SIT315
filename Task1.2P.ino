const int sensorPin = A0;  
const int intPin = 2;
int tempt = 0;

void setup() {
  pinMode(intPin, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(sensorPin, INPUT);  // initialize sensor as an input
  Serial.begin(9600);         
  attachInterrupt(digitalPinToInterrupt(intPin), temp, RISING);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  // Convert the analog value to temperature in degrees Celsius
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureCelsius = (voltage - 0.5) * 100.0;

  
  Serial.print("Current Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.println(" degrees Celsius");

  
  if (temperatureCelsius > 25) {  
    digitalWrite(4, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED turned ON");
  } else {
    digitalWrite(4, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED turned OFF");
  }
  delay(1000);
}

void temp() {
  tempt = digitalRead(intPin);
  if (tempt == 1) {
    Serial.println("Temperature Rising");
  }
}
