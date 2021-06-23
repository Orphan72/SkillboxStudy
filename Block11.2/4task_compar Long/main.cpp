#include <iostream>
#include <climits>

int find_dot (std::string str)
{
    int dt = -1;
    for (int i = 0; dt == -1 && i < str.length(); i++)
    {
        if (str [i] == '.')
            dt = i;
    }
    return dt;
}

std::string get_intPart (std::string str) {
    std::string strResult = "";
    int dot = find_dot(str);
    if (dot == -1)
    {
        return str;
    }

    for (int i = 0; i < dot; i++) {
            strResult += str[i];
    }
    return strResult;
}

std::string get_fracPart (std::string str) {
    std::string strResult = "";
    int dot = find_dot(str);
    if (dot == -1)
    {
        return "";
    }
    for (int i = dot + 1; i < str.length(); i++) {
       strResult += str[i];
    }
    return strResult;
}

bool checkSymbol (std::string str, bool mns)
{
    int start  = mns ? 1 : 0;
    for (int i = start; i < str.length(); i++)
    {
        if (str [i] < '0' || str [i] > '9')
        {
            return false;
        }
    }
    return true;
}

int convert (std::string str, bool mns) {

    long long number = 0;
    int endPos = str.length() - 1;
    int factor = 1;

    int start  = mns ? 1 : 0;
    for (int i = endPos; i >= start; i--) {
        number += (factor * (str [i] - '0'));
        if (number > INT_MAX)
        {
           return 0;
        }
        factor *= 10;
    }
    number  = mns ? -number : number;
    return number;
}

int main() {

    std::string str_first = "";
    std::string str_second = "";

    std::cout << "Enter first number\n=>";
    std::getline(std::cin, str_first);

    std::cout << "Enter second number\n=>";
    std::getline(std::cin, str_second);

    bool minus_first = (str_first.length() > 0 && str_first [0] == '-');
    bool minus_second = (str_second.length() > 0 && str_second [0] == '-');

    std::string strIntPart_first = get_intPart (str_first);
    std::string strFracPart_first = get_fracPart(str_first);

    std::string strIntPart_second = get_intPart (str_second);
    std::string strFracPart_second = get_fracPart(str_second);

    std::cout << "strIntPart_first: " << strIntPart_first << "\n";
    std::cout << "strFracPart_first: " << strFracPart_first << "\n";

    std::cout << "strIntPart_second: " << strIntPart_second << "\n";
    std::cout << "strFracPart_second: " << strFracPart_second << "\n";

    bool correctEnter = (checkSymbol (strIntPart_first, minus_first) &&
                         checkSymbol (strFracPart_first, false) &&
                         checkSymbol(strIntPart_second, minus_second) &&
                         checkSymbol(strFracPart_second, false));

    std::cout << "correctSymbol: " << correctEnter << "\n";

    if (!correctEnter) std::cout << "Input incorrect!\n";
    else {
        int strInt_first = convert (strIntPart_first, minus_first);
        int strFrac_first = convert (strFracPart_first, false);
        int strInt_second = convert (strIntPart_second, minus_second);
        int strFrac_second = convert (strFracPart_second, false);

        std::cout << "strIntToInt_first: " << strInt_first << "\n";
        std::cout << "strFracToFloat_first: " << strFrac_first << "\n";
        std::cout << "strIntToInt_second: " << strInt_second << "\n";
        std::cout << "strFracToFloat_second: " << strFrac_second << "\n";

       int compInt = (strInt_first - strInt_second);

       if (compInt > 0) std::cout << "More!\n";
       else if (compInt < 0) std::cout << "Less!\n";
       else {
           if (strFrac_first > strFrac_second)
               std::cout << "More!\n";
           else if (strFrac_first < strFrac_second)
                std::cout << "Less!\n";
                else std::cout << "Equal!\n";
            }
        }

    return 0;
}

