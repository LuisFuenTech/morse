/*
file has definitions for the library: basically a listing of everything that's inside
*/

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

/*
There are rules to help people distinguish dots from dashes in Morse code.

    1. The length of a dot is 1 time unit.
    2. A dash is 3 time units.
    3. The space between symbols (dots and dashes) of the same letter is 1 time unit.
    4. The space between letters is 3 time units.
    5. The space between words is 7 time units
*/

#define DOT_TIMING 45
#define DASH_TIMING DOT_TIMING * 3
#define SPACE_TIMING DOT_TIMING * 7
#define DELAY DOT_TIMING
#define LETTER_TIMING DOT_TIMING * 3
class Morse
{
public:
    Morse();
    Morse(int pin);
    HardwareSerial *serial;
    void dot();
    void dash();
    void space();
    void begin(long baudRate);
    void begin(long baudRate, HardwareSerial *_serial);
    void print(String text);
    void parse(String text);

private:
    void processMorse(String text);
    int _pin;
    long _baudRate;
    String _text;
};

#endif