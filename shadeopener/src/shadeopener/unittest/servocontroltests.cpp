/*
 * This file contains unit tests for the servo control module.
 */

#include "catch.hpp"
#include "../servocontrol.hpp"


TEST_CASE("ServoControl initializes with disabled power", "[servocontrol]") {

    ServoControl control;
    control.init();

    REQUIRE_FALSE(control.servo_power_enabled);
    REQUIRE(control.current_spool_movement == STANDBY);

}

