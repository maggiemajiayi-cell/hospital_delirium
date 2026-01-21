// Define the pins for your EMG sensors
// Pins 34 and 35 are good input-only ADC pins on the ESP32.
#define EMG_PIN1 34
#define EMG_PIN2 35

// Define the maximum expected ADC reading
// The standard ESP32 12-bit ADC provides values from 0 to 4095.
// We use 4095 as the stable plotting range max.
const int MAX_ADC_VALUE = 4095; 

void setup() {
  // Use a fast baud rate (115200) for streaming sensor data
  Serial.begin(115200); 
  
  // Clear and informative headers
  Serial.println("time_ms,EMG_1,EMG_2"); 
  
  // *** CRITICAL ESP32 ADC CONFIGURATION ***
  // 1. Set ADC resolution to 12 bits (values 0-4095).
  analogReadResolution(12); 
  
  // 2. Set ADC attenuation to 11dB (ADC_11db). 
  // This allows the full range of input voltage (0 to ~3.9V) to be read, 
  // which is typically required for external sensors.
  analogSetAttenuation(ADC_11db);
}

void loop() {
  // Read the raw sensor values
  int sensorValue1 = analogRead(EMG_PIN1);
  int sensorValue2 = analogRead(EMG_PIN2);

  // Clamp values to the stable plotting range (0 to 4095)
  // This replaces your original, incorrect constraint of 8000.
  sensorValue1 = constrain(sensorValue1, 0, MAX_ADC_VALUE);
  sensorValue2 = constrain(sensorValue2, 0, MAX_ADC_VALUE);

  // Output current time (ms) and sensor data for plotting
  Serial.print(millis());
  Serial.print(",");
  Serial.print(sensorValue1);
  Serial.print(",");
  Serial.println(sensorValue2);

  // Decreased delay for a higher sample rate, better for EMG analysis
  delay(10); 
}