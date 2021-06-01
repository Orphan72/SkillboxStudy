#include <iostream>

//функция должна быть булевая, значит внутри должен быть флаг

bool fun (std::string str)
{
    bool et = false;
    bool correct = true;
    int etPos = 0;
    int startSecond = 0;

    for (int i = 0; !et && i < str.length(); i++)
    {
        //std::cout << str[i];
        if (str [i] == '@')
       {
           et = true;
           etPos = i;
           startSecond = i + 1;
           //std::cout << str[i] << std::endl;
           //std::cout << i << std::endl;
       }
    }

    if (!et) return false;
    else
    {
        for (int i = 0; i < etPos; i++)
        {
            std::cout << str[i];
            if (str [0] == '.') return false;
            else if (str[i] == '.' && str[i - 1] == '.') return false;

        }
        std::cout << std::endl;
        for (int i = startSecond; i < str.length(); i++)
        {

            int endPos = str.length() - 1;
            if (str [endPos] == '.') return false;
            else if (str[i] == '.' && str[i - 1] == '.') return false;
            std::cout << str[i];
        }
        std::cout << std::endl;

    }

    /*
    int endPos = str.length() - 1;
    if ((str [0] == '.') || (str[endPos] == '.') ||
        (str[i] == '.' && str[i - 1] == '.'))
        return false;
    */

/*
    for (int i = etPos + 1; i < str.length(); i++)
    {
        if (str [i] == '@') return false;
    }

*/
    return correct;
}

int main()
{
    std::string str = "";

    bool et = false;
    int etPos = 0;
    int secondStart = 0;
    bool cor = true;

    std::cout << "Enter email\n=>";
    std::getline(std::cin, str);

    cor = fun (str);


    if (cor)
    {
        std::cout << "Yes. " << etPos << "\n";
    }
    else
    {
        std::cout << "No\n";
    }

    //std::cout << (correct ? "Yes.\n" : "No\n");
    //correct ? std::cout << "Yes.\n" : "No\n"



    /*

    bool cor = false;
    while (!cor)
    {
        std::cout << "Enter email\n=>";
        std::getline(std::cin, str);
        cor = fun (str);
        std::cout << (cor ? "Yes\n" : "No\n");
    }

*/
    return 0;
}


/*
 Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @.
 Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов.
 Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним символом,
 а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:

!#$%&'*+-/=?^_`{|}~
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.

 */