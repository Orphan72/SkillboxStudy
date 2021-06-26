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

std::string get_intPart (std::string str, bool mns) {
    std::string strResult = "";
    int dot = find_dot(str);
    if (dot == -1)
    {
        return str;
    }
    int start = mns ? 1 : 0;
    for (int i = start; i < dot; i++) {
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

bool checkSymbol (std::string str) {
    for (int i = 0; i < str.length(); i++)
    {
        if (str [i] < '0' || str [i] > '9')
        {
            return false;
        }
    }
    return true;
}

int convertStrToUnsLong (std::string str) {
    long long number = 0;
    int endPos = str.length() - 1;
    int factor = 1;

     for (int i = endPos; i >= 0; i--) {
        number += (factor * (str [i] - '0'));
        if (number > INT_MAX)
        {
           return 0;
        }
        factor *= 10;
    }

    return (int)number;
}

 bool checkCorrectEnter (std::string intStr, std::string fracStr) {
    bool correctEnter = (checkSymbol(intStr) &&
                         checkSymbol(fracStr));
    if (!correctEnter) {
        std::cout << "Input incorrect symbols!\n";
        return false;
    } else {
        int nmb = convertStrToUnsLong (intStr);
        if (nmb == 0 && intStr [0] != '0' && intStr.length() != 0)
        {
            std::cout << "Int number should be between " << INT_MIN << " and " <<  INT_MAX  << std::endl;
            return false;
        }
    }
    return true;
}

//return
// -1 if less,
// 1 if more,
// 0 if equal
int compareFrac (std::string str1, std::string str2, bool mns1)
{
    size_t length1 = str1.length();
    size_t length2 = str2.length();
    size_t endPos = (length1 < length2) ? length1 : length2;

    for (int i = 0; i < endPos; i++)
    {
        if (str1 [i] != str2 [i])
        {
            if (!mns1)
                return (str1 [i] > str2 [i])  ? 1 : -1;
            else return (str1[i] < str2[i]) ? 1 : -1;
        }
    }
    return 0;
}

int main() {

    std::string str_first;
    std::string str_second;

    std::cout << "Enter first number\n=>";
    std::getline(std::cin, str_first);

    std::cout << "Enter second number\n=>";
    std::getline(std::cin, str_second);

    bool minus_first = (str_first.length() > 0 && str_first [0] == '-');
    bool minus_second = (str_second.length() > 0 && str_second [0] == '-');

    std::string strIntPart_first = get_intPart (str_first, minus_first);
    std::string strFracPart_first = get_fracPart(str_first);

    std::string strIntPart_second = get_intPart (str_second, minus_second);
    std::string strFracPart_second = get_fracPart(str_second);

    bool correctEnter = (checkCorrectEnter(strIntPart_first, strFracPart_first) &&
                         checkCorrectEnter(strIntPart_second, strFracPart_second));

    if (correctEnter)
    {
        int strInt_first =  convertStrToUnsLong (strIntPart_first);
        int strInt_second =  convertStrToUnsLong (strIntPart_second);

        strInt_first  = minus_first ? -strInt_first : strInt_first;
        strInt_second  = minus_second ? -strInt_second : strInt_second;

        int compInt = (strInt_first - strInt_second);
        if (compInt > 0) std::cout << "More!\n";
        else if (compInt < 0) std::cout << "Less!\n";
        else {
            int compFrac = compareFrac(strFracPart_first, strFracPart_second, minus_first);
            if (compFrac > 0) std::cout << "More!\n";
            else if (compFrac < 0) std::cout << "Less!\n";
            else std::cout << "Equal!\n";
        }
    }
    return 0;
}

