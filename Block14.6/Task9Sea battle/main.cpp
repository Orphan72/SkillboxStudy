#include <iostream>
#include <vector>

const int SIZE = 12;
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


void setupShip (char array [SIZE][SIZE], int dsk)
{
    for (int count = 0; count < dsk; count++)
    {
        std::cout << "Enter coordinates " << count + 1 << " ship =>";
        int horisontal, vertical;
        char position = ' ';
        std::cin >> horisontal >> vertical;
        int i = horisontal + DELTA;
        int j = vertical + DELTA;
        bool correctPos = false;
        while (!correctPos)
       {
            std::cout << "Enter ship's position (V or H)\n=>";
            std::cin >> position;
            correctPos = (position == 'V' || position == 'H');
            if (position == 'V')
            {
                std::cout << "vertical\n";
                for (; i < (horisontal + DELTA + dsk); i++)
                {
                    array[i][j] = 'O';
                }
            }
            else if (position == 'H')
            {
                std::cout << "horisontal\n";
                for (; j < (vertical + DELTA + dsk); j++)
                {
                    array[i][j] = 'O';
                }
            }
            else
               std::cout << "Position incorrect, please try again\n";
       }

       display (array);
    }
}



int main()
{
    const int DIFF = 46;
    //int desk = 3;
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

    int countShip = 4;
    int desk = 2;


    setupShip (field1, desk);
    //setuoFlot

    /*
    std::cout <<  "Entering " << countShip << " " <<  desk <<  "-desk ships.\n";
    setupShip (field1, desk);
    countShip--;
    desk++;

    std::cout <<  "Entering " << countShip << " " <<  desk <<  "-desk ships.\n";
    setupShip (field1, desk);
    countShip--;
    desk++;
     */

    return 0;
}
