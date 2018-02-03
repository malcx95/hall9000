#ifndef SHADECONTROL_H
#define SHADECONTROL_H

#include "servocontrol.hpp"

#ifdef IS_UNITTEST
    #include "unittest/fakehallsensor.hpp"
#else
    #include "hallsensor.hpp"
#endif

enum ShadeStatus {
    STANDBY, TIMEOUT, SHADES_INCREMENTING, SHADES_DECREMENTING,
    SHADES_ROLLING_UP, SHADES_ROLLING_DOWN, SHADE_ANGLE_CHANGING
};

#ifdef IS_UNITTEST
// so we don't have to wait for an eternity
const int SHADE_TIMEOUT_MILLIS = 100;
#else
const int SHADE_TIMEOUT_MILLIS = 3000;
#endif

/*
 * High-level controller for the shades.
 */
class ShadeControl {

    public:

        /*
         * Initializes the shadecontrol.
         */
        void init();

        /*
         * Starts setting the angle of the shade to the given value
         * between 0-1, 1 means fully open, 0 means fully closed.
         * Returns false if the servos are busy at the moment.
         */
        bool set_shade_angle(const float value);

        /*
         * Starts rolling up or down the shades such that they are
         * a given amount of revolutions from the bottom position.
         * That is, if revolutions is 0, assuming everything is calibrated
         * properly, it should roll the shades all the way down.
         * Returns false if the spool servo or angle servo is already moving,
         * returns true if it started moving.
         */
        bool set_shades_position(const int revolutions);

        /*
         * Starts rolling the shades up or down. Stops when one revolution
         * is completed.
         */
        bool increment_shades_position(const bool up);

        /*
         * Sets which ever position it is in as the bottom position.
         */
        void set_curr_pos_as_bottom();

        /*
         * Sets the given number of revolutions as the top position,
         * that is when the shades are completely rolled up.
         */
        void set_top_position(const int revolutions);

        /*
         * Returns the current number of revolutions from bottom.
         */
        int get_current_position() const;

        /*
         * Sets the current revolutions value for the spool.
         * Useful for when power is cut and it needs to know
         * in which position it's in.
         */
        void set_current_position(const int revolutions);

        /*
         * Returns which number of revolutions that is currently set as the
         * top value.
         */
        int get_top_position() const;

        /*
         * Run this every Arduino update to make sure control is maintained
         * over the servos.
         */
        void update();

        /*
         * Returns whether the spool servo is timed out, that is, 
         * we can't verify that the servo is moving.
         */
        bool is_timed_out() const;

        /*
         * Resets the timeout flag.
         */
        void reset_timeout_flag();

#ifndef IS_UNITTEST
    private:
#endif

        float current_shade_angle;

        int current_revolutions;

        HallSensor hall_sensor;

        ServoControl servo_control;

        ShadeStatus current_status;
};

#endif /* ifndef SHADECONTROL_H */
