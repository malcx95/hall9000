#ifndef FAKESERVO_H
#define FAKESERVO_H
#include <vector>

class Servo {

    public:

        Servo();

        void writeMicroseconds(const int micros);

        int current_micros;
    
        std::vector<int> micro_values;

};

#endif
