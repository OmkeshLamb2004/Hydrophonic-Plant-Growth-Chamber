const int soilMoisturePin = 15; // Analog pin connected to the soil moisture sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin); // Read analog value from sensor
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100); // Map the analog value to percentage (0-100)
  
  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  
  delay(1000); // Delay for readability, adjust as needed
}
