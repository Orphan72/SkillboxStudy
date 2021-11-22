#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::stringstream text;
    std::string strFirstNum  = " ";
    std::string strSecondNum = " ";
    std::string action = " ";
    std::string expression = " ";

    std::cout << "Enter math expression\n=>";
    std::getline (std::cin, expression);

    text << expression;
    text >> strFirstNum >> action >> strSecondNum;

    double firstNum  = std::stod (strFirstNum);
    double secondNum = std::stod (strSecondNum);
    double result = 0.0;

    if (action == "+")      result = firstNum + secondNum;
    else if (action == "-") result = firstNum - secondNum;
    else if (action == "*") result = firstNum - secondNum;
    else if (action == "/") result = firstNum / secondNum;

    std::cout << "Result is " << result << std::endl;

    return 0;
}

