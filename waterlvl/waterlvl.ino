// Set the float sensor to pin 3
#define Float_Switch 13

void setup() {
  // Start the serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Initialize pin 3 as an input with an internal pull-up resistor
  pinMode(Float_Switch, INPUT_PULLUP);
}

void loop() {
  // Read the state of the float sensor
  if(digitalRead(Float_Switch) == HIGH) {
    // Print "HIGH" to the Serial Monitor
    Serial.println("HIGH");
  } else {
    // Print "LOW" to the Serial Monitor
    Serial.println("LOW");
  }

  // Add a small delay to avoid flooding the Serial Monitor with messages
  delay(1000);
}
