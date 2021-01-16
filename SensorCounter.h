#ifndef SensorCounter_h
#define SensorCounter_h

#define DEBOUNCE_DELAY 10

#include <Arduino.h>

class SensorCounter {

  private:
    int pin;
    bool invert01;
    int count;

    // debouce
    int currentStatus;
    int prevStatus;
    unsigned long debounceStamp;
    unsigned long debounceDelay;

  public:
    SensorCounter(int _pin, bool _invert01);
    void Init();
    void Update();
    int GetCurrentStatus();
    int GetCount();
    void ResetCount();
};

#endif
