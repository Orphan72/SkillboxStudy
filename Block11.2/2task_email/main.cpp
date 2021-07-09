#include <iostream>

int get_etPos (std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str [i] == '@') return i;
    }
    return 0;
}

std::string firstPart (std::string str, int pos) {
    std::string strResult = "";
    if (pos > 0) {
        for (int i = 0; i < pos; i++) {
            strResult += str[i];
        }
    }
    return strResult;
}

std::string secondPart (std::string str, int pos) {
     std::string strResult = "";
     if (pos > 0 ) {
        pos++;
        for (int i = pos; i < str.length(); i++) {
            strResult += str[i];
        }
    }
    return strResult;
}

bool checkSymbols (std::string str, std::string symbols) {
    bool sym = false;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '.' && str[i - 1] == '.') return false;
    }

    for (int i = 0; i < str.length(); i++) {
        sym = ((str [i] >= '0' && str [i] <= '9') ||
               (str [i] >= 'A'  && str [i] <= 'Z') ||
               (str [i] >= 'a'  && str [i] <= 'z'));

        if (!sym) {
            for (int j = 0; j < symbols.length(); j++) {
                sym = (str[i] == symbols[j]);
                if (sym) break;
                if (j == (symbols.length() - 1) && sym == false)
                    return false;
            }
        }
    }
    return sym;
}

bool checkFirst (std::string str) {
    std::string symFirst = ".!#$%&'*+-/=?^_`{|}~";
    if (str [0] == '.' || str.length() < 1 || str.length() > 64) {
        return false;
    }
    return checkSymbols (str, symFirst);
}

bool checkSecond (std::string str) {

    std::string symSec = ".-";
    int last = str.length() - 1;
    if (str [last] == '.' || str.length() < 1 || str.length() > 63) {
        return false;
    }
    return checkSymbols (str, symSec);
}

int main()
{
    std::string str = "";

    std::cout << "Enter email\n=>";
    std::getline(std::cin, str);

    int etPos = get_etPos (str);

    std::string strFirst = firstPart (str, etPos);
    std::string strSecond = secondPart (str, etPos);

    bool correct = (checkFirst(strFirst) && checkSecond(strSecond));

    std::cout << (correct ? "Yes\n" : "No\n");
    return 0;
}
