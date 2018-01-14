#ifndef FAKEHALLSENSOR_H
#define FAKEHALLSENSOR_H

#include <queue>

const int HALL_SENSOR_PIN = 13;

/*
 * Simulator for the hall sensor.
 */
class HallSensor {
   
    public:

        void init();

        /*
         * Pops and returns a value from the measurements
         * queue. If the queue is empty, false is returned.
         */
        bool measure();

        /*
         * Adds a measurement value to the queue
         * of values to be returned by measure().
         */
        void enqueue_measurement(const bool val);

    private:
        
        std::queue<bool> measurements;

};

#endif /* ifndef FAKEHALLSENSOR_H */
