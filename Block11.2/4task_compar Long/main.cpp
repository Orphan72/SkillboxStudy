#include <iostream>

std::string get_firstPart (std::string str)
{
    bool dot = false;
    int dotPos = 0;
    std::string strResult = "";
    for (int i = 0; !dot && i < str.length(); i++) {
        if (str [i] == '.') {
            dot = true;
            dotPos = i;
        }
    }

    if (dot) {
        for (int i = 0; i < dotPos; i++) {
            strResult += str[i];
        }
    }

    return strResult;
}

std::string get_secondPart (std::string str) {
    bool dot = false;
    int dotPos = 0;
    std::string strResult = "";
    for (int i = 0; !dot && i < str.length(); i++) {
        if (str [i] == '.') {
            dot = true;
            dotPos = i + 1;
        }
    }

    if (dot) {
        for (int i = dotPos; i < str.length(); i++) {
            strResult += str[i];
        }
    }

    return strResult;
}

bool check (std::string str, bool minus) {
    int start  = minus ? 1 : 0;
    for (int i = start; i < str.length(); i++) {
        if (str [i] < '0' || str [i] > '9'){
            std::cout << "incorr symbols\n";
            return false;
        }
    }
    return true;
}


bool find_dot (std::string str)
{
    for (int i = 0; i < str.length(); i++) {
        if (str [i] == '.') return true;
        else return false;
    }

}




int main() {

    std::string str = "";

    std::cout << "Enter email\n=>";
    std::getline(std::cin, str);

    bool correct = false;
    bool minus = (str.length() > 0 && str [0] == '-');
    bool dot = find_dot(str);

    std::string strFirst = get_firstPart (str);

    if (!dot) {
        correct = check(strFirst, minus);
    }
    else {
        std::string strSecond = get_secondPart (str);
        correct = (check(strFirst, minus) && check(strFirst, false));
    }

    if (!correct) {
        std::cout << "Input incorrect!\n";
    }
    else {
        std::cout << "GOOD!\n";
    }





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