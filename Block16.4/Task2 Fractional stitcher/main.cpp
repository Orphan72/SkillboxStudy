#include <iostream>
#include <string>

int main()
{
    const int DEVIDER = 10;
    int integer    = 0;
    int fractional = 0;
    int count      = 0;
    double result  = 0.0;
    std::cout << "Enter the integer part of number\n=> ";
    std::cin >> integer;
    std::cout << "Enter the fractional part of a number\n=> ";
    std::cin >> fractional;
    std::string str = std::to_string(fractional);

    double frac = fractional;
    for (int i = 0; i < str.length(); i++)
    {
       frac = frac/DEVIDER;
       count++;
    }

    result = integer + frac;
    std::cout << "result is " << result << std::endl;

    return 0;
}
