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

void setupShip (char array [SIZE][SIZE], int dsk, int cntShp)
{
   for (int n = 0; n < cntShp; n++)
   {
       char position = ' ';
       if (dsk != 1)
       {
           bool correctPos = false;
           while (!correctPos)
           {
               std::cout << "Enter ship's position (V or H)\n=>";
               std::cin >> position;
               correctPos = (position == 'V' || position == 'H');
               if (!correctPos)
                   std::cout << "Position incorrect, please try again\n";
           }
       }
       else
       {
           position = 'V';
       }


       bool correctCoordinates = false;

       while (!correctCoordinates)
       {
           std::cout << "Enter coordinates ship =>";
           int horisontal, vertical;
           std::cin >> horisontal >> vertical;
           correctCoordinates = (horisontal >= 0 && vertical >= 0 &&
                                 horisontal <= 9 && vertical <= 9);
           if (!correctCoordinates)
           {
               
           }
       }





       int i = horisontal + DELTA;
       int j = vertical + DELTA;

       if (position == 'V')
       {
           for (; i < (horisontal + DELTA + dsk); i++)
           {
               array[i][j] = 'O';
           }
       }
       else if (position == 'H')
       {
           for (; j < (vertical + DELTA + dsk); j++) {
               array[i][j] = 'O';
           }
       }

       display(array);
   }
}

int main()
{
    const int DIFF = 46;
    const int MAXDESK = 4;

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
        field1 [i][0] = char (i + DIFF);
        field2 [i][0] = char (i + DIFF);

        for (int j = DELTA; j < SIZE; j++)
        {
            field1 [0][j] = char (j + DIFF);
            field2 [0][j] = char (j + DIFF);
            field1 [i][j] = '~';
            field2 [i][j] = '~';
        }
    }

    display (field1);

    //setup flot
    for (int desk = 1, countShip = 4; desk <= MAXDESK; desk++)
    {
        setupShip(field1, desk, countShip);
        countShip--;
    }
    return 0;
}
