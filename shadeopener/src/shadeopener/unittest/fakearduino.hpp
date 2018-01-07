#ifndef FAKEARDUINO_H
#define FAKEARDUINO_H 

/*
 * File for simulating the various arduino functions.
 */

const int HIGH = 1;
const int LOW = 0;

void digitalWrite(int val);

unsigned long millis();

#endif /* ifndef FAKEARDUINO_H */
