#include <Arduino.h>
#include <vector>
#include <map>
#define fireSensorsNumber 8

enum directions {NORTH_WEST, NORTH, NORTH_EAST, EAST, 
                SOUTH_EAST, SOUTH, SOUTH_WEST, WEST};
std::map<directions, uint32_t> anglesMap{{directions::NORTH, 0}, {directions::NORTH_WEST, 45}, 
                                        {directions::WEST, 90}, {directions::SOUTH_WEST, 135}, 
                                        {directions::SOUTH, 180}, {directions::SOUTH_EAST, 225}, 
                                        {directions::EAST, 270}, {directions::NORTH_EAST, 315}};

class fire_sensor {
public:
    void init(const unsigned& analogInputPin, const unsigned& digitalInputPin, const directions& dir) {
        analogInputPinNumber = analogInputPin;
        digitalInputPinNumber = digitalInputPin;
        //pinMode(analogInputPin, INPUT); TODO: check if it is needed for analog pin 
        pinMode(digitalInputPin, INPUT);
        direction = dir;
        angle = anglesMap[dir];
    }
    directions getDirection () {
        return direction;
    }
    uint32_t getAnalogReading () {
        analogReadValue = analogRead(analogInputPinNumber);
        return analogReadValue;
    }
    uint32_t getDigitalReading () {
        digitalReadValue = digitalRead(digitalInputPinNumber);
        return digitalReadValue;
    }

private:
    uint32_t analogInputPinNumber;
    uint32_t digitalInputPinNumber;
    directions direction;
    uint32_t angle = 0;

    uint32_t analogReadValue = 0;
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
    float calcFireAnglePos() {
        return 0;
    }
    
private:
    std::vector<fire_sensor> sensors;
    const float angleBetweenSensors = 360.f / static_cast<float>(fireSensorsNumber);
};
