# Morse Library

This is an arduino library, created as a example to learn how to create and use custom libraries.

# Installation

1. Download this repository add `.zip` file
2. Open arduino IDE
3. Go to `Sketch > Include Library > Add .ZIP Library...`
4. Lookup and choose the `morse.zip` file downloaded

# Usage

```c++
#include <Morse.h>

Morse morse(13);

void setup()
{
}

void loop()
{
  morse.dot();
  morse.dash();
  morse.dash();
  morse.dot();

  delay(3000);
}

```

# Examples

1. Open arduino IDE
2. Go to `Files > Examples > Morse`
