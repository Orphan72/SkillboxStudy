#include <iostream>

int getDotPos (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str [i] == '.') return i;
    }
    return 0;
}

std::string getFirst (std::string str, int pos)
{
    std::string strResult = "";
    if (pos > 0) {
        for (int i = 0; i < pos; i++) {
            strResult += str[i];
        }
    }
    return strResult;
}

std::string getRest (std::string str, int pos) {
    std::string strResult = "";
    if (pos > 0) {
        pos++;
        for (int i = pos; i < str.length(); i++) {
            strResult += str[i];
        }
        return strResult;
    }
}

int getCountDot (std::string str) {
    int count = 0;
    int endPos = str.length() - 1;
    if (str [0] == '.' || str [endPos] == '.') return 0;
    for (int i = 1; i < str.length(); i++) {
        if (str [i] == '.' && str [i - 1] == '.') return 0;
        else if (str [i] == '.') count++;
    }
    return count;
}

bool checkSymbol (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str [i] < '0' || str [i] > '9') return false;
     }
    return true;
}

int convert (std::string str) {
    int strint = 0;
    if (str.length() > 3) return -1;
    else if (str.length() > 1 && str [0] == '0') return -1;
    else {
        int endPos = str.length() - 1;
        for (int i = endPos, j = 1; i < str.length(); i--, j *= 10) {
            strint += (j * (str [i] - '0'));
        }
    }
    return strint;
}

bool checkNum (int num) {
    return (num >= 0 && num <= 255);
}

bool checkCorrect (std::string str)
{
    int dotCount = getCountDot (str);
    if (dotCount != 3) return false;
    else {
        std::string strRest = "";
        int number = 0;
        bool cor = false;
        int dotPos = 0;
        for (int i = 0; i < dotCount; i++) {
            dotPos = getDotPos (str);
            std::string strFirst = getFirst(str, dotPos);
            std::cout << "strFirst " << strFirst << std::endl;
            cor = checkSymbol (strFirst);
            if (!cor) return false;
            else {
                number = convert(strFirst);
                cor = checkNum(number);
                if (!cor) return false;
                else {
                    dotPos = getDotPos (str);
                    strRest = getRest(str, dotPos);
                    str = strRest;
                }
            }
        }

        cor = checkSymbol (strRest);
        std::cout << "correrct Symbol = " << cor << std::endl;
        if (!cor) return false;
        else {
            number = convert(strRest);
            cor = checkNum(number);
            if (!cor) return false;
            else return true;
       }
    }
}

int main() {
    std::string ipAdress = "";

    std::cout << "Enter IP adress\n=>";
    std::getline(std::cin, ipAdress);
    bool correct = checkCorrect (ipAdress);

    std::cout << (correct ? "Yes\n" : "No\n");
    return 0;
}
