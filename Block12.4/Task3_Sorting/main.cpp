#include <iostream>

int main() {

    float number [15] =  {1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};
    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 14; i++) {
            if (number[i] > number[i+1]) {
                number[i] += number[i+1];
                number[i+1] = number[i] - number[i+1];
                number[i] -= number[i+1];
            }
        }

        for (int i = 0; i < 15; i++)
        {
            std::cout << number [i] << ", ";
        }

        std::cout << std::endl;
        std::cout << "============================\n";



    }




/*
    if (number[1] > number[2]) {
        number[1] += number[2];
        number[2] = number[1] - number[2];
        number[1] -= number[2];
    }
*/
   // std::cout << number[0] << " " << number[1] << " " << number[2] << std::endl;

    /*
    if (number[0] > number[i+1]) {
        number[i] += number[i+1];
        number[i+1] = number[i] - number[i+1];
        number[i] -= number[i+1];
    }

    if (number[0] > number[i+1]) {
        number[i] += number[i+1];
        number[i+1] = number[i] - number[i+1];
        number[i] -= number[i+1];
    }

    if (number[0] > number[i+1]) {
        number[i] += number[i+1];
        number[i+1] = number[i] - number[i+1];
        number[i] -= number[i+1];
    }

    if (number[0] > number[i+1]) {
        number[i] += number[i+1];
        number[i+1] = number[i] - number[i+1];
        number[i] -= number[i+1];
    }

    if (number[0] > number[i+1]) {
        number[i] += number[i+1];
        number[i+1] = number[i] - number[i+1];
        number[i] -= number[i+1];
    }

    if (number[0] > number[i+1]) {
        number[i] += number[i+1];
        number[i+1] = number[i] - number[i+1];
        number[i] -= number[i+1];
    }
    */

    /*
    if (number [1] > number [2])
    {
        swap (number [1], number [2]);
    }

    if (number [3] > number [4])
    {
        swap (number [3], number [4]);
    }

    if (number [3] > number [4])
    {
        swap (number [3], number [4]);
    }

    if (number [3] > number [4])
    {
        swap (number [3], number [4]);
    }

     */



    /*
    Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль
    в порядке от большего к меньшему. По возможности используйте минимум дополнительной памяти и проходов по массиву.

Пример:

Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251

Вывод: 1.11 1.2 1.25 1.251 1.5 1.51 2.3 3.4 5.1 5.11 5.3 5.31 5.4 5.41 5.5

    */




    return 0;
}
