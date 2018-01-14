#include "fakehallsensor.hpp"

void HallSensor::init() {}

bool HallSensor::measure() {
    if (this->measurements.empty()) return false;

    bool val = this->measurements.front();
    this->measurements.pop();
    return val;
}


