#include <iostream>
#include <vector>

const int SIZE = 12;
const int DELTA = 2;
const int SEA = 9;
const int MAXCOUNTSHIP = 4;

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


//СЮДА МОЖНО ПЕРЕДАТЬ ГЛОБАЛЬНУЮ ПЕРЕМЕННУЮ MAXCOUNTSHIP вмместо cntShp
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
    }
}
/*
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
*/

void drawEmpty ()
{
    for (int i = 0; i < SIZE*2; i++)
    {
        std::cout << std::endl;
    }
}

bool shoot (char arr1 [SIZE][SIZE], char arr2 [SIZE][SIZE])
{
    int ver, hor;
    std::cin >> ver >> hor;
    ver += DELTA;
    hor += DELTA;
    if (arr1 [ver][hor] == 'O')
    {
        arr2 [ver][hor] = 'X';
        std::cout << "GOAL!!!";
        return true;
    }
    else
    {
        arr2 [ver][hor] = '*';
        std::cout << "MISSED\n";
        return false;
    }
}

int main()
{
    const int MAXDESK = 4;


    char field1 [SIZE][SIZE];
    char field2 [SIZE][SIZE];
    char field2For1 [SIZE][SIZE];
    char field1For2 [SIZE][SIZE];

    int countAllDesk1 = 20;
    int countAllDesk2 = 20;

    setupSea (field1);
    setupSea (field2);
    setupSea (field2For1);
    setupSea (field1For2);

    display (field1);
    std::cout << "Player 1, set your ships\n ";

    for (int desk = 1, countShip = 4; desk <= MAXDESK; desk++)
    {
        setupShip(field1, desk, countShip);
        countShip--;
    }

        //tempSetup (field1, MAXDESK);
    display (field1);
    std::cout << "Player 1, all your ships have been set\n ";
    drawEmpty();

    display (field2);
    std::cout << "Player 2, set your ships\n ";



    ///ОСТАНОВИЛСЯ ЗДЕСЬ



    tempSetup (field2, MAXDESK);
    display (field2);
    std::cout << "Player 2, all your ships have been set\n ";
    drawEmpty();

    while (countAllDesk1 > 0 &&  countAllDesk2 > 0)
    {
        std::cout << "Player 1, your turn\n ";
        if (shoot(field2, field2For1))
            countAllDesk2--;

        std::cout << "Player 1, see field of player 2\n ";
        display (field2For1);
        if (!countAllDesk2) break;

        std::cout << "Player 2, your turn\n ";
        if (shoot(field1, field1For2))
            countAllDesk1--;

        std::cout << "Player 2, see field of player 1\n ";
        display (field1For2);
        if (!countAllDesk1) break;
    }

    if (countAllDesk2 == 0)
        std::cout << "Player1 won!";
    else
        std::cout << "Player2 won!";

    return 0;
}
