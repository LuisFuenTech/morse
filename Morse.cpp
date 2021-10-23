/*
This file has the actual code
*/

#include "Arduino.h"
#include "Morse.h"

/*
Morse::
This says that the function is part of the Morse class

Constructor
*/
Morse::Morse(int pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

// Delaclare dot function
void Morse::dot()
{
    digitalWrite(_pin, HIGH);
    delay(DOT_LENGTH);
    digitalWrite(_pin, LOW);
    delay(DELAY);
}

//Declare dash function
void Morse::dash()
{
    digitalWrite(_pin, HIGH);
    delay(DASH_LENGTH);
    digitalWrite(_pin, LOW);
    delay(DELAY);
}
