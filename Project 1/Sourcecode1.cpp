
#include <Arduino.h>
// ================== ENUM ==================
enum HeaterState {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

// ================== PIN CONFIG ==================
const int TMP36_PIN = A0;
const int HEATER_PIN = 8;

// ================== THRESHOLDS ==================
const float targetTemp = 30.0;
const float overheatTemp = 40.0;
const unsigned long stabilizingTime = 5000; // 5 seconds

// ================== STATE VARIABLES ==================
HeaterState currentState = IDLE;
unsigned long stateStartTime = 0;

// ================== FUNCTION DECLARATIONS ==================
float readTemperature();
void changeState(HeaterState newState);

// ================== FUNCTIONS ==================

// Reads the temperature from TMP36 sensor in °C
float readTemperature() {
  int analogValue = analogRead(TMP36_PIN);
  float voltage = analogValue * (5.0 / 1023.0);
  return (voltage - 0.5) * 100; // TMP36 formula
}

// Changes the heater's state and logs the change
void changeState(HeaterState newState) {
  currentState = newState;
  stateStartTime = millis();
  Serial.print("State changed to: ");
  switch (newState) {
    case IDLE: Serial.println("IDLE"); break;
    case HEATING: Serial.println("HEATING"); break;
    case STABILIZING: Serial.println("STABILIZING"); break;
    case TARGET_REACHED: Serial.println("TARGET_REACHED"); break;
    case OVERHEAT: Serial.println("OVERHEAT"); break;
  }
}

// ================== ARDUINO SETUP ==================
void setup() {
  Serial.begin(9600);
  pinMode(HEATER_PIN, OUTPUT);
  digitalWrite(HEATER_PIN, LOW);
  changeState(IDLE);
}

// ================== ARDUINO LOOP ==================
void loop() {
  float temperature = readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);

  switch (currentState) {
    case IDLE:
      digitalWrite(HEATER_PIN, LOW);
      if (temperature < targetTemp) {
        changeState(HEATING);
      }
      break;

    case HEATING:
      digitalWrite(HEATER_PIN, HIGH);
      if (temperature >= targetTemp) {
        changeState(STABILIZING);
      }
      if (temperature > overheatTemp) {
        changeState(OVERHEAT);
      }
      break;

    case STABILIZING:
      digitalWrite(HEATER_PIN, LOW);
      if (millis() - stateStartTime >= stabilizingTime) {
        changeState(TARGET_REACHED);
      }
      if (temperature > overheatTemp) {
        changeState(OVERHEAT);
      }
      break;

    case TARGET_REACHED:
      digitalWrite(HEATER_PIN, LOW);
      if (temperature < targetTemp - 2) { // hysteresis
        changeState(HEATING);
      }
      if (temperature > overheatTemp) {
        changeState(OVERHEAT);
      }
      break;

    case OVERHEAT:
      digitalWrite(HEATER_PIN, LOW);
      // Manual reset to IDLE (in real system: button press)
      if (temperature < targetTemp - 5) {
        changeState(IDLE);
      }
      break;
  }

  delay(1000); // read every second
}
