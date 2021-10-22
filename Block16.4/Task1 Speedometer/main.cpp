#include <iostream>
#include <iomanip>
#include <sstream>

bool compare (double value, double reference, double epsilon)
{
    return (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main()
{
    std::stringstream text;
    double const EPSILON = 0.01;
    const int MAXSPEED = 150;
    double speed  = 0.0;
    double raise  = 0.0;

    std::cout << "Go!\n";
    do
    {
       std::cout << "\nEnter delta \n=>";
        std::cin >> raise;
        speed = speed + raise;
        if (speed < 0 - EPSILON || speed > MAXSPEED + EPSILON)
        {
            std::cout << "speed value is not correct" << std::endl;
            speed = speed - raise;
            std::cout << "try again" << std::endl;
        }
        else
        {
            std::cout << "Speed is " << speed << " km/h" << std::endl;
            text << "\nSpeed is " << std::fixed << std::setprecision(1) << speed << " km/h";
        }

    } while (!compare(speed, 0, EPSILON));

    std::cout << text.str();

    return 0;
}