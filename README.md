# Hydroponic Plant Growth Chamber with ESP32

![Hydroponic Plant Growth Chamber](https://github.com/OmkeshLamb2004/Hydrophonic-Plant-Growth-Chamber/blob/master/Project_Photos/20240608_112844.jpg)

## Overview

This project aims to create a smart hydroponic plant growth chamber using the ESP32 Dev Module. The system monitors environmental conditions such as temperature, humidity, and soil moisture, while also automating the watering process based on detected water levels using a float switch. 

## Features

- **Temperature and Humidity Monitoring:** Uses the DHT11 sensor to measure ambient temperature and humidity levels within the growth chamber.
  
- **Soil Moisture Sensing:** Utilizes an analog soil moisture sensor to monitor soil moisture content, crucial for optimal plant growth.
  
- **Automated Watering System:** Controls a water pump based on the water level detected by a float switch, ensuring plants receive adequate hydration.
  
## Components Used

- **ESP32 Dev Module:** Controls and manages the entire system, including sensor readings and pump control.
  
- **DHT11 Temperature and Humidity Sensor:** Provides accurate readings of temperature and humidity.
  
- **Soil Moisture Sensor:** Measures soil moisture levels to determine watering needs.
  
- **Float Switch:** Detects water levels to activate or deactivate the water pump.
  
- **Water Pump:** Delivers water to the plants based on sensor readings.
  
- **Hydroponic Growth Chamber:** Environment where plants grow without soil, relying on nutrient-rich water solutions.

## Setup

1. **Software Setup:**
   - Install Arduino IDE and configure it for ESP32 development.
   - Install necessary libraries: DHT sensor library, Adafruit_GFX , Adafruit_SSD1306.
   
2. **Hardware Setup:**
   - Connect the DHT11 sensor to DHTPIN (pin 13) on the ESP32.
   - Connect the analog soil moisture sensor to SoilMoisturePin (e.g., pin 34).
   - Wire the float switch to Float_Switch pin (e.g., pin 3) for water level detection.
   - Connect the water pump to Pump_Pin (e.g., pin 12) for automated watering.

3. **Upload Code:**
   - Upload the provided Arduino sketch (`hydroponic_growth_chamber.ino`) to the ESP32 Dev Module.

## Usage

- Power on the ESP32 Dev Module.
- Open the Serial Monitor in Arduino IDE to view real-time sensor readings and system status.
- Monitor temperature, humidity, soil moisture levels, and pump activation through the Serial Monitor (But in our project we had an inbuild oled display on the microcontroller to display the readings.
- Adjust delay intervals and sensor thresholds in the code for customized operation based on plant requirements.



## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/OmkeshLamb2004/Hydrophonic-Plant-Growth-Chamber/blob/master/LICENSE.txt) file for details.

