#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::stringstream text;
    std::string strFirstNum  = " ";
    std::string strSecondNum = " ";
    std::string action;
    std::string expression = " ";

    std::cout << "Enter math expression\n=>";
    std::getline (std::cin, expression);

  //  std::cout << "expression " << expression << std::endl;
    text << expression;
    text >> strFirstNum >> action >> strSecondNum;
/*
    std::cout << strFirstNum << std::endl;
    std::cout << action << std::endl;
    std::cout << strSecondNum << std::endl;
*/
    double firstNum  = std::stod (strFirstNum);
    double secondNum = std::stod (strSecondNum);

/*
    std::cout << firstNum << std::endl;
    std::cout << secondNum << std::endl;
*/

    double result = 0.0;

    if (action == "+")      result = firstNum + secondNum;
    else if (action == "-") result = firstNum - secondNum;
    else if (action == "*") result = firstNum - secondNum;
    else if (action == "/") result = firstNum / secondNum;

   std::cout << "Result is " << result << std::endl;

    return 0;
}

