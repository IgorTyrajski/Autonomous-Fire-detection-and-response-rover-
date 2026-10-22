#include <Arduino.h>
#include <vector>

#define fireSensorsNumber 8

enum directions {NORTH_WEST, NORTH, NORTH_EAST, EAST, 
                SOUTH_EAST, SOUTH, SOUTH_WEST};

class fire_sensor {
public:
    void init(const unsigned& analogInputPin, const unsigned& digitalInputPin, const directions& dir) {
        analogInputPinNumber = analogInputPin;
        digitalInputPinNumber = digitalInputPin;
        //pinMode(analogInputPin, INPUT); TODO: check if it is needed for analog pin 
        pinMode(digitalInputPin, INPUT);
        direction = dir;
    }
    directions getDirection () {
        return direction;
    }
    unsigned getAnalogReading () {
        return analogReadValue;
    }
    unsigned getDigitalReading () {
        return digitalReadValue;
    }

private:
    unsigned analogInputPinNumber;
    unsigned digitalInputPinNumber;
    directions direction;

    unsigned analogReadValue = 0;
    bool digitalReadValue = LOW;
};

class fire_recognition_system {
public:
    fire_recognition_system () {
        sensors.reserve(fireSensorsNumber);
    }
    void addSensor (fire_sensor& sensor) {
        sensors.push_back(sensor);
    }
    
private:
    std::vector<fire_sensor> sensors;
};
