#include <iostream>
#include <vector>

const int SIZE = 10;
const int ENEMYCOUNT = 3;
const int CHARDIFF = 49;

struct location
{
    int coordX = 0;
    int coordY = 0;
};

struct character
{
    std::string name = "noname";
    int health = 0;
    int armor = 0;
    int damage = 0;
    location lctn;
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

void createGamer (char array [SIZE][SIZE], character &gmr)
{
    std::cout << "Set your character's options:\n";
    std::cout << "Enter the Name\n=>";
    std::cin >> gmr.name;
    std::cout << "Enter horisontal's value, from 1 to 40\n=>";
    std::cin >> gmr.lctn.coordY;
    std::cout << "Enter vertical's value, from 1 to 40\n=>";
    std::cin >> gmr.lctn.coordX;
    array [gmr.lctn.coordX][gmr.lctn.coordY] = 'P';
}

void createEnemies (char array [SIZE][SIZE], std::vector <character> &ems)
{
    for (int i = 0; i < ENEMYCOUNT; i++)
    {
        character enemy;
        char enemyNumner;
        std::string strName = "Enemy #";
        enemyNumner = (char)(i + CHARDIFF);
        enemy.name = strName + enemyNumner;
        enemy.lctn.coordX = i;
        enemy.lctn.coordY = i + 2;
        array [enemy.lctn.coordX][enemy.lctn.coordY] = 'E';
        ems.push_back(enemy);
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

void moveCharacter (char array [SIZE][SIZE], character &chrct)
{
    array [chrct.lctn.coordX][chrct.lctn.coordY] = '*';
    std::string cmd = " ";
    bool correctAnswer = false;
    while (!correctAnswer)
    {
        std::cout << "Enter one of next commands:\n- '\left\'\n- \'right\'\n- \'top\'\n- \'button\'\n=>";
        std::cin >> cmd;
        correctAnswer = (cmd == "left" || cmd == "right"
                      || cmd == "top"  || cmd == "button");
        if (!correctAnswer)
        {
            std::cout << "Answer incorrect. Try again\n";
            array [chrct.lctn.coordX][chrct.lctn.coordY] = 'P';
            display (array);
        }
        else
            array [chrct.lctn.coordX][chrct.lctn.coordY] = '*';
    };
    if (cmd == "left")
    {
        chrct.lctn.coordY--;
    }
    else if (cmd == "right")
    {
        chrct.lctn.coordY++;
    }
    else if (cmd == "top")
    {
        chrct.lctn.coordX--;
    }
    else
    {
        chrct.lctn.coordX++;
    }
    array [chrct.lctn.coordX][chrct.lctn.coordY] = 'P';
}


int main()
{
    char field [SIZE][SIZE];
    std::vector <character> enemies;

    character gamer;
    setupField (field);

    createEnemies (field, enemies);
    for (int i = 0; i < ENEMYCOUNT; i++)
    {
        std::cout << enemies[i].name << std::endl;
        std::cout << enemies[i].lctn.coordX << " " << enemies[i].lctn.coordY << std::endl;
    }

    display (field);

    createGamer (field, gamer);
    display (field);
    for (int i = 0; i < 10; i++)
    {
        moveCharacter (field, gamer);
        display (field);
    }

    return 0;
}
