// Simple Smart Irrigation System
// Turns ON pump when soil is dry, turns OFF when soil is wet

int sensorPin = A0;      // Soil moisture sensor connected to A0
int relayPin = 7;        // Relay control pin
int sensorValue = 0;     // To store sensor reading
int threshold = 500;     // Change this value after calibration

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Read soil moisture

  if (sensorValue > threshold) {
    // Soil is dry → turn ON pump
    digitalWrite(relayPin, HIGH);
  } else {
    // Soil is wet → turn OFF pump
    digitalWrite(relayPin, LOW);
  }
  delay(2000); // Wait 2 seconds before next reading
}