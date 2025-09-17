//code to test whether the moisture sensor can sense the moisture. This code checks soil moisture level and accordingly blinks the led of the ESP8266.
// Automatic Plant Irrigation - Stage 1 Prototype
// ESP8266 + Capacitive Soil Moisture Sensor + Onboard LED

// Pin configuration
const int sensorPin = A0;   // Only analog pin available on ESP8266
const int ledPin    = 2;    // Onboard LED (GPIO2, active LOW on NodeMCU)

// Moisture threshold (tune this later by testing)
int moistureThreshold = 500;  // Adjust after reading raw values (0–1023)

void setup() {
  Serial.begin(115200);       // Serial monitor for debugging
  pinMode(ledPin, OUTPUT);    // Configure LED pin
}

void loop() {
  // Read sensor value
  int sensorValue = analogRead(sensorPin);

  // Print raw sensor value
  Serial.print("Moisture Sensor Value: ");
  Serial.println(sensorValue);

  // Compare with threshold
  if (sensorValue < moistureThreshold) {
    digitalWrite(ledPin, HIGH);   // Dry soil → LED OFF (since active LOW)
  } else {
    digitalWrite(ledPin, LOW);    // Wet soil → LED ON
  }

  delay(1000); // Read every 1 second
}
