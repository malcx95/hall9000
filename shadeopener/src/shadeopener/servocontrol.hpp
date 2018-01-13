#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

#ifdef IS_UNITTEST
    #include "unittest/fakeservo.hpp"
#else
    #include <Servo.h>
#endif

const int SPOOL_CLOCKWISE_MICROS = 2000;
const int SPOOL_STANDBY_MICROS = 1500;
const int SPOOL_ANTICLOCKWISE_MICROS = 1000;

enum ServoStatus {
    STANDBY, SPOOL_CLOCKWISE, SPOOL_ANTICLOCKWISE, SHADE_ANGLE_MOVING
};

/*
 * Controller of both the continuous spool servo and
 * the servo for angling the shades. This handles commanding
 * the servos to start or stop moving.
 */
class ServoControl {
   
    public:

        /*
         * Initializes the ServoControl
         */
        void init();

        /*
         * Returns whether one of the servos are running.
         */
        bool servos_running() const;

        /*
         * Starts running the spool servo in the given
         * direction. If clockwise is true, it spins clockwise,
         * otherwise it spins anti-clockwise. Turns on the
         * servo power. Doesn't start if the angle servo is
         * already running, in which case false is returned.
         * Otherwise true is returned.
         */
        bool start_spool_servo(const bool clockwise);

        /*
         * Stops the spool servo and cuts the power.
         */
        void stop_spool_servo();

        /*
         * Sets the angle of the shade to the given value
         * between 0-1, 1 means fully open, 0 means fully closed.
         * Turns on the power for the servos and cuts it later when
         * the movement is estimated to be done.
         */
        bool set_shade_angle(const float value);

        /*
         * Run this function once every Arduino loop iteration,
         * to make sure the power is cut to the servos when it's supposed to.
         */
        void update();

#ifndef IS_UNITTEST
    private:
#endif

        /*
         * Enables or disables the power to the servos.
         */
        void set_power_enabled(const bool val);

        ServoStatus current_spool_movement;

        /*
         * The continuous spool servo
         */
        Servo spool_servo;
        
        /*
         * The servo for angling the shades
         */
        Servo angle_servo;

        bool servo_power_enabled;

};

#endif /* ifndef SERVOCONTROL_H */

