#include <iostream>

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
    //std::cout << "start " << start << "\n";
    //int length = str.length();
    //std::cout << "length " << length << "\n";
    for (int i = start; i < str.length(); i++)
    {
        if (str [i] < '0' || str [i] > '9')
        {
            //std::cout << "incorr symbols: \n";
            //std::cout << i << " " << str [i] << "\n";
            return false;
        }
    }
    return true;
}

/*

bool correctEnter (std::string str)
{
    //bool cor = false;
    bool minus = (str.length() > 0 && str [0] == '-');
    int dot = find_dot(str);
    if (dot == -1) {
        return checkSymbol(str, minus);
        //std::cout << "correct68 - " << correct << "\n";
        //std::cout << "str - " << str << "\n";

    }
    else {
        std::string strIntPart = get_intPart (str);
        std::cout << "strIntPart: " << strIntPart << "\n";
        std::string strFracPart = get_fracPart(str);
        std::cout << "strFracPart: " << strFracPart << "\n";
        return (checkSymbol(strIntPart, minus) && checkSymbol(strFracPart, false));
        //std::cout << "correct78 - " << correct << "\n";
    }
}

*/





int convertInt (std::string str, bool mns) {

    int strInt = 0;
    int endPos = str.length() - 1;
    int factor = 1;

    int start  = mns ? 1 : 0;
    for (int i = endPos; i >= start; i--) {
        strInt += (factor * (str [i] - '0'));
        factor *= 10;
    }
    strInt  = mns ? -strInt : strInt;
    return strInt;
}

float convertFrac (std::string str) {
    float strFrac = 0;
    int endPos = str.length() - 1;
    int factor = 1;

    for (int i = endPos; i >= 0; i--) {
        strFrac += (factor * (str [i] - '0'));
        factor *= 10;
    }
    return strFrac;
}

// в предыдущем заданиии пподправить метод convert
float convert (std::string str) {


    int strInt_int = 0;
    float strFrac_float = 0;

    bool minus = (str.length() > 0 && str [0] == '-');
    int dot = find_dot(str);
    if (dot == -1)
    {
        //return convertInt (str);
    }
    else
    {
        //strInt_int = convertInt (strIntPart);
        std::cout << "strInt_int: " << strInt_int << "\n";



        //strFrac_float = convertFrac (strFracPart);
        std::cout << "strFrac_float: " << strFrac_float << "\n";
    }


    return (strInt_int + strFrac_float);

}


   /* for (int i = endPos; i <= str.length(); i--) {
        std::cout  << "i = " << i << std::endl;
       }*/




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

    std::cout << "strIntPart_first: " << strIntPart_second << "\n";
    std::cout << "strFracPart_first: " << strFracPart_second << "\n";

    bool correctEnter = (checkSymbol (strIntPart_first, minus_first) &&
                         checkSymbol (strFracPart_first, false) &&
                         checkSymbol(strIntPart_second, minus_second) &&
                         checkSymbol(strFracPart_second, false));

    std::cout << "correctSymbol: " << correctEnter << "\n";

    if (!correctEnter) std::cout << "Input incorrect!\n";
    else {
        int strIntToInt_first = convertInt (strIntPart_first, minus_first);
        float strFracToFloat_first = convertFrac(strFracPart_first);
        int strIntToInt_second = convertInt (strIntPart_second, minus_second);
        float strFracToFloat_second = convertFrac(strFracPart_second);

        std::cout << "strIntToInt_first: " << strIntToInt_first << "\n";
        std::cout << "strFracToFloat_first: " << strFracToFloat_first << "\n";
        std::cout << "strIntToInt_second: " << strIntToInt_second << "\n";
        std::cout << "strFracToFloat_second: " << strFracToFloat_second << "\n";
    }

    // std::string strIntPart_first = "";
   // std::string strFracPart_second = "";

   // int str_int = 0;
    //int strIntPart_int = 0;
   // float strFracPart_float = 0;

    //bool correct = (correctEnter(str_first) && correctEnter(str_second));

   //    bool correct = (correctEnter(str_first) && (correctEnter(str_second)));

/*

    int dot = find_dot(str);
    //std::cout << "DOT:  " << dot << "\n";

    if (dot == -1) {
        cor = check(str, minus);
        //std::cout << "correct68 - " << correct << "\n";
        //std::cout << "str - " << str << "\n";

    }
    else {
        strIntPart = get_intPart (str, dot);
        std::cout << "strIntPart: " << strIntPart << "\n";
        strFracPart = get_fracPart(str, dot);
        std::cout << "strFracPart: " << strFracPart << "\n";
        correct = (check(strIntPart, minus) && check(strFracPart, false));
        //std::cout << "correct78 - " << correct << "\n";
    }










    str_int = convertInt (str, minus);
    std::cout << "str_int: " << str_int << "\n";


   */

//========================================

/*
    if (!correct) {
        std::cout << "Input incorrect!\n";
    }
    else {



        std::cout << "GOOD!\n";

        float str1;
        float str2;

        str1 = convert(str_first);
        str2 = convert(str_second);

        std::cout << "str1   " << str1 << "\n";
        std::cout << "str2   " << str2 << "\n";


        //strIntPart_int = convertInt (strIntPart, minus);
        //std::cout << "strIntPart_int: " << strIntPart_int << "\n";
        //strFracPart_float = convertFrac (strFracPart);
        //std::cout << "strSecond_int: " << strFracPart_float << "\n";



        bool more;
        if (str1 > str2)
        {
            std::cout << "more\n";
        }
        else
        std::cout << "less\n";


          //  more = (strIntPart_int > strFracPart_int) ? true : false;
        //else
        //{

        //}






    }
*/
    return 0;
}





/*
  Вы продолжаете писать калькулятор, работающий над вещественными числами повышенной точности. Вы уже научились проверять корректность записи вещественных чисел в виде строк,
  и теперь перед вами новая цель — научиться сравнивать такие вещественные числа.
    Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче «Длинное вещественное число».
 Программа должна проверить корректность ввода (для этого можно переиспользовать код,
 написанный в задаче «Длинное вещественное число»), после чего вывести слово Less, если первое число строго меньше второго; слово More,
 если первое число строго больше второго; и слово Equal, если введённые числа равны.
 */