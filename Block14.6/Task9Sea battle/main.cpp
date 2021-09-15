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

bool checkCorrectInput (int v, int h, int dsk, char pos)
{
    if (v < 0 || h < 0 || v > 9 || h > 9)
    {
        std::cout << "Coordinates incorrect\n";
        return false;
    }
    else if ((pos == 'V' && (v + DELTA + dsk > SIZE)) ||
             (pos == 'H' && (h + DELTA + dsk > SIZE)))
    {
        std::cout << "The ship is out of the field\n";
        return false;
    }
    else
        return true;
}

void setupShip (char array [SIZE][SIZE], int dsk, int cntShp)
{
    for (int n = 1; n <= cntShp; n++)
    {
        char position = ' ';
        if (dsk != 1)
        {
            bool correctPos = false;
            while (!correctPos)
            {
                std::cout << "Enter position of ";
                std::cout << n << " " << dsk << "-desk ship (V or H)\n=>";
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

        int vertical, horizontal;
        bool correctCoordinates = false;

        while (!correctCoordinates)
        {
            std::cout << "Enter coordinates of ";
            std::cout << n << " " << dsk << "-desk ship from 0 to 9 =>";
            std::cin >> vertical;
            std::cin >> horizontal;
            correctCoordinates = checkCorrectInput (vertical, horizontal, dsk, position);

            if (!correctCoordinates)
            {
                std::cout << "Please try again\n";
            }
            else
            {
                int i = vertical + DELTA;
                int j = horizontal + DELTA;

                if (position == 'V')
                {
                    for (; i < (vertical + DELTA + dsk); i++)
                    {
                        if (array[i][j] == 'O')
                        {
                            std::cout << "BUSY!!!\n";
                            correctCoordinates = false;
                            break;
                        }
                    }

                    if (correctCoordinates)
                    {
                        i = vertical + DELTA;
                        for (; i < (vertical + DELTA + dsk); i++) {
                            array[i][j] = 'O';
                        }
                    }
                }

                else if (position == 'H')
                {

                    for (; j < (horizontal + DELTA + dsk); j++)
                    {
                        if (array[i][j] == 'O')
                        {
                            std::cout << "BUSY!!!\n";
                            correctCoordinates = false;
                            break;
                        }
                    }

                    if (correctCoordinates)
                    {
                        j = horizontal + DELTA;
                        for (; j < (horizontal + DELTA + dsk); j++)
                        {
                            array[i][j] = 'O';
                        }
                    }
                }
           }
            display(array);
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

    //function fo draw


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

    for (int desk = 1, countShip = 4; desk <= MAXDESK; desk++)
    {
        setupShip(field1, desk, countShip);
        countShip--;
    }

    display (field1);
    return 0;
}
