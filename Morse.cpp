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

Morse::Morse() {}

Morse::Morse(int pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
    _text = "";
}

void Morse::begin(long baudRate, HardwareSerial *_serial)
{
    serial = _serial;
    serial->begin(baudRate);
    print("Initializing Serial Port...");
}

void Morse::begin(long baudRate)
{
    serial = &Serial;
    serial->begin(baudRate);
    print("Initializing Serial Port...\n");
}

void Morse::print(String text)
{
    serial->print(text);
}

void Morse::dot()
{
    digitalWrite(_pin, HIGH);
    delay(DOT_TIMING);

    if (serial)
    {
        print(".");
    }

    digitalWrite(_pin, LOW);
    delay(DELAY);
}

void Morse::dash()
{
    digitalWrite(_pin, HIGH);
    delay(DASH_TIMING);

    if (serial)
    {
        print("-");
    }

    digitalWrite(_pin, LOW);
    delay(DELAY);
}

void Morse::space()
{
    digitalWrite(_pin, HIGH);
    delay(SPACE_TIMING);

    if (serial)
    {
        print("/");
    }

    digitalWrite(_pin, LOW);
    delay(DELAY);
}

void Morse::processMorse(String text)
{
    for (int i = 0; i < text.length(); i++)
    {
        char character = text.charAt(i);

        switch (character)
        {
        case '.':
            dot();
            break;
        case '-':
            dash();
            break;
        case '/':
        case '|':
            space();
            break;
        }
    }
    serial->print(" ");
}

void Morse::parse(String text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text.toLowerCase();
        char character = text.charAt(i);

        switch (character)
        {
        case 'a':
            processMorse(".-");
            break;
        case 'b':
            processMorse("-...");
            break;
        case 'c':
            processMorse("-.-.");
            break;
        case 'd':
            processMorse("-..");
            break;
        case 'e':
            processMorse(".");
            break;
        case 'f':
            processMorse("..-.");
            break;
        case 'g':
            processMorse("--.");
            break;
        case 'h':
            processMorse("....");
            break;
        case 'i':
            processMorse("..");
            break;
        case 'j':
            processMorse(".---");
            break;
        case 'k':
            processMorse("-.-");
            break;
        case 'l':
            processMorse(".-..");
            break;
        case 'm':
            processMorse("--");
            break;
        case 'n':
            processMorse("-.");
            break;
        case 'o':
            processMorse("---");
            break;
        case 'p':
            processMorse(".--.");
            break;
        case 'q':
            processMorse("--.-");
            break;
        case 'r':
            processMorse(".-.");
            break;
        case 's':
            processMorse("...");
            break;
        case 't':
            processMorse("-");
            break;
        case 'u':
            processMorse("..-");
            break;
        case 'v':
            processMorse("...-");
            break;
        case 'w':
            processMorse(".--");
            break;
        case 'x':
            processMorse("-..-");
            break;
        case 'y':
            processMorse("-.--");
            break;
        case 'z':
            processMorse("--..");
            break;
        case ' ':
            processMorse("/");
            break;
        case '0':
            processMorse("-----");
            break;
        case '1':
            processMorse(".----");
            break;
        case '2':
            processMorse("..---");
            break;
        case '3':
            processMorse("...--");
            break;
        case '4':
            processMorse("....-");
            break;
        case '5':
            processMorse(".....");
            break;
        case '6':
            processMorse("-....");
            break;
        case '7':
            processMorse("--...");
            break;
        case '8':
            processMorse("---..");
            break;
        case '9':
            processMorse("----.");
            break;
        case '.':
            processMorse(".-.-.-");
            break;
        case '?':
            processMorse("..--..");
            break;
        case ',':
            processMorse("--..--");
            break;
        case '=':
            processMorse("-...-");
            break;
        default:
            break;
        }

        delay(LETTER_TIMING);
    }

    serial->print("\n");
}
