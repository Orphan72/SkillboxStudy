#include <iostream>
#include <string>

int main()
{
    const int DEVIDER = 10;
    int integer    = 0;
    std::string str_frac = " ";

    std::cout << "Enter the integer part of number\n=> ";
    std::cin >> integer;
    std::cout << "Enter the fractional part of a number\n=> ";
    std::cin >> str_frac;
    double num_frac = std::stoi(str_frac);
    std::cout << "num_frac " << num_frac << std::endl;
    for (int i = 0; i < str_frac.length(); i++)
    {
       num_frac /= DEVIDER;
    }

    double result = (integer < 0) ? integer - num_frac : integer + num_frac;

    std::cout << "result is " << result << std::endl;
    return 0;
}
