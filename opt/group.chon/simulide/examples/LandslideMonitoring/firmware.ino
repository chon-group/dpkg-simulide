#include <Javino.h>   /* https://javino.chon.group */

#define vibrationSensorPin  3 
#define buzzerPin           11 
#define moistureSensorPin   A0
#define analogDrySoil       1023 /* calibration of soil moisture sensor */
#define analogWetSoil       400  /* calibration of soil moisture sensor */

Javino javino;
int moistureLevel = 0, alertLevel = 0;
boolean moved = false;
unsigned long buzzerLastTime = 0;

void serialEvent() { javino.readSerial(); }

void setup() {
  /* GPIO configuration */
  pinMode(vibrationSensorPin, INPUT); 
  pinMode(moistureSensorPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);
  /* Functions to be executed when the agent determines an action in the environment */
  javino.act["danger"] = dangerSiren;
  javino.act["critical"] = criticalSiren;
  javino.act["deactivate"] = deactivateSiren;
  /* Function to be executed when the agent requests environmental perceptions */
  javino.perceive(getExogenousPerceptions);
  javino.start(9600);
}

void loop() {
  refreshSiren();
  readSoilMoisture();
  readVibration();
  javino.run();
}

void getExogenousPerceptions() {
  javino.addPercept("moisture(" + String(moistureLevel) + ")");
  if (moved) {
    javino.addPercept("movement(true)");
    moved = false; 
  }
}
 
void dangerSiren() { alertLevel = 1; }
 
void criticalSiren() {
  alertLevel = 2;
  for (int i = 1000; i <= 2000; i += 50) {
    tone(buzzerPin, i);
    delay(10);
  }
  noTone(buzzerPin);
}

void deactivateSiren() {
  alertLevel = 0;
  noTone(buzzerPin);
}

void refreshSiren() {
  if (alertLevel == 0) {
    deactivateSiren();
  }
  else if ((alertLevel == 1) && ((millis() - buzzerLastTime) > 1000)) { 
    buzzerLastTime = millis();
    tone(buzzerPin, 1000);
    alertLevel = -1;          
  }
  else if ((alertLevel == -1) && ((millis() - buzzerLastTime) > 250)) {
    noTone(buzzerPin);
    buzzerLastTime = millis();
    alertLevel = 1;    
  }
  else if (alertLevel == 2) { 
    criticalSiren();
  }
}

void readSoilMoisture() {
  moistureLevel = constrain(analogRead(moistureSensorPin), analogWetSoil, analogDrySoil); 
  moistureLevel = map(moistureLevel, analogWetSoil, analogDrySoil, 100, 0); 
}

void readVibration() {
  if (digitalRead(vibrationSensorPin) == HIGH) { moved = true; }
}
