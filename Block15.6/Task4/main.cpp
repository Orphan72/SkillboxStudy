#include <iostream>
#include <vector>

int main()
{
    std::vector <int> vect = {-100,-50, -5, 1, 10, 15};
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.size() - 1; j++)
        {
            if (vect [j] < 0)
            {
                if (vect [j + 1] < 0)
                {
                    //case 1
                    if (vect [j] < vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
                else if (vect [j + 1] >= 0)
                {
                    //case 2
                    if (-vect [j] > vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
            }

            else if (vect [j] >= 0)
            {
                if (vect [j + 1] < 0)
                {
                    //case 3
                    if (vect [j] > -vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
                else if (vect [j + 1] >= 0)
                {
                    //case 4
                    if (vect [j] > vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect [i] << " ";
    }

    return 0;
}


/*
Задача 4

Вам даётся массив целых чисел, отсортированных по возрастанию.
Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел

Пример:

Массив {-100,-50, -5, 1, 10, 15}

Вывод: 1, -5, 10, 15, -50, -100

Задание со звёздочкой: оптимизировать решение четвёртой задачи, чтобы оно совершало как можно меньше операций
 */