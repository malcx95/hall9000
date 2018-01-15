#include "servocontrol.hpp"
#ifndef IS_UNITTEST
    #include <Arduino.h>
#else
    #include "unittest/fakearduino.hpp"
#endif

void ServoControl::init() {
    this->current_servo_movement = SERVO_STANDBY;
    this->servo_power_enabled = false;
}


bool ServoControl::servos_running() const {
    return current_servo_movement != SERVO_STANDBY;
}

bool ServoControl::start_spool_servo(const bool clockwise) {

    // other servos are currently moving, so don't allow this
    if (this->current_servo_movement != SERVO_STANDBY) return false;

    this->set_power_enabled(true);

    if (clockwise) {
        this->current_servo_movement = SPOOL_CLOCKWISE;
        this->spool_servo.writeMicroseconds(SPOOL_CLOCKWISE_MICROS);
    } else {
        this->current_servo_movement = SPOOL_ANTICLOCKWISE;
        this->spool_servo.writeMicroseconds(SPOOL_ANTICLOCKWISE_MICROS);
    }

    return true;
}

bool ServoControl::stop_spool_servo() {
    if (this->current_servo_movement == SPOOL_CLOCKWISE ||
        this->current_servo_movement == SPOOL_ANTICLOCKWISE) {
        
        this->spool_servo.writeMicroseconds(SPOOL_STANDBY_MICROS);
        this->set_power_enabled(false);
        this->current_servo_movement = SERVO_STANDBY;
        return true;
    }
    return false;
}

bool ServoControl::set_shade_angle(const float value) {
    // other servos are currently moving, so don't allow this
    if (this->current_servo_movement != SERVO_STANDBY) return false;
    
    int micros = CLOSED_SHADE_MICROS - (int)(((float)SHADE_MICROS_RANGE)*value);
    this->set_power_enabled(true);
    this->angle_servo.writeMicroseconds(micros);
    this->angle_movement_start_time = millis();
    this->current_servo_movement = SHADE_ANGLE_MOVING;

    return true;
}

void ServoControl::update() {
    if (this->current_servo_movement == SHADE_ANGLE_MOVING) {
        unsigned current_time = millis();
        if (this->angle_movement_start_time > current_time) {
            // overflow has occurred, restart the timer
            this->angle_movement_start_time = current_time;
            return;
        }

        if (this->angle_movement_start_time - current_time 
                >= ANGLE_SERVO_DELAY_MILLIS) {
            this->set_power_enabled(false);
        }
    }
}

void ServoControl::set_power_enabled(const bool val) {
    // TODO actually set the power enabled
    this->servo_power_enabled = val;
}

