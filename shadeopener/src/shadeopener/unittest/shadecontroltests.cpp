/*
 * This file contains unit tests for the shade control module.
 */

#include "catch.hpp"
#include "../shadecontrol.hpp"
#include "fakearduino.hpp"

TEST_CASE("ShadeControl initializes") {
    ShadeControl control;
    control.init();

    CHECK(control.current_revolutions == 0);
    CHECK(control.current_shade_angle == 0.0);
}

TEST_CASE("ShadeControl can set shade angle") {
    ShadeControl control;
    control.init();

    bool set = control.set_shade_angle(1.0);
    CHECK(set);
    CHECK(control.current_shade_angle == 1.0);
}

TEST_CASE("ShadeControl can go to top spool position") {

    ShadeControl control;
    control.init();

    control.set_top_position(10);
    control.set_current_position(0);


    // every other measurement returns true
    for (int i = 0; i < 30; ++i) {
        control.hall_sensor.enqueue_measurement(i % 2 == 0);
    }

    // start rolling the shades up
    control.set_shades_position(10);

    REQUIRE(control.current_status == SHADES_ROLLING_UP);
    int expected_revolutions = 0;

    // revolutions should every other time update() is called
    for (int i = 0; i < 20; ++i) {
        CHECK(control.current_revolutions == expected_revolutions);
        expected_revolutions += i % 2 == 0;
        control.update();
    }

    CHECK(control.current_status == STANDBY);
}

TEST_CASE("ShadeControl times out when rolling up") {

    ShadeControl control;
    control.init();

    control.set_top_position(10);
    control.set_current_position(0);

    control.set_shades_position(10);

    unsigned long time = millis();

    REQUIRE(control.current_status == SHADES_ROLLING_UP);

    while (millis() - time < SHADE_TIMEOUT_MILLIS) {
        control.update();
    }
    
    CHECK(control.current_status == TIMEOUT);
}

