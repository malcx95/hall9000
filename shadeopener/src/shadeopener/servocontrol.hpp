#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

#ifdef IS_UNITTEST
    #include "unittest/fakeservo.hpp"
#else
    #include <Servo.h>
#endif

enum ServoStatus {
    STANDBY, SPOOL_CLOCKWISE, SPOOL_ANTICLOCKWISE, SHADE_ANGLE_MOVING
};

/*
 * Controller of both the continuous spool servo and
 * the servo for angling the shades.
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
         * otherwise it spins anti-clockwise.
         */
        bool start_spool_servo(const bool clockwise);

        /*
         * Stops the spool movement.
         */
        void stop_spool();

        /*
         * Sets the angle of the shade to the given value
         * between 0-1, 1 means fully open, 0 means fully closed.
         * Turns on the power for the servos and cuts it later when
         * the movement is estimated to be done.
         */
        bool set_shade_angle(const float value);

    private:

        ServoStatus current_spool_movement;

        /*
         * The continuous spool servo
         */
        Servo spool_servo;
        
        /*
         * The servo for angling the shades
         */
        Servo angle_servo;

};

#endif /* ifndef SERVOCONTROL_H */

