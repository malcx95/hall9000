/*
 * This file contains unit tests for the servo control module.
 */

#include "catch.hpp"
#include "../servocontrol.hpp"
#include "fakearduino.hpp"
#include <unistd.h>


TEST_CASE("ServoControl initializes with disabled power", "[servocontrol]") {

    ServoControl control;
    control.init();

    SECTION("Servo power is disabled") {
        CHECK_FALSE(control.servo_power_enabled);
    }

    SECTION("Servos aren't moving") {
        CHECK(control.current_spool_movement == STANDBY);
        CHECK_FALSE(control.servos_running());
        CHECK(control.spool_servo.current_micros == SPOOL_STANDBY_MICROS);
    }

}

TEST_CASE("start_spool_servo runs normally", "[servocontrol]") {
    
    ServoControl control;
    control.init();
    
    SECTION("Servos aren't moving and power is disabled") {
        CHECK_FALSE(control.servo_power_enabled);
        CHECK(control.current_spool_movement == STANDBY);
        CHECK_FALSE(control.servos_running());
    }

    SECTION("Servo can start to move clockwise") {
        bool started = control.start_spool_servo(true);
        CHECK(started);
        CHECK(control.servos_running());
        CHECK(control.current_spool_movement == SPOOL_CLOCKWISE);
        CHECK(control.servo_power_enabled);
        CHECK(control.spool_servo.current_micros == SPOOL_CLOCKWISE_MICROS);
    }

    SECTION("Servo can be stopped") {
        control.stop_spool_servo();

        CHECK_FALSE(control.servo_power_enabled);
        CHECK(control.current_spool_movement == STANDBY);
        CHECK_FALSE(control.servos_running());
        CHECK(control.spool_servo.current_micros == SPOOL_STANDBY_MICROS);
    }

    SECTION("Servo can start to move anti-clockwise") {
        bool started = control.start_spool_servo(false);
        CHECK(started);
        CHECK(control.servos_running());
        CHECK(control.current_spool_movement == SPOOL_ANTICLOCKWISE);
        CHECK(control.servo_power_enabled);
        CHECK(control.spool_servo.current_micros == SPOOL_ANTICLOCKWISE_MICROS);
    }

}

