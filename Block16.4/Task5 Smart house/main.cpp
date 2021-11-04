#include <iostream>
#include <string>

enum switches
{
    POWER           = 2,
    SOCKETS         = 4,
    INSIDE_LIGHT    = 8,
    OUTSIDE_LIGHT   = 16,
    INSIDE_HEATING  = 32,
    OUTSIDE_HEATING = 64,
    AIRCONDITION    = 128
};

enum hours
{
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ELEVEN,
    TWELVE
};

enum move
{
    OFF,
    ON
};

enum sunlight
{
    NIGHT,
    DAY
};


int main()
{
    const int DAYTIME = 24;
    const int MORNING = 5;
    const int EVENING = 16;
    const int WINTER = 0;
    const int SUMMER = 5;

    int state = 0;
    int outsideTemperature = WINTER;
    int insideTemperature = 0;
    int time = 0;


    sunlight light = NIGHT;
    move mv = OFF;






    if (time > MORNING || time < EVENING) light = DAY;
    else light = NIGHT;


    if (outsideTemperature < WINTER)
    {
        state |= OUTSIDE_HEATING;
    }
    else if (insideTemperature > SUMMER)
    {
        state &= ~OUTSIDE_HEATING;
    }

    if (light == NIGHT)
    {
        if (mv == ON)
        {
            // свет включен
        }
        else
        {
            // свет выключен
        }
    }
    else
    {
        // свет выключен
    }








    state |= SOCKETS;

    if (state & POWER) std::cout << "Power of hous ON";
    if (state & SOCKETS) std::cout << "Socket ON";
    if (state & INSIDE_LIGHT) std::cout << "Inside light ON";
    if (state & OUTSIDE_LIGHT) std::cout << "Outside light ON";
    if (state & INSIDE_HEATING) std::cout << "Inside heating ON";
    if (state & OUTSIDE_HEATING) std::cout << "Outside heating ON";
    if (state & AIRCONDITION) std::cout << "Aircondition ON";


    state &= ~SOCKETS;


    if (state | POWER) std::cout << "Power of hous OFF";
    if (state | SOCKETS) std::cout << "Socket OFF";
    if (state | INSIDE_LIGHT) std::cout << "Inside light OFF";
    if (state | OUTSIDE_LIGHT) std::cout << "Outside light OFF";
    if (state | INSIDE_HEATING) std::cout << "Inside heating OFF";
    if (state | OUTSIDE_HEATING) std::cout << "Outside heating OFF";
    if (state | AIRCONDITION) std::cout << "Aircondition OFF";











    return 0;
}
/*

enum time
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ELEVEN,
    TWELVE
};

 int hours [DAYTIME];
    for (int i = 1; i <= DAYTIME; i++) hours [i] = i;





*/


