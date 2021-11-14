#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    POWER           = 2,
    SOCKETS         = 4,
    INSIDE_ILLUM    = 8,
    OUTSIDE_LIGHT   = 16,
    INSIDE_HEATING  = 32,
    OUTSIDE_HEATING = 64,
    AIRCONDITION    = 128
};

enum sunlight
{
    LIGHT,
    TWILIGHT,
    DARK
};

const int DAYS = 2;
const int DAYHOURS = 24;
const int MORNING = 5;
const int EVENING = 16;
const int NIGHT = 20;

const int WIN_TEMP = 0;
const int SUM_TEMP = 5;
const int COLD_TEMP = 22;
const int WARM_TEMP = 25;
const int HOT_TEMP = 30;

const int COLOR_TEMP_MIN = 2700;
const int COLOR_TEMP_MAX = 5000;

int main()
{
    int state = 0;
    int outTemp = WIN_TEMP;
    int inTemp = 0;
    int level_illum = 0;
    bool move_sensor = false;

    std::string input_str;
    std::string str_move_sensor;
    std::string str_inside_illum;

    sunlight outside_light;

    int diff = NIGHT - EVENING;
    int color_temp [diff];
    int step_color = (COLOR_TEMP_MAX - COLOR_TEMP_MIN) / diff;

    for (int k = 0; k <= diff; k++)
    {
        color_temp [k] = COLOR_TEMP_MAX - step_color*k;
    }

    for (int i = 0; i < DAYS; i++)
    {
        for (int j = 0; j < DAYHOURS; j++)
        {
            std::stringstream text;
            int time = j;
            std::cout << "======================\n";
            std::cout << "Time is " << time << ":00" << std::endl;

            state |= POWER;
            state |= SOCKETS;

            std::cout << "Enter:\ntemperature outside,\ntemperature inside,\n";
            std::cout << "move outside status (Y/N),\nlight inside status (On/Off)\n=>";

            getline(std::cin, input_str);
            text << input_str;
            text >> outTemp >> inTemp >> str_move_sensor >> str_inside_illum;

            if (time >= MORNING && time < EVENING)
                outside_light = LIGHT;
            else if (time >= EVENING && time < NIGHT)
                outside_light = TWILIGHT;
            else
                outside_light = DARK;

            if (state & POWER)
            {
                if (str_move_sensor == "Y")
                    move_sensor = true;
                else if (str_move_sensor == "N")
                    move_sensor = false;

                if (str_inside_illum == "On")
                    state |= INSIDE_ILLUM;
                else if (str_inside_illum == "Off")
                    state &= ~INSIDE_ILLUM;

                if (state & INSIDE_ILLUM)
                {
                    if (time >= 0)
                        level_illum = COLOR_TEMP_MAX;
                    if (time > EVENING && time <= NIGHT)
                        level_illum = color_temp[time - EVENING];
                    else if (time > NIGHT)
                        level_illum = COLOR_TEMP_MIN;
                }
                else
                    level_illum = 0;

                if ((outside_light == DARK || outside_light == TWILIGHT) && move_sensor)
                    state |= OUTSIDE_LIGHT;
                else
                    state &= ~OUTSIDE_LIGHT;

                if (outTemp < WIN_TEMP)
                    state |= OUTSIDE_HEATING;
                else if (outTemp > SUM_TEMP)
                    state &= ~OUTSIDE_HEATING;

                if (state & SOCKETS)
                {
                    if (inTemp < COLD_TEMP)
                        state |= INSIDE_HEATING;
                    else if (inTemp >= WARM_TEMP)
                        state &= ~INSIDE_HEATING;
                    if (inTemp >= HOT_TEMP)
                        state |= AIRCONDITION;
                    else if (inTemp <= WARM_TEMP)
                        state &= ~AIRCONDITION;
                }
                else
                {
                    state &= ~INSIDE_HEATING;
                    state &= ~AIRCONDITION;
                }
            }
            else
            {
                state &= ~OUTSIDE_HEATING;
                state &= ~INSIDE_HEATING;
                state &= ~AIRCONDITION;
                state &= ~OUTSIDE_LIGHT;
                state &= ~INSIDE_ILLUM;
            }

            std::cout << ((state & OUTSIDE_HEATING) ? "OUTSIDE HEATING is ON " : "OUTSIDE HEATING is OFF ") << std::endl;
            std::cout << ((state & INSIDE_HEATING) ? "INSIDE HEATING is ON " : "INSIDE HEATING is OFF ") << std::endl;
            std::cout << ((state & AIRCONDITION) ? "AIRCONDITION is ON " : "AIRCONDITION is OFF ") << std::endl;
            std::cout << ((state & OUTSIDE_LIGHT) ? "OUTSIDE ILLUMINATIONT is ON " : "OUTSIDE LIGHT is OFF ") << std::endl;
            std::cout << "INSIDE ILLUMINATION LEVEL is " << level_illum << std::endl;
           }
    }

    return 0;
}
