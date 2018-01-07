#include "servocontrol.hpp"
#ifndef IS_UNITTEST
    #include <Arduino.h>
#else
    #include "unittest/fakearduino.hpp"
#endif

void ServoControl::init() {
    this->current_spool_movement = STANDBY;
    this->servo_power_enabled = false;
}

/*
 * TODO: implement update such that it checks
 * how long ago we set the angle servo moving, and
 * cuts the power to it once we have waited a certain
 * amount of time. Also implement millis() in fakearduino
 * so we can test it.
 */

