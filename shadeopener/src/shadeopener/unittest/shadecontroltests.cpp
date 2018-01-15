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
        control.enqueue_measurement(i % 2 == 0);
    }

    // TODO finish

}

