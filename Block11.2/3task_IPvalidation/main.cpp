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

bool check (std::string str)
{
    if (str.length() > 3) return false;
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str [i] < '0' && str [i] > '9')
                return false;
            else if (str [0] > '2')
                return false;
            else if (str [0] > '1' && str [1] > '5')
                return false;
            else return true;
        }

    }
}




int main()
{
    std::string ipAdress = "";
    bool correct = false;

    std::cout << "Enter IP adress\n=>";
    std::getline(std::cin, ipAdress);

    int dotCount = getDot (ipAdress);
    if (dotCount == 3)
    {
        for (int i = 0; i <= dotCount; i++)
        {
            std::string strFirst = getFirst(ipAdress);
            std::string strRest = getRest(ipAdress);
            bool cor = check(strFirst);
            if (!cor) break;

            std::cout << strFirst << std::endl;
            std::cout << strRest << std::endl;
            ipAdress = strRest;
        }
    }

       //std::string strSecond = getFirst(ipAdress);
       //std::string strThird = getFirst(ipAdress);
       //std::string strFourth = getFirst(ipAdress);
       correct = true;


    //bool correct = (checkFirst(strFirst) && checkSecond(strSecond));

    std::cout << (correct ? "Yes\n" : "No\n");
    return 0;
}

/*Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно.
 Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, присутствовать не должно.
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, и слово No, если это не так.
 */