#include <iostream>
#include <vector>

const int SIZE = 12;
const int DELTA = 2;
const int SEA = 9;
const int DIFF = 46;

void setupSea (char array [SIZE][SIZE])
{
    array [0][0] = ' ';
    for (int i = 0; i < SIZE; i++)
    {
        array[i][1] = '|';
    }
    for (int j = 0; j < SIZE; j++)
    {
        array [1][j] = '-';
    }

    for (int i = DELTA; i < SIZE; i++)
    {
        array [i][0] = char(i + DIFF);
        for (int j = DELTA; j < SIZE; j++)
        {
            array [0][j] = char(j + DIFF);
            array[i][j] = '~';
        }
    }
}

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
    if (v < 0 || h < 0 || v > SEA || h > SEA)
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

      //  display(array);
    }
}


void tempSetup (char array [SIZE][SIZE], int dsk)
{

    int vertical, horizontal;

    std::cout << "Enter coordinates ";
    std::cin >> vertical >> horizontal;

    int i = vertical + DELTA;
    int j = horizontal + DELTA;

    for (; i < (vertical + DELTA + dsk); i++) {
        array[i][j] = 'O';
    }

}

void drawEmpty ()
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::endl;
    }
}


void shoot (char arr1 [SIZE][SIZE], char arr2 [SIZE][SIZE])
{
    int ver, hor;

    std::cin >> ver >> hor;

    ver += DELTA;
    hor += DELTA;
    if (arr1 [ver][hor] == 'O')
    {
        arr2 [ver][hor] = 'X';
        display(arr2);
        std::cout << "Popal";
    }
    else
    {
        arr2 [ver][hor] = '*';
        display(arr2);
        std::cout << "Mimo";
    }



}









int main()
{
    const int MAXDESK = 4;
    char field1 [SIZE][SIZE];
    char field2 [SIZE][SIZE];
    char field2For1 [SIZE][SIZE];
    char field1For2 [SIZE][SIZE];

    setupSea (field1);
    setupSea (field2);
    setupSea (field2For1);
    setupSea (field1For2);

    display (field1);
    std::cout << "Player 1, set your ships\n ";
    tempSetup (field1, MAXDESK);
    display (field1);
    std::cout << "Player 1, all your ships have been set\n ";
    system("pause");
    drawEmpty();

    display (field2);
    std::cout << "Player 2, set your ships\n ";
    tempSetup (field2, MAXDESK);
    display (field2);
    std::cout << "Player 2, all your ships have been set\n ";
    system("pause");
    drawEmpty();


//    int ver, hor;




    std::cout << "Player 1, your turn\n ";
    shoot (field2, field2For1);

    std::cout << "Player 2, your turn\n ";
    shoot (field1, field1For2);

/*

    std::cin >> ver >> hor;

    ver += DELTA;
    hor += DELTA;
    if (field2 [ver][hor] == 'O')
    {
        field2For1[ver][hor] = 'X';
        display(field2For1);
        std::cout << "Popal";
    }
    else
    {
        std::cout << "Mimo";
    }

*/
/*
    std::cout << "Player 2, your turn\n ";
    std::cin >> ver >> hor;

    ver += DELTA;
    hor += DELTA;
    if (field1 [ver][hor] == 'O')
    {
        field1For2[ver][hor] = 'X';
        display(field1For2);
        std::cout << "Popal";
    }
    else
    {
        std::cout << "Mimo";
    }

  */













    return 0;
}
