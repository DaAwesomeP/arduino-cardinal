/******************************************************************************
  Cardinal.h
  Cardinal Library header file
  Originally Created: August 10, 2015

  Written by Perry Naseck (https://perrynaseck.com/)
  Project homepage at https://github.com/DaAwesomeP/arduino-cardinal
  
  This sketch takes a number input in degrees from serial at 9600 baud
  and outputs the heading in number and text form.

    Copyright 2015-present Perry Naseck (DaAwesomeP)
    
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

#ifndef CARDINAL_H
#define CARDINAL_H

#include <Arduino.h>

/*************************************************
* Public Constants
*************************************************/

#define CARDINAL_N            1             // North, N, id 1, 0 degrees middle azimuth, 354.38 to 5.62 degrees range
#define CARDINAL_N_MIDAZ      0
#define CARDINAL_N_MIN        354.38
#define CARDINAL_N_MAX        5.62
#define CARDINAL_NbE          2             // North by East, NbE, id 2, 11.25 degrees middle azimuth, 5.63 to 16.87 degrees range
#define CARDINAL_NbE_MIDAZ    11.25
#define CARDINAL_NbE_MIN      5.63
#define CARDINAL_NbE_MAX      16.87
#define CARDINAL_NNE          3             // North-northeast, NNE, id 3, 22.5 degrees middle azimuth, 16.88 to 28.12 degrees range
#define CARDINAL_NNE_MIDAZ    22.5
#define CARDINAL_NNE_MIN      16.88
#define CARDINAL_NNE_MAX      28.12
#define CARDINAL_NEbN         4             // Northeast by North, NEbN, id 4, 33.75 degrees middle azimuth, 16.88 to 28.12 degrees range
#define CARDINAL_NEbN_MIDAZ   33.75
#define CARDINAL_NEbN_MIN     28.13
#define CARDINAL_NEbN_MAX     39.37
#define CARDINAL_NE           5             // Northeast, NE, id 5, 45 degrees middle azimuth, 39.38 to 50.62 degrees range
#define CARDINAL_NE_MIDAZ     45
#define CARDINAL_NE_MIN       39.38
#define CARDINAL_NE_MAX       50.62
#define CARDINAL_NEbE         6             // etc
#define CARDINAL_NEbE_MIDAZ   56.25
#define CARDINAL_NEbE_MIN     50.63
#define CARDINAL_NEbE_MAX     61.87
#define CARDINAL_ENE          7
#define CARDINAL_ENE_MIDAZ    67.5
#define CARDINAL_ENE_MIN      61.88
#define CARDINAL_ENE_MAX      73.12
#define CARDINAL_EbN          8
#define CARDINAL_EbN_MIDAZ    78.75
#define CARDINAL_EbN_MIN      73.13
#define CARDINAL_EbN_MAX      84.37
#define CARDINAL_E            9
#define CARDINAL_E_MIDAZ      90
#define CARDINAL_E_MIN        84.38
#define CARDINAL_E_MAX        95.62
#define CARDINAL_EbS          10
#define CARDINAL_EbS_MIDAZ    101.25
#define CARDINAL_EbS_MIN      95.63
#define CARDINAL_EbS_MAX      106.87
#define CARDINAL_ESE          11
#define CARDINAL_ESE_MIDAZ    112.5
#define CARDINAL_ESE_MIN      106.88
#define CARDINAL_ESE_MAX      118.12
#define CARDINAL_SEbE         12
#define CARDINAL_SEbE_MIDAZ   123.75
#define CARDINAL_SEbE_MIN     118.13
#define CARDINAL_SEbE_MAX     129.37
#define CARDINAL_SE           13
#define CARDINAL_SE_MIDAZ     135
#define CARDINAL_SE_MIN       129.38
#define CARDINAL_SE_MAX       140.62
#define CARDINAL_SEbS         14
#define CARDINAL_SEbS_MIDAZ   146.25
#define CARDINAL_SEbS_MIN     140.63
#define CARDINAL_SEbS_MAX     151.87
#define CARDINAL_SSE          15
#define CARDINAL_SSE_MIDAZ    157.5
#define CARDINAL_SSE_MIN      151.88
#define CARDINAL_SSE_MAX      163.12
#define CARDINAL_SbE          16
#define CARDINAL_SbE_MIDAZ    168.75
#define CARDINAL_SbE_MIN      163.13
#define CARDINAL_SbE_MAX      174.37
#define CARDINAL_S            17
#define CARDINAL_S_MIDAZ      180
#define CARDINAL_S_MIN        174.38
#define CARDINAL_S_MAX        185.62
#define CARDINAL_SbW          18
#define CARDINAL_SbW_MIDAZ    191.25
#define CARDINAL_SbW_MIN      185.63
#define CARDINAL_SbW_MAX      196.87
#define CARDINAL_SSW          19
#define CARDINAL_SSW_MIDAZ    202.5
#define CARDINAL_SSW_MIN      196.88
#define CARDINAL_SSW_MAX      208.12
#define CARDINAL_SWbS         20
#define CARDINAL_SWbS_MIDAZ   213.75
#define CARDINAL_SWbS_MIN     208.13
#define CARDINAL_SWbS_MAX     219.37
#define CARDINAL_SW           21
#define CARDINAL_SW_MIDAZ     225
#define CARDINAL_SW_MIN       219.38
#define CARDINAL_SW_MAX       230.62
#define CARDINAL_SWbW         22
#define CARDINAL_SWbW_MIDAZ   236.25
#define CARDINAL_SWbW_MIN     230.63
#define CARDINAL_SWbW_MAX     241.87
#define CARDINAL_WSW          23
#define CARDINAL_WSW_MIDAZ    247.5
#define CARDINAL_WSW_MIN      241.88
#define CARDINAL_WSW_MAX      253.12
#define CARDINAL_WbS          24
#define CARDINAL_WbS_MIDAZ    258.75
#define CARDINAL_WbS_MIN      253.13
#define CARDINAL_WbS_MAX      264.37
#define CARDINAL_W            25
#define CARDINAL_W_MIDAZ      270
#define CARDINAL_W_MIN        264.38
#define CARDINAL_W_MAX        275.62
#define CARDINAL_WbN          26
#define CARDINAL_WbN_MIDAZ    281.25
#define CARDINAL_WbN_MIN      275.63
#define CARDINAL_WbN_MAX      286.87
#define CARDINAL_WNW          27
#define CARDINAL_WNW_MIDAZ    292.5
#define CARDINAL_WNW_MIN      286.88
#define CARDINAL_WNW_MAX      298.12
#define CARDINAL_NWbW         28
#define CARDINAL_NWbW_MIDAZ   303.75
#define CARDINAL_NWbW_MIN     298.13
#define CARDINAL_NWbW_MAX     309.37
#define CARDINAL_NW           29
#define CARDINAL_NW_MIDAZ     315
#define CARDINAL_NW_MIN       309.38
#define CARDINAL_NW_MAX       320.62
#define CARDINAL_NWbN         30
#define CARDINAL_NWbN_MIDAZ   326.25
#define CARDINAL_NWbN_MIN     320.63
#define CARDINAL_NWbN_MAX     331.87
#define CARDINAL_NNW          31
#define CARDINAL_NNW_MIDAZ    337.5
#define CARDINAL_NNW_MIN      331.88
#define CARDINAL_NNW_MAX      343.12
#define CARDINAL_NbW          32
#define CARDINAL_NbW_MIDAZ    348.75
#define CARDINAL_NbW_MIN      343.13
#define CARDINAL_NbW_MAX      354.37


/*************************************************
* Definitions
*************************************************/

class Cardinal
{
  public:
    String getString(int type, float degree);
    int getInteger(int type, float degree);
  private:
    void _lookup(int type, float degree);
    int _intOut;
    String _stringOut;
};

#endif
