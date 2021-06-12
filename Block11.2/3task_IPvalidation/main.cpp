#include <iostream>

std::string getFirst (std::string str)
{
    bool dot = false;
    int dotPos = 0;
    std::string strResult = "";
    for (int i = 0; !dot && i < str.length(); i++)
    {
        if (str [i] == '.')
        {
            dot = true;
            dotPos = i;
        }
    }

    if (dot)
    {
        for (int i = 0; i < dotPos; i++)
        {
            strResult += str[i];
        }
    }
    return strResult;
}


std::string getRest (std::string str)
{
    bool dot = false;
    int dotPos = 0;
    std::string strResult = "";
    for (int i = 0; !dot && i < str.length(); i++)
    {
        if (str [i] == '.')
        {
            dot = true;
            dotPos = i + 1;
        }
    }
    for (int i = dotPos; i < str.length(); i++)
    {
        strResult += str[i];
        std::cout << str[i] << std::endl;
    }

    return strResult;
}

int getDot (std::string str)
{
    int count = 0;
    int endPos = str.length() - 1;
    if (str [0] == '.' || str [endPos] == '.') return 0;
    for (int i = 1; i < str.length(); i++)
    {
        if (str [i] == '.' && str [i - 1] == '.') return 0;
        else if (str [i] == '.') count++;
    }
    return count;
}

// Добавить проверку - цифры или символы

// обернуть в цикл
int convert (std::string str)
{
    int strint = 0;
    if (str.length() > 3) return -1;



    else if (str.length() == 3)
    {
        if (str [0] == '0' || str [1] == '0')
            return -1;
        else
        {
            strint = 100 * (str [0] - '0') +
                     10 * (str [1] - '0') +
                     (str [2] - '0');
        }
    }
    else if (str.length() == 2)
    {
        if (str [0] == '0') return -1;
        else
        {
            strint = 10 * (str [0] - '0') +
                     (str [1] - '0');
        }
    }

    else if (str.length() == 1)
    {
        strint = (str [0] - '0');
    }
    return strint;
}

bool check (int num)
{

    std::cout << "checknum: "  << num << std::endl;
    if (num < 0 || num > 256)
    {
        std::cout << "BAD "  << std::endl;
        return false;
    }
    else
    {
        std::cout << "GOOD "  << std::endl;
        return true;
    }


}



int main()
{
    std::string ipAdress = "";

    bool corFirst = true;
    bool corRest = true;


    std::cout << "Enter IP adress\n=>";
    std::getline(std::cin, ipAdress);

    int dotCount = getDot (ipAdress);

    std::cout << dotCount << std::endl;

    if (dotCount != 3) corFirst = false;
    else
    {
        std::string strRest = "";
        int number = 0;

        for (int i = 0; i < dotCount; i++)
        {
            std::cout << "ipAdress - " << i << " " << ipAdress << std::endl;

            std::string strFirst = getFirst(ipAdress);

            std::cout << "strFirst - " << strFirst << std::endl;
            number = convert (strFirst);
            corFirst = check(number);
            std::cout << (corFirst ? "GOoooOD\n" : "BREAK\n");
            if (!corFirst) break;

            std::cout << "number - "  << number << std::endl;

            strRest = getRest(ipAdress);
            std::cout << "strRest - " << strRest << std::endl;
            ipAdress = strRest;

            std::cout << "ipAdress - " << i << " " << ipAdress << std::endl;

            std::cout << " ------- \n";

            //correct = check(strFirst);
            //if (!correct) break;

            //std::cout << strFirst << std::endl;
            //std::cout << strRest << std::endl;

        }

        std::cout << "ipAdressNew - " << ipAdress << std::endl;
        std::cout << "strRestNew - " << strRest << std::endl;
        number = convert (strRest);
        corRest = check(number);

    }

       //std::string strSecond = getFirst(ipAdress);
       //std::string strThird = getFirst(ipAdress);
       //std::string strFourth = getFirst(ipAdress);
      // correct = true;


    //bool correct = (checkFirst(strFirst) && checkSecond(strSecond));

    std::cout << ((corFirst && corRest) ? "Yes\n" : "No\n");
    return 0;
}

/*Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно.
 Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, присутствовать не должно.
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, и слово No, если это не так.
 */