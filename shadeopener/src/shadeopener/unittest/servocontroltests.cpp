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
        CHECK(control.current_servo_movement == SERVO_STANDBY);
        CHECK_FALSE(control.servos_running());
        CHECK(control.spool_servo.current_micros == SPOOL_STANDBY_MICROS);
    }

}

TEST_CASE("start_spool_servo runs normally", "[servocontrol]") {
    
    ServoControl control;
    control.init();
    
    SECTION("Servos aren't moving and power is disabled") {
        CHECK_FALSE(control.servo_power_enabled);
        CHECK(control.current_servo_movement == SERVO_STANDBY);
        CHECK_FALSE(control.servos_running());
    }

    SECTION("Servo can start to move clockwise") {
        bool started = control.start_spool_servo(true);
        CHECK(started);
        CHECK(control.servos_running());
        CHECK(control.current_servo_movement == SPOOL_CLOCKWISE);
        CHECK(control.servo_power_enabled);
        CHECK(control.spool_servo.current_micros == SPOOL_CLOCKWISE_MICROS);
    }

    SECTION("Servo can be stopped") {
        control.stop_spool_servo();

        CHECK_FALSE(control.servo_power_enabled);
        CHECK(control.current_servo_movement == SERVO_STANDBY);
        CHECK_FALSE(control.servos_running());
        CHECK(control.spool_servo.current_micros == SPOOL_STANDBY_MICROS);
    }

    SECTION("Servo can start to move anti-clockwise") {
        bool started = control.start_spool_servo(false);
        CHECK(started);
        CHECK(control.servos_running());
        CHECK(control.current_servo_movement == SPOOL_ANTICLOCKWISE);
        CHECK(control.servo_power_enabled);
        CHECK(control.spool_servo.current_micros == SPOOL_ANTICLOCKWISE_MICROS);
    }

}

TEST_CASE("set_shade_angle runs normally", "[servocontrol]") {
    ServoControl control;
    control.init();
    
    SECTION("Servos aren't moving and power is disabled") {
        CHECK_FALSE(control.servo_power_enabled);
        CHECK(control.current_servo_movement == SERVO_STANDBY);
        CHECK_FALSE(control.servos_running());
    }

    SECTION("Angle servo can be opened") {
        bool started = control.set_shade_angle(SHADE_ANGLE_OPEN);
        CHECK(started);
        CHECK(control.current_servo_movement == SHADE_ANGLE_MOVING);
        CHECK(control.servos_running());
        CHECK(control.servo_power_enabled);
        CHECK(control.angle_servo.current_micros == OPEN_SHADE_MICROS);
    }

    SECTION("Power is cut when the servo has stopped moving") {
        usleep(ANGLE_SERVO_DELAY_MILLIS * 1000 + 1000);
        control.update();
        CHECK_FALSE(control.servo_power_enabled);
        CHECK(control.current_servo_movement == SERVO_STANDBY);
        CHECK_FALSE(control.servos_running());
    }

    SECTION("Angle servo can be closed") {
        bool started = control.set_shade_angle(SHADE_ANGLE_CLOSED);
        CHECK(started);
        CHECK(control.current_servo_movement == SHADE_ANGLE_MOVING);
        CHECK(control.servos_running());
        CHECK(control.servo_power_enabled);
        CHECK(control.angle_servo.current_micros == CLOSED_SHADE_MICROS);
    }

}

TEST_CASE("Two servos cannot be run at once", "[servocontrol]") {
    ServoControl control;
    control.init();
    
    SECTION("Starting angle servo while spool is running shouldn't work") {
        bool started = control.start_spool_servo(true);
        CHECK(started);
        CHECK(control.servos_running());
        CHECK(control.current_servo_movement == SPOOL_CLOCKWISE);
        
        bool angle_started = control.set_shade_angle(SHADE_ANGLE_OPEN);
        CHECK_FALSE(angle_started);
        CHECK(control.current_servo_movement == SPOOL_CLOCKWISE);
    }

    ServoControl control2;
    control2.init();

    SECTION("Starting spool servo while angle servo is running shouldn't work") {
        bool angle_started = control.set_shade_angle(SHADE_ANGLE_OPEN);
        CHECK(angle_started);
        CHECK(control.current_servo_movement == SHADE_ANGLE_MOVING);

        bool spool_started = control.start_spool_servo(true);
        CHECK_FALSE(spool_started);
        CHECK(control.current_servo_movement == SHADE_ANGLE_MOVING);
        
    }
}

