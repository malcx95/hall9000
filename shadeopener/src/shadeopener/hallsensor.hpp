#ifndef HALLSENSOR_H
#define HALLSENSOR_H

const int HALL_SENSOR_PIN = 13;

/*
 * A simple class for accessing the hall sensor.
 * The reason for making this a class is so that
 * a "fake" hall sensor can be created for the unit
 * tests.
 */
class HallSensor {
    
    /*
     * Initializes the sensor.
     */
    void init();

    /*
     * Reads from the sensor. Returns true if
     * the magnet is detected, false otherwise.
     */
    bool measure() const;

};

#endif /* ifndef HALLSENSOR_H */
