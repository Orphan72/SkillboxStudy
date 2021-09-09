#include <iostream>
#include <vector>

const int SIZE = 12;
const int DIFF = 46;
const int DELTA = 2;

void display (char array [SIZE][SIZE])
{
    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << array [i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    char field1 [SIZE][SIZE];
    char field2 [SIZE][SIZE];

    field1 [0][0] = ' ';

    for (int i = 0; i < SIZE; i++)
    {
        field1 [i][1] = '|';
        field2 [i][1] = '|';
    }

    for (int j = 0; j < SIZE; j++)
    {
        field1 [1][j] = '-';
        field2 [1][j] = '-';
    }

    for (int i = DELTA; i < SIZE; i++)
    {
        field1 [i][0] = i + DIFF;
        field2 [i][0] = i + DIFF;

        for (int j = DELTA; j < SIZE; j++)
        {
            field1 [0][j] = j + DIFF;
            field2 [0][j] = j + DIFF;
            field1 [i][j] = '*';
            field2 [i][j] = '*';
        }
    }

    display (field1);

  //  std::cout << "Enter coordinates =>";

   // int h, v;

  //  std::cin >> h >> v;

 //   field1 [h + DELTA][v + DELTA] = 'O';

  //  display (field1);

    std::cout << "Enter coordinates =>";

     int h, v;
    std::cin >> h >> v;

    int i = h + DELTA;
    int j = v + DELTA;

    for (; j < (v + DELTA + 4); j++)
    {
        field1 [i][j] = 'O';
    }


    display (field1);
    return 0;
}
