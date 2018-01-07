#include "fakearduino.hpp"
#include <iostream>

/*
 * We can't simulate this so we do nothing.
 */
void digitalWrite(int val) {}

unsigned long millis() {
    // TODO implement
    return 0;
}

