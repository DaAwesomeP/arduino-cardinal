/******************************************************************************
  Cardinal.cpp
  Cardinal Library program file
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

#include <Arduino.h>
#include "Cardinal.h"

int _intOut;
String _stringOut;

void Cardinal::_lookup(int type, float degree)
{
  if (degree > 360 || degree < 0){     // Degrees are from 0 to 360 and must be a number
      _intOut = 0;
      _stringOut = "ERR";
  }
  else if (type == 0) {  // N, E, S, W
    if (degree > CARDINAL_NW_MIDAZ || degree < CARDINAL_NE_MIDAZ)
    {
      _intOut = 1;
      _stringOut = "N";
    }
	else if (degree > CARDINAL_NE_MIDAZ && degree < CARDINAL_SE_MIDAZ)
    {
      _intOut = 9;
      _stringOut = "E";
    }
	else if (degree > CARDINAL_SE_MIDAZ && degree < CARDINAL_SW_MIDAZ)
    {
      _intOut = 17;
      _stringOut = "S";
    }
	else if (degree > CARDINAL_SW_MIDAZ && degree < CARDINAL_NW_MIDAZ)
    {
      _intOut = 25;
      _stringOut = "W";
    }
	else  // Did not match any heading. Input is negative or exactly at another degree. Try rounding to the tenths place or a whole number
    {
      _intOut = 0;
	  _stringOut = "ERR";
    }
  }
  else if (type == 1) {   // N, NE, E, SE, S, SW, W, NW
    if (degree > CARDINAL_NNW_MIDAZ || degree < CARDINAL_NNE_MIDAZ)
    {
      _intOut = 1;
      _stringOut = "N";
    }
	else if (degree > CARDINAL_NNE_MIDAZ && degree < CARDINAL_ENE_MIDAZ)
    {
      _intOut = 5;
      _stringOut = "NE";
    }
	else if (degree > CARDINAL_ENE_MIDAZ && degree < CARDINAL_ESE_MIDAZ)
    {
      _intOut = 9;
      _stringOut = "E";
    }
	else if (degree > CARDINAL_ESE_MIDAZ && degree < CARDINAL_SSE_MIDAZ)
    {
      _intOut = 13;
      _stringOut = "SE";
    }
	else if (degree > CARDINAL_SSE_MIDAZ && degree < CARDINAL_SSW_MIDAZ)
    {
      _intOut = 17;
      _stringOut = "S";
    }
	else if (degree > CARDINAL_SSW_MIDAZ && degree < CARDINAL_WSW_MIDAZ)
    {
      _intOut = 21;
      _stringOut = "SW";
    }
	else if (degree > CARDINAL_WSW_MIDAZ && degree < CARDINAL_WNW_MIDAZ)
    {
      _intOut = 25;
      _stringOut = "W";
    }
	else if (degree > CARDINAL_WNW_MIDAZ && degree < CARDINAL_NNW_MIDAZ)
    {
      _intOut = 29;
      _stringOut = "NW";
    }
	else  // Did not match any heading. Input is exactly at another degree. Try rounding to the tenths place or a whole number
    {
      _intOut = 0;
	  _stringOut = "ERR";
    }
  }
  else if (type == 2) {   // N, NNE, NE, ENE, E, ESE, SE, SSE, S, SSW, SW, WSW, W, WNW, NW, NNW
    if (degree > CARDINAL_NbW_MIDAZ || degree < CARDINAL_NbE_MIDAZ)
    {
      _intOut = 1;
      _stringOut = "N";
    }
	else if (degree > CARDINAL_NbE_MIDAZ && degree < CARDINAL_NEbN_MIDAZ)
    {
      _intOut = 3;
      _stringOut = "NNE";
    }
	else if (degree > CARDINAL_NEbN_MIDAZ && degree < CARDINAL_NEbE_MIDAZ)
    {
      _intOut = 5;
      _stringOut = "NE";
    }
	else if (degree > CARDINAL_NEbE_MIDAZ && degree < CARDINAL_EbN_MIDAZ)
    {
      _intOut = 7;
      _stringOut = "ENE";
    }
	else if (degree > CARDINAL_EbN_MIDAZ && degree < CARDINAL_EbS_MIDAZ)
    {
      _intOut = 9;
      _stringOut = "E";
    }
	else if (degree > CARDINAL_EbS_MIDAZ && degree < CARDINAL_SEbE_MIDAZ)
    {
      _intOut = 11;
      _stringOut = "ESE";
    }
	else if (degree > CARDINAL_SEbE_MIDAZ && degree < CARDINAL_SEbS_MIDAZ)
    {
      _intOut = 13;
      _stringOut = "SE";
    }
	else if (degree > CARDINAL_SEbS_MIDAZ && degree < CARDINAL_SbE_MIDAZ)
    {
      _intOut = 15;
      _stringOut = "SSE";
    }
	else if (degree > CARDINAL_SbE_MIDAZ && degree < CARDINAL_SbW_MIDAZ)
    {
      _intOut = 17;
      _stringOut = "S";
    }
	else if (degree > CARDINAL_SbW_MIDAZ && degree < CARDINAL_SWbS_MIDAZ)
    {
      _intOut = 19;
      _stringOut = "SSW";
    }
	else if (degree > CARDINAL_SWbS_MIDAZ && degree < CARDINAL_SWbW_MIDAZ)
    {
      _intOut = 21;
      _stringOut = "SW";
    }
	else if (degree > CARDINAL_SWbW_MIDAZ && degree < CARDINAL_WbS_MIDAZ)
    {
      _intOut = 23;
      _stringOut = "WSW";
    }
	else if (degree > CARDINAL_WbS_MIDAZ && degree < CARDINAL_WbN_MIDAZ)
    {
      _intOut = 25;
      _stringOut = "W";
    }
	else if (degree > CARDINAL_WbN_MIDAZ && degree < CARDINAL_NWbW_MIDAZ)
    {
      _intOut = 27;
      _stringOut = "WNW";
    }
	else if (degree > CARDINAL_NWbW_MIDAZ && degree < CARDINAL_NWbN_MIDAZ)
    {
      _intOut = 29;
      _stringOut = "NW";
    }
	else if (degree > CARDINAL_NWbN_MIDAZ && degree < CARDINAL_NbW_MIDAZ)
    {
      _intOut = 31;
      _stringOut = "NNW";
    }
	else  // Did not match any heading. Input is exactly at another degree. Try rounding to the tenths place or a whole number
    {
      _intOut = 0;
	  _stringOut = "ERR";
    }
  }
  else if (type == 3) {   //  All 32 headings: N, NbE, NNE, NEbN, NE, NEbE, etc.
    if (degree > CARDINAL_N_MIN || degree < CARDINAL_N_MAX)
    {
      _intOut = 1;
      _stringOut = "N";
    }
    else if (degree > CARDINAL_NbE_MIN && degree < CARDINAL_NbE_MAX)
    {
      _intOut = 2;
      _stringOut = "NbE";
    }
    else if (degree > CARDINAL_NNE_MIN && degree < CARDINAL_NNE_MAX)
    {
      _intOut = 3;
      _stringOut = "NNE";
    }
    else if (degree > CARDINAL_NEbN_MIN && degree < CARDINAL_NEbN_MAX)
    {
      _intOut = 4;
      _stringOut = "NEbN";
    }
    else if (degree > CARDINAL_NE_MIN && degree < CARDINAL_NE_MAX)
    {
      _intOut = 5;
      _stringOut = "NE";
    }
        else if (degree > CARDINAL_NEbE_MIN && degree < CARDINAL_NEbE_MAX)
    {
      _intOut = 6;
      _stringOut = "NEbE";
    }
    else if (degree > CARDINAL_ENE_MIN && degree < CARDINAL_ENE_MAX)
    {
      _intOut = 7;
      _stringOut = "ENE";
    }
    else if (degree > CARDINAL_EbN_MIN && degree < CARDINAL_EbN_MAX)
    {
      _intOut = 8;
      _stringOut = "EbN";
    }
    else if (degree > CARDINAL_E_MIN && degree < CARDINAL_E_MAX)
    {
      _intOut = 9;
      _stringOut = "E";
    }
    else if (degree > CARDINAL_EbS_MIN && degree < CARDINAL_EbS_MAX)
    {
      _intOut = 10;
      _stringOut = "EbS";
    }
    else if (degree > CARDINAL_ESE_MIN && degree < CARDINAL_ESE_MAX)
    {
      _intOut = 11;
      _stringOut = "ESE";
    }
    else if (degree > CARDINAL_SEbE_MIN && degree < CARDINAL_SEbE_MAX)
    {
      _intOut = 12;
      _stringOut = "SEbE";
    }
    else if (degree > CARDINAL_SE_MIN && degree < CARDINAL_SE_MAX)
    {
      _intOut = 13;
      _stringOut = "SE";
    }
    else if (degree > CARDINAL_SEbS_MIN && degree < CARDINAL_SEbS_MAX)
    {
      _intOut = 14;
      _stringOut = "SEbS";
    }
    else if (degree > CARDINAL_SSE_MIN && degree < CARDINAL_SSE_MAX)
    {
      _intOut = 15;
      _stringOut = "SSE";
    }
    else if (degree > CARDINAL_SbE_MIN && degree < CARDINAL_SbE_MAX)
    {
      _intOut = 16;
      _stringOut = "SbE";
    }
    else if (degree > CARDINAL_S_MIN && degree < CARDINAL_S_MAX)
    {
      _intOut = 17;
      _stringOut = "S";
    }
    else if (degree > CARDINAL_SbW_MIN && degree < CARDINAL_SbW_MAX)
    {
      _intOut = 18;
      _stringOut = "SbW";
    }
    else if (degree > CARDINAL_SSW_MIN && degree < CARDINAL_SSW_MAX)
    {
      _intOut = 19;
      _stringOut = "SSW";
    }
    else if (degree > CARDINAL_SWbS_MIN && degree < CARDINAL_SWbS_MAX)
    {
      _intOut = 20;
      _stringOut = "SWbS";
    }
    else if (degree > CARDINAL_SW_MIN && degree < CARDINAL_SW_MAX)
    {
      _intOut = 21;
      _stringOut = "SW";
    }
    else if (degree > CARDINAL_SWbW_MIN && degree < CARDINAL_SWbW_MAX)
    {
      _intOut = 22;
      _stringOut = "SWbW";
    }
    else if (degree > CARDINAL_WSW_MIN && degree < CARDINAL_WSW_MAX)
    {
      _intOut = 23;
      _stringOut = "WSW";
    }
    else if (degree > CARDINAL_WbS_MIN && degree < CARDINAL_WbS_MAX)
    {
      _intOut = 24;
      _stringOut = "WbS";
    }
    else if (degree > CARDINAL_W_MIN && degree < CARDINAL_W_MAX)
    {
      _intOut = 25;
      _stringOut = "W";
    }
    else if (degree > CARDINAL_WbN_MIN && degree < CARDINAL_WbN_MAX)
    {
      _intOut = 26;
      _stringOut = "WbN";
    }
    else if (degree > CARDINAL_WNW_MIN && degree < CARDINAL_WNW_MAX)
    {
      _intOut = 27;
      _stringOut = "WNW";
    }
    else if (degree > CARDINAL_NWbW_MIN && degree < CARDINAL_NWbW_MAX)
    {
      _intOut = 28;
      _stringOut = "NWbW";
    }
    else if (degree > CARDINAL_NEbN_MIN && degree < CARDINAL_NEbN_MAX)
    {
      _intOut = 29;
      _stringOut = "NW";
    }
    else if (degree > CARDINAL_NW_MIN && degree < CARDINAL_NW_MAX)
    {
      _intOut = 30;
      _stringOut = "NWbN";
    }
    else if (degree > CARDINAL_NNW_MIN && degree < CARDINAL_NNW_MAX)
    {
      _intOut = 31;
      _stringOut = "NNW";
    }
    else if (degree > CARDINAL_NbW_MIN && degree < CARDINAL_NbW_MAX)
    {
      _intOut = 32;
      _stringOut = "NbW";
    }
  }
  else {     // Invalid type specified.
      _intOut = 0;
      _stringOut = "ERR";
  }
}

String Cardinal::string(int type, float degree)
{
  _lookup(type, degree);
  return _stringOut;
}
int Cardinal::integer(int type, float degree)
{
  _lookup(type, degree);
  return _intOut;
}