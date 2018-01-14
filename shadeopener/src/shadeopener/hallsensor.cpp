#include "hallsensor.hpp"
#include <Arduino.h>

void HallSensor::init() {
    pinMode(HALL_SENSOR_PIN, INPUT);
}

bool HallSensor::measure() const {
    return (bool)digitalRead(HALL_SENSOR_PIN);
}

