Cardinal
========
[![license](https://img.shields.io/github/license/DaAwesomeP/arduino-cardinal.svg?style=flat-square)](https://github.com/DaAwesomeP/arduino-cardinal/blob/master/LICENSE) [![Github Releases](https://img.shields.io/github/downloads/DaAwesomeP/arduino-cardinal/latest/total.svg?style=flat-square)](https://github.com/DaAwesomeP/arduino-cardinal/releases/latest) [![Gitter chat](https://badges.gitter.im/DaAwesomeP/arduino-cardinal.png?style=flat-square)](https://gitter.im/DaAwesomeP/arduino-cardinal)
---
Cardinal is an Arduino library that takes input in degrees and output a string or integer for the 4, 8, 16, or 32 compass headings (like North, South, East, and West). It also makes available variables for the minimum, maximum, and middle azimuth of all of the 32 directions. It works fantastically when paired with a magnetometer.

## Installation

### Via Arduino IDE Library Manager
Cardinal will (hopefully) soon be in the package manager, so be patient.

### Via the ZIP archive
Download the latest release ZIP from [here](https://github.com/DaAwesomeP/arduino-cardinal/releases/latest). If you don't know how to install an Arduino library from the ZIP, then just Google it.

## Usage
The first thing to do is to include the library in your sketch. Goes to SKetch > Include Library > Cardinal. The example has everything put to use in it, so I would advice looking there too. You should also take a look at the types at the wiki page [here]().

### Cardinal *name*
This initializes the class and bind it to a name of your choosing. Just use `cardinal` and make it simple. You will call the other functions with like `name.otherFunction`. So, if you choose cardinal, then it would be `cardinal.otherFunction`.

**Example:**
```cpp
Cardinal cardinal;
```

### ::integer(int *type*, float *inputFloat*)
This will take the types that you select and an input float in degrees and about a heading by numbers 1 through 32.

**Example:**
```cpp
cardinal.integer(3, 190.15);
// returns 18
```

### ::integer(int *type*, float *inputFloat*)
This will take the types that you select and an input float in degrees and about a heading in text format.

**Example:**
```cpp
cardinal.integer(3, 190.15);
// returns SbW
```

## More Information

I found the rainbow compass image and the table of headings on [this](https://en.wikipedia.org/wiki/Points_of_the_compass) Wikipedia page very helpful in understand these directions.
