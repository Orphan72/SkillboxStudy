#include <iostream>

const int SIZE = 10;

struct player
{
    int coordX = 0;
    int coordY = 0;
};

void setupField  (char array [SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            array[i][j] = '*';
        }
    }
}

void setupPlayer (char array [SIZE][SIZE], player &gmr)
{
    gmr.coordX = 0;
    gmr.coordY = 0;
    array [gmr.coordX][gmr.coordY] = 'P';
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

void movePlayer (char array [SIZE][SIZE], player &gmr)
{
    array [gmr.coordX][gmr.coordY] = '*';
    std::string cmd = " ";
    std::cout << "Enter command :\n=>";
    std::cin >> cmd;
    if (cmd == "left")
    {
        gmr.coordY--;
    }
    else if (cmd == "right")
    {
        gmr.coordY++;
    }
    else if (cmd == "top")
    {
        gmr.coordX--;
    }
    else
    {
        gmr.coordX++;
    }
    array [gmr.coordX][gmr.coordY] = 'P';

}






int main()
{
    char field [SIZE][SIZE];

    player gamer;
    setupField (field);
    setupPlayer (field, gamer);
    display (field);
    for (int i = 0; i < 10; i++)
    {
        movePlayer (field, gamer);
        display (field);
    }


    return 0;
}
