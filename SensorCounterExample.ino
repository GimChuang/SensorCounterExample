#include "SensorCounter.h"

// sensors
#define SENSOR_PIN_1 2
#define SENSOR_PIN_2 3
#define SENSOR_INVERT01 false

SensorCounter sc_1(SENSOR_PIN_1, SENSOR_INVERT01);
SensorCounter sc_2(SENSOR_PIN_2, SENSOR_INVERT01);

void setup() {

  sc_1.Init();
  sc_2.Init();

  Serial.begin(9600);
}

void loop() {

  // Sensor Counter's Update() must be called EVERY FRAME
  sc_1.Update();
  sc_2.Update();

  Serial.print("Sensor 1: ");
  Serial.print(sc_1.GetCurrentStatus());
  Serial.print(", Sensor 2: ");
  Serial.println(sc_2.GetCurrentStatus());

  Serial.print("Count  1: ");
  Serial.print(sc_1.GetCount());
  Serial.print(", Count  2: ");
  Serial.println(sc_2.GetCount());
}
