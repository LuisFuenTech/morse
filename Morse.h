/*
file has definitions for the library: basically a listing of everything that's inside
*/

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse
{
public:
    Morse(int pin);
    void dot();
    void dash();

private:
    int _pin;
    const int DOT_LENGTH = 250;
    const int DASH_LENGTH = 1000;
    const int DELAY = 250;
};

#endif

/*
This code is necessary:
#ifndef {fileName}_h
#define {fileName}_h

#include "Arduino.h"

The code go here...

 #endif

*/