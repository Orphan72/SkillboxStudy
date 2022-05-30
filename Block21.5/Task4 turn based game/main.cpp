#include <iostream>
#include <vector>
#include <ctime>



//Уровень жизней врагам задаётся случайно — от 50 до 150.
//Уровень брони варьируется от 0 до 50.
//Урон тоже выбирается случайно — от 15 до 30 единиц.


//TODO 21.3 Работа со структурами пересмотреть

const int SIZE = 10;
const int ENEMYCOUNT = 3;

const int MINHEALTH = 50;
const int MAXHEALTH = 100;

const int MINARMOR = 0;
const int MAXARMOR = 50;

const int MINDAMAGE = 15;
const int MAXDAMAGE = 30;

struct position
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
    position pos;
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
    std::cin >> gmr.pos.coordY;
    std::cout << "Enter vertical's value, from 1 to 40\n=>";
    std::cin >> gmr.pos.coordX;
    array [gmr.pos.coordX][gmr.pos.coordY] = 'P';
}

void createEnemies (char array [SIZE][SIZE], std::vector <character> &ems)
{
    for (int i = 0; i < ENEMYCOUNT; i++)
    {
        character enemy;
        std::string strName = "Enemy #";
        enemy.name = strName + std::to_string (i + 1);

        int diffHealth = MAXHEALTH - MINHEALTH;
        enemy.health = std::rand()%(diffHealth + 1) + MINHEALTH;

        int diffArmor = MAXARMOR - MINARMOR;
        enemy.armor = std::rand()%(diffArmor + 1) + MINARMOR;

        int diffDamage = MAXDAMAGE - MINDAMAGE;
        enemy.damage = std::rand()%(diffDamage + 1) + MINDAMAGE;

        enemy.pos.coordX = i;
        enemy.pos.coordY = i + 2;
        array [enemy.pos.coordX][enemy.pos.coordY] = 'E';
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

void moveCharacter (char array [SIZE][SIZE], character &person)
{
    array [person.pos.coordX][person.pos.coordY] = '*';
    char cmd = ' ';
    bool correctAnswer = false;
    while (!correctAnswer)
    {
        std::cout << "Enter one of next commands:\n- '\l (left)\'\n- \'r (right)\'\n- \'t (top)\'\n- \'b (button)\'\n=>";
        std::cin >> cmd;
        correctAnswer = (cmd == 'l' || cmd == 'r'
                      || cmd == 't'  || cmd == 'b');
        if (!correctAnswer)
        {
            std::cout << "Answer incorrect. Try again\n";
            array [person.pos.coordX][person.pos.coordY] = 'P';
            display (array);
        }
        else
            array [person.pos.coordX][person.pos.coordY] = '*';
    };
    if (cmd == 'l')
    {
        person.pos.coordY--;
    }
    else if (cmd == 'r')
    {
        person.pos.coordY++;
    }
    else if (cmd == 't')
    {
        person.pos.coordX--;
    }
    else
    {
        person.pos.coordX++;
    }
    array [person.pos.coordX][person.pos.coordY] = 'P';
}

void takeDamage (character &person, int dmg)
{
    std::cout << person.name << " took damage: -" << dmg << std::endl;
    person.armor -= dmg;
    if (person.armor < 0)
    {
        person.health += person.armor;
        person.armor = 0;
    }
}




int main()
{
    std::srand(std::time(nullptr));
    char field [SIZE][SIZE];
    std::vector <character> enemies;

    character gamer;
    setupField (field);

    createEnemies (field, enemies);
    for (int i = 0; i < ENEMYCOUNT; i++)
    {
        std::cout << enemies[i].name << std::endl;
        std::cout << "Health: " << enemies[i].health << std::endl;
        std::cout << "Armor: " << enemies[i].armor << std::endl;
        std::cout << "Damage: " << enemies[i].damage << std::endl;
        std::cout << enemies[i].pos.coordX << " " << enemies[i].pos.coordY << std::endl;
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
