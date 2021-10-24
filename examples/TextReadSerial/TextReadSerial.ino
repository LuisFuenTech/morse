/*
  Created by Luis Fuentes, Octuber 24, 2021.
*/
#include <Morse.h>

Morse morse(13);

void setup()
{
    morse.begin(9600);
}

void loop()
{
    while (morse.serial->available())
    {
        morse.parse(morse.serial->readString());
    }

    delay(50);
}
