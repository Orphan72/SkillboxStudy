#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string str_int {};
    std::string str_frac {};
    std::string str_dot = ".";
    std::string str_double {};

    std::cout << "Enter the integer part of number\n=> ";
    std::cin >> str_int;
    std::cout << "Enter the fractional part of a number\n=> ";
    std::cin >> str_frac;

    str_double = str_int + str_dot;
    str_double = str_double + str_frac;

    unsigned int leight = str_double.length();
    double num_frac = std::stod(str_double);

    std::cout << "result is " << std::setprecision(leight) << num_frac << std::endl;
    return 0;
}
