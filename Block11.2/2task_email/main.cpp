#include <iostream>

std::string firstPart (std::string str)
{
    bool et = false;
    int etPos = 0;
    std::string strResult = "";
    for (int i = 0; !et && i < str.length(); i++)
    {
        if (str [i] == '@')
        {
            et = true;
            etPos = i;
        }
    }

    if (et)
    {
        for (int i = 0; i < etPos; i++)
        {
            strResult += str[i];
        }
    }

    return strResult;
}

std::string secondPart (std::string str)
{
    bool et = false;
    int etPos = 0;
    std::string strResult = "";
    for (int i = 0; !et && i < str.length(); i++)
    {
        if (str [i] == '@')
        {
            et = true;
            etPos = i + 1;
        }
    }

    if (et)
    {
        for (int i = etPos; i < str.length(); i++)
        {
            strResult += str[i];
        }
    }

    return strResult;
}

bool checkSymbols (std::string str, std::string symbols)
{
    bool sym = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.' && str[i - 1] == '.') return false;

        sym = ((str [i] >= '0' && str [i] <= '9') ||
               (str [i] >= 'A'  && str [i] <= 'Z') ||
               (str [i] >= 'a'  && str [i] <= 'z'));

        if (!sym)
        {
            for (int j = 0; j < symbols.length(); j++)
            {
                sym = (str[i] == symbols[j]);
                if (sym) break;
                if (j == (symbols.length() - 1) && sym == false)
                    return false;
            }
        }
        //sym = false;
    }
    return sym;
}

bool checkFirst (std::string str)
{
    std::string symFirst = ".!#$%&'*+-/=?^_`{|}~";
    if (str [0] == '.' || str.length() < 1 || str.length() > 64)
        return false;

    return checkSymbols (str, symFirst);

}

bool checkSecond (std::string str)
{

    std::string symSec = ".-";
    int last = str.length() - 1;
    if (str [last] == '.' || str.length() < 1 || str.length() > 63)
        return false;

    return checkSymbols (str, symSec);
}

int main()
{
    std::string str = "";

    std::cout << "Enter email\n=>";
    std::getline(std::cin, str);

    std::string strFirst = firstPart (str);
    std::string strSecond = secondPart (str);

    bool correct = (checkFirst(strFirst) && checkSecond(strSecond));

    std::cout << (correct ? "Yes\n" : "No\n");
    return 0;
}

