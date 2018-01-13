#include "fakearduino.hpp"
#include <iostream>
#include <chrono>

/*
 * We can't simulate this so we do nothing.
 */
void digitalWrite(int val) {}

unsigned long millis() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
}

