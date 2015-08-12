Cardinal
========
[![License](https://img.shields.io/github/license/DaAwesomeP/arduino-cardinal.svg?style=flat-square)](https://github.com/DaAwesomeP/arduino-cardinal/blob/master/LICENSE) [![GitHub release](https://img.shields.io/github/release/DaAwesomeP/arduino-cardinal.svg?style=flat-square)](https://github.com/DaAwesomeP/arduino-cardinal/releases/latest) [![Github Releases Downloads](https://img.shields.io/github/downloads/DaAwesomeP/arduino-cardinal/latest/total.svg?style=flat-square)](https://github.com/DaAwesomeP/arduino-cardinal/releases/latest) [![Gitter chat](https://badges.gitter.im/DaAwesomeP/arduino-cardinal.png?style=flat-square)](https://gitter.im/DaAwesomeP/arduino-cardinal)
---
Cardinal is an Arduino library that takes input in degrees and output a string or integer for the 4, 8, 16, or 32 compass headings (like North, South, East, and West). It also makes available environment variables for the minimum, maximum, and middle azimuth of all of the 32 directions. It works fantastically when paired with a magnetometer.

## Installation
Cardinal is currently compatible with both Arduino 1.0.x and 1.5.x.

### Via Arduino IDE Library Manager
Cardinal is in the library manager. From the latest version of the Arduino IDE, go to `Sketch > Tools > Include Library > Manage Libraries` and search and install the latest release version of Cardinal.

### Via the ZIP archive
Download the latest release ZIP from [here](https://github.com/DaAwesomeP/arduino-cardinal/releases/latest) or the latest testing version from [here](https://github.com/DaAwesomeP/arduino-cardinal/archive/master.zip). Then go to `Sketch > Tools > Include Library > Add ZIP Library`.

## Usage
The first thing to do is to include the library in your sketch. Goes to `Sketch > Include Library > Cardinal`. The example has everything put to use in it, so I would advice looking there too. You should also take a look at the types at the wiki page [here](https://github.com/DaAwesomeP/arduino-cardinal/wiki/Types).

### Cardinal *name*
This initializes the class and bind it to a name of your choosing. Just use `cardinal` and make it simple. You will call the other functions with like `name.otherFunction`. So, if you choose cardinal, then it would be `cardinal.otherFunction`.

**Example:**
```cpp
Cardinal cardinal;
```

### ::getInteger(int *type*, float *inputFloat*)
This will take the type that you select and an input float in degrees and about a heading by numbers 1 through 32.

**Example:**
```cpp
cardinal.getInteger(3, 190.15);
// returns 18
```

### ::getString(int *type*, float *inputFloat*)
This will take the type that you select and an input float in degrees and about a heading in text format.

**Example:**
```cpp
cardinal.getString(3, 190.15);
// returns SbW
```

## Environment Variables
Environment Variables for the integer id, middle azimuth, minimum degrees, and maximum degrees for all 32 headings are available [here](https://github.com/DaAwesomeP/arduino-cardinal/wiki/Environment-Variables).

## More Information

I found the rainbow compass image and the table of headings on [this](https://en.wikipedia.org/wiki/Points_of_the_compass) Wikipedia page very helpful in understand these directions.
