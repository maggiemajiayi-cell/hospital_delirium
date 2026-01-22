#include <DFRobot_MAX30102.h>
#include <Wire.h>

// Create an object from the DFRobot_MAX30102 class
DFRobot_MAX30102 particleSensor;

// Define global variables
int32_t SPO2;           
int32_t heartRate;     
int8_t SPO2Valid;       
int8_t heartRateValid;  

void setup() {
  Serial.begin(115200);   // Initialize Serial Monitor
  Wire.begin();           // Enable I2C (SDA: A4, SCL: A5)

  // If sensor fails to initialize, print an error message
  while (!particleSensor.begin()) {
    Serial.println("MAX30102 not found!");
    delay(1000);  // 1 sec delay before trying again
  }

  // Sensor configuration
  particleSensor.sensorConfiguration(
    60,              // LED Brightness
    SAMPLEAVG_16,    // Sample Average
    MODE_MULTILED,   // Mode: both IR and Red
    SAMPLERATE_400,  // Sample Rate
    PULSEWIDTH_411,  // Pulse Width
    ADCRANGE_16384   // ADC Range
  );
}

void loop() {
  // Call library function to calculate heart rate and SPO2
  particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);

  if (heartRateValid) {
    Serial.print("Heart Rate: ");
    Serial.println(heartRate);
  }

  if (SPO2Valid) {
    Serial.print("SPO2: ");
    Serial.print(SPO2);
    Serial.println("%");
  }

  delay(500);  // Small delay for readability
}