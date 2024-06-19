#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 13          // Digital pin connected to the DHT sensor
#define soilMoisturePin 15 // Analog pin connected to the soil moisture sensor
#define Float_Switch 27    // Pin connected to the float switch
#define pumpPin 36         // Digital pin connected to the motor pump

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Hydroponic Plant Growth Chamber...");

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display(); // Clear the display buffer
  delay(2000);       // Pause for 2 seconds

  dht.begin();
  pinMode(soilMoisturePin, INPUT);
  pinMode(Float_Switch, INPUT_PULLUP);
  pinMode(pumpPin, OUTPUT); // Set pump pin as output
}

void loop() {
  // Read temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Read soil moisture
  int soilMoistureValue = analogRead(soilMoisturePin);
  int moisturePercentage = map(soilMoistureValue, 0, 4095, 0, 100);

  // Read float switch state
  int floatSwitchState = digitalRead(Float_Switch);

  // Debugging output for float switch state
  Serial.print("Float Switch State: ");
  Serial.println(floatSwitchState);

  // Display information on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(t);
  display.println(" C");
  display.print("Humidity: ");
  display.print(h);
  display.println(" %");
  display.print("Soil Moisture: ");
  display.print(moisturePercentage);
  display.println("%");
  display.print("Float Switch: ");
  display.println(floatSwitchState == HIGH ? "HIGH" : "LOW");
  display.display();

  // Control the pump based on float switch state
  if (floatSwitchState == HIGH) {
    // Turn off pump
    digitalWrite(pumpPin, LOW);
    Serial.println("Pump OFF");
  } else {
    // Turn on pump
    digitalWrite(pumpPin, HIGH);
    Serial.println("Pump ON");
  }

  delay(1000); // Delay for readability, adjust as needed
}
