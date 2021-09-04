#include <iostream>
#include <vector>
#include <valarray>

const int SIZE = 5;

void display (std::vector <std::vector <bool>> vec)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << (vec [i][j] ?  "O " : "X ");
        }
        std::cout << std::endl;
    }
}

bool checkEnter (int a, int b)
{
    return !(a < 1 || a > SIZE || b < 1 || b > SIZE);
}

std::vector<std::vector <bool>> pop (std::vector<std::vector <bool>> vec, int stY, int stX, int finY, int finX)
{
    for (int i = (stY - 1); i < finY; i++)
    {
        for (int j = (stX - 1); j < finX; j++)
        {
            vec [i][j] = false;
        }
    }
    return vec;
}

bool checkIntact (std::vector <std::vector <bool>> vec)
{
    int countIntact = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (vec [i][j]) countIntact++;
        }
    }

    return countIntact > 0;
}

int main() {

    std::vector <std::vector<bool>> bubble (SIZE, std::vector<bool> (SIZE));
    int rowStart = 0;
    int colStart = 0;
    int rowFin   = 0;
    int colFin   = 0;
    bool intact  = true;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            bubble [i][j] = true;
        }
    }

    display(bubble);

    while (intact)
    {
        bool correct = false;
        while (!correct)
        {
            std::cout << "Please input start coordinates from 1 to 12\n=>";
            std::cin >> rowStart >> colStart;
            correct = checkEnter (rowStart, colStart);
            if (!correct)
            {
                std::cout << "Values must be from 1 to 12. Please, try again\n";
            }
        }

        correct = false;

        while (!correct)
        {
            std::cout << "Please input finish coordinates from 1 to 12\n=>";
            std::cin >> rowFin >> colFin;
            correct = checkEnter (rowFin, colFin);
            if (!correct)
            {
                std::cout << "Values must be from 1 to 12. Please, try again\n";
            }
        }

        bubble = pop (bubble, rowStart, colStart, rowFin, colFin);

        display(bubble);

        //std::cout << "Enter intct\n";
        intact = checkIntact (bubble);
        std::cout << "intct  " << intact;
    }

    return 0;
}

/*
Задача 7. Пупырка

После посылки из Китая осталась спец. плёнка для бережной перевозки груза — пупырка.
Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька — это всегда либо он целый, либо нет, т.е. true или false (тип массива bool).
Для начала, требуется реализовать отдельную функцию инициализации пупырки начальным состоянием — полностью целая пупырка, т.е. все элементы true.
Но это только самое начало.

Программа заключается в последовательном лопанье целых регионов пузырьков.
Перед каждым таким лопаньем надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый.
Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопанье.
Пользователь вводит две координаты: координаты начала региона и конца прямоугольного региона.
Сама процедура лопанья пузырей должна быть реализована с помощью отдельной функции, все аргументы должны проверяться на их валидность,
что они в в рамках диапазона возможных значений — иначе должна быть выведена ошибка.
После лопанья каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

Лопанье должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает выполнение.
В принципе, вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, т.к. она выполняется после каждого лопанья.
 */