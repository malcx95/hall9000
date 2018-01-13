#include "servocontrol.hpp"
#ifndef IS_UNITTEST
    #include <Arduino.h>
#else
    #include "unittest/fakearduino.hpp"
#endif

/*
 * TODO: implement update such that it checks
 * how long ago we set the angle servo moving, and
 * cuts the power to it once we have waited a certain
 * amount of time. Also implement millis() in fakearduino
 * so we can test it.
 */

void ServoControl::init() {
    this->current_spool_movement = STANDBY;
    this->servo_power_enabled = false;
}


bool ServoControl::servos_running() const {
    // TODO implement
    return false;
}

bool ServoControl::start_spool_servo(const bool clockwise) {
    // TODO implement
    return false;
}

void ServoControl::stop_spool_servo() {
    // TODO implement
}

bool ServoControl::set_shade_angle(const float value) {
    // TODO implement
    return false;
}

void ServoControl::update() {
    // TODO implement
}

void ServoControl::set_power_enabled(const bool val) {
    // TODO implement
}

