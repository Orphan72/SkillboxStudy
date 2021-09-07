#include <iostream>
#include <vector>

const int SIZE = 3;

void display (std::vector <bool> vec [SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < vec[i][j].size(); k++)
            {
                std::cout << vec[i][j][k] << " ";
            }

            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void slice (std::vector <bool> vec [SIZE][SIZE], int k)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << vec[i][j][k] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int maxHight = 10;
    std::vector <bool> sector [SIZE][SIZE];
    int hightPillar = 0;
    int hightSlice  = 0;

    int l = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << "Enter hight of " << i + j + l + 1 << " pillar=>";
            std::cin >> hightPillar;
            for (int k = 0; k < hightPillar; k++)
            {
                sector[i][j].push_back(true);
            }
        }
        l += SIZE - 1;
    }

display (sector);

    while (hightSlice != -2)
    {
        std::cout << "Enter hight of slice \n=>";
        std::cin >> hightSlice;
        slice(sector, hightSlice - 1);
    }

    return 0;
}

/*
Задача 8. Почти-Майнкрафт

Нам всё-таки предстоит сделать некое подобие Майнкрафта. Миллионов не обещаю, но это довольно интересная задача на пространственное мышление.
У нас есть небольшой квадратный ландшафт, размером 5х5 секторов. В каждом секторе располагается блок (столбик) ландшафта,
максимальная высота которого — это 10 блоков. Текущая высота каждого такого блока задаётся пользователем вначале программы.
Итоговая задача — используя трёхмерный массив вывести в стандартный вывод горизонтальное сечение (или горизонтальный срез) нашего небольшого мира.
Сам мир как раз должен быть представлен в виде трёхмерного массива. Его горизонтальный срез стало быть — это двумерный массив,
который надо отобразить в виде единиц и нулей. 0 — это отсутствие элемента на данном уровне в данной точке, 1 — элемент есть.
Уровень среза от 0 до 9 включительно — также задаётся в стандартном вводе.

*/