#include "fakeservo.hpp"

Servo::Servo() {
    current_micros = 1500;
}

void Servo::writeMicroseconds(const int micros) {
    this->current_micros = micros;
    this->micro_values.push_back(micros);
}

