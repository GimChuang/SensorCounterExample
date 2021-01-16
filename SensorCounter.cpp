#include "SensorCounter.h"

SensorCounter::SensorCounter(int _pin, bool _invert01) {
  pin = _pin;
  invert01 = _invert01;
  count = 0;
  prevStatus = 0;
  debounceStamp = 0;
  debounceDelay = DEBOUNCE_DELAY;
}

void SensorCounter::Init() {
  pinMode(pin, INPUT);
}

// This fuction must be called EVERY FRAME!!!
void SensorCounter::Update() {

  int reading = digitalRead(pin);

  // if the status is changed, due to noise or actually pressed
  if (reading != prevStatus) {
    debounceStamp = millis(); // update stamp
  }
  if (millis() - debounceStamp > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current status:
    if (reading != currentStatus) {
      currentStatus = reading;
      // update count
      count = count + GetCurrentStatus(); // if currentStatus is 0 it's ok to add it
    }
  }

  prevStatus = reading;
}

int SensorCounter::GetCurrentStatus() {
  if (invert01)
    return (1 - currentStatus); // (1-value) turns 0 to 1 and 1 to 0
  else
    return currentStatus;
}

int SensorCounter::GetCount() {
  return count;
}

void SensorCounter::ResetCount() {
  count = 0;
}
