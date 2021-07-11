#include <iostream>
#include <climits>

int findDot (std::string str) {
    int dt = -1;
    for (int i = 0; dt == -1 && i < str.length(); i++){
        if (str [i] == '.')
            dt = i;
    }
    return dt;
}

std::string getIntPart (std::string str, bool mns) {
    std::string strResult = "";
    int dot = findDot(str);
    if (dot == -1) {
        return str;
    }
    int start = mns ? 1 : 0;
    for (int i = start; i < dot; i++) {
            strResult += str[i];
    }
    return strResult;
}

std::string getFracPart (std::string str) {
    std::string strResult = "";
    int dot = findDot(str);
    if (dot == -1) {
        return "";
    }
    for (int i = dot + 1; i < str.length(); i++) {
       strResult += str[i];
    }
    return strResult;
}

bool checkSymbol (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str [i] < '0' || str [i] > '9') {
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
        if (number > INT_MAX) {
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
        if (nmb == 0 && intStr [0] != '0' && intStr.length() != 0){
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
int compareFrac (std::string str1, std::string str2, bool mns1) {
    while (str1.length() != str2.length()) {
        if (str1.length() > str2.length()) {
            str2 += '0';
        }
        else if (str2.length() > str1.length()) {
            str1 += '0';
        }
    }
    size_t endPos = str1.length();
    for (int i = 0; i < endPos; i++) {
        if (str1 [i] != str2 [i]) {
            if (!mns1)
                return (str1 [i] > str2 [i])  ? 1 : -1;
            else return (str1[i] < str2[i]) ? 1 : -1;
        }
    }
    return 0;
}

int main() {

    std::string strFirst;
    std::string strSecond;

    std::cout << "Enter first number\n=>";
    std::getline(std::cin, strFirst);

    std::cout << "Enter second number\n=>";
    std::getline(std::cin, strSecond);

    bool minusFirst = (strFirst.length() > 0 && strFirst [0] == '-');
    bool minusSecond = (strSecond.length() > 0 && strSecond [0] == '-');

    std::string strIntPartFirst = getIntPart (strFirst, minusFirst);
    std::string strFracPartFirst = getFracPart(strFirst);

    std::string strIntPartSecond = getIntPart (strSecond, minusSecond);
    std::string strFracPartSecond = getFracPart(strSecond);

    bool correctEnter = (checkCorrectEnter(strIntPartFirst, strFracPartFirst) &&
                         checkCorrectEnter(strIntPartSecond, strFracPartSecond));

    if (correctEnter) {
        int strIntFirst =  convertStrToUnsLong (strIntPartFirst);
        int strIntSecond =  convertStrToUnsLong (strIntPartSecond);

        strIntFirst  = minusFirst ? -strIntFirst : strIntFirst;
        strIntSecond  = minusSecond ? -strIntSecond : strIntSecond;

        int compInt = (strIntFirst - strIntSecond);
        if (compInt > 0) std::cout << "More!\n";
        else if (compInt < 0) std::cout << "Less!\n";
        else {
            int compFrac = compareFrac(strFracPartFirst, strFracPartSecond, minusFirst);
            if (compFrac > 0) std::cout << "More!\n";
            else if (compFrac < 0) std::cout << "Less!\n";
            else std::cout << "Equal!\n";
        }
    }
    return 0;
}
