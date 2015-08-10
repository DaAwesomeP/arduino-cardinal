/******************************************************************************
  CardinalSerialInputDegrees.ino
  Cardinal Library example file
  Originally Created: August 10, 2015

  Written by DaAwesomeP (https://daawesomep.github.io/)
  Project homepage at https://github.com/DaAwesomeP/arduino-cardinal
  
  This sketch takes a number input in degrees from serial at 9600 baud
  and outputs the heading in number and text form.

    Copyright 2015 DaAwesomeP
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

 ******************************************************************************/

#include <Cardinal.h>    // Include the library

int type = 3; // Type of precision
/*
Precision types:
 - 0: N, S, E, W
 - 1: N, NE, E, SE, S, SW, W, NW
 - 2: N, NNE, NE, ENE, E, ESE, SE, SSE, S, SSW, SW, WSW, W, WNW, NW, NNW
 - 3: all 32 headings (N, NbE, NNE, NEbN, NE, NEbE, etc.)
*/

String inputString = "";
float inputFloat;
boolean stringComplete = false;

String stringOut;
int intOut;

Cardinal cardinal;   // init the library to "cardnial"

void setup() {
  Serial.begin(9600);
  Serial.println("Type a number from 0 to 360 (including decimals) and see the output!");
  Serial.println("--------------------------------------------------------------------");
}

void loop() {
  if (stringComplete) {
    inputFloat = inputString.toFloat();                // Convert the inputted number to a float
    intOut = cardinal.integer(type, inputFloat);       // Use that float to get the heading number
    stringOut = cardinal.string(type, inputFloat);     // Use that float to get the heading in text format
    Serial.print("in: ");
    Serial.print(inputString);
    Serial.print("int: ");
    Serial.print(intOut);
    Serial.print(" str: ");
    Serial.println(stringOut);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEventRun(void) {
  if (Serial.available()) serialEvent();
}
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
