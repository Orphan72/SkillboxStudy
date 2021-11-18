#include <iostream>
#include <string>

int main()
{
    //const int DEVIDER = 10;
    ///int integer    = 0;
    std::string str_int {};
    std::string str_frac {};
    std::string str_dot = ".";
    std::string str_double {};



    std::cout << "Enter the integer part of number\n=> ";
    //std::cin >> str_int;
    str_int = "12345";
    std::cout << "Enter the fractional part of a number\n=> ";
    str_frac = "5678";
    //std::cin >> str_frac;

    str_double = str_int + str_dot;
    str_double = str_double + str_frac;


    double num_frac = std::stoi(str_double);






    std::cout << "num_frac " << num_frac << std::endl;


    //double result = (integer < 0) ? integer - num_frac : integer + num_frac;

    //std::cout << "result is " << result << std::endl;
    return 0;
}
