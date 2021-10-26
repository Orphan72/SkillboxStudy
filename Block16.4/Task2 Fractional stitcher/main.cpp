#include <iostream>
#include <string>

int main()
{
    const int DEVIDER = 10;
    int integer    = 0;
    int fractional = 0;

    std::cout << "Enter the integer part of number\n=> ";
    std::cin >> integer;
    std::cout << "Enter the fractional part of a number\n=> ";
    do
    {
        std::cin >> fractional;
        if (fractional < 0)
        {
            std::cout << "Fractional part of a number must be positive" << std::endl;
            std::cout << "Try again" << std::endl;
        }
    } while (fractional < 0);

    std::string str = std::to_string(fractional);

    double frac = fractional;
    for (int i = 0; i < str.length(); i++)
    {
       frac = frac/DEVIDER;
    }

    double result = 0.0;
    if (integer < 0)
    {
        result = integer - frac;
    }
    else
        result = integer + frac;

    std::cout << "result is " << result << std::endl;

    return 0;
}
