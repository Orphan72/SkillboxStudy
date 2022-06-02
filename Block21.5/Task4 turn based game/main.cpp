#include <iostream>
#include <vector>
#include <ctime>



//Уровень жизней врагам задаётся случайно — от 50 до 150.
//Уровень брони варьируется от 0 до 50.
//Урон тоже выбирается случайно — от 15 до 30 единиц.


//TODO 21.3 Работа со структурами пересмотреть

const int SIZE = 10;
const int ENEMYCOUNT = 2;

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
    int id = 0;
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
        enemy.id = i + 1;
        enemy.name = strName + std::to_string (enemy.id);

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

void displayField (char array [SIZE][SIZE])
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

void displayCharacter (character &person)
{
    if (!person.health)
    {
        std::cout << person.name << " is dead" << std::endl;
    }
    else
    {
        std::cout << person.name << std::endl;
        std::cout << "Health: " << person.health << std::endl;
        std::cout << "Armor: " << person.armor << std::endl;
        std::cout << "Damage: " << person.damage << std::endl;
        std::cout << person.pos.coordX << " " << person.pos.coordY << std::endl;
    }
}

int detectID (character &person, std::vector <character> enm)
{
    for (int i = 0; i < enm.size(); i++)
    {
        if (person.pos.coordX == enm[i].pos.coordX &&
            person.pos.coordY == enm[i].pos.coordY)
        {
            return enm[i].id;
        }
    }
}

void moveCharacter (char array [SIZE][SIZE], character &person, std::vector <character> enm)
{
    array [person.pos.coordX][person.pos.coordY] = '*';

    char cmd = ' ';
    bool correctAnswer = false;

    while (!correctAnswer)
    {
        std::cout << "Enter one of next commands:\n- \'l (left)\'\n- \'r (right)\'\n- \'t (top)\'\n- \'b (button)\'\n=>";
        std::cin >> cmd;
        correctAnswer = (cmd == 'l' || cmd == 'r'
                      || cmd == 't'  || cmd == 'b');
        if (!correctAnswer)
        {
            std::cout << "Answer incorrect. Try again\n";
            array [person.pos.coordX][person.pos.coordY] = 'P';
            displayField (array);
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

    if (array [person.pos.coordX][person.pos.coordY] == 'E')
    {

        int ID = detectID (person, enm);
        std::cout << "You atacked ENEMY # " << ID << std::endl;

        //takeDamage (character &person, int dmg
    }

    array [person.pos.coordX][person.pos.coordY] = 'P';

  //  if ()


}

// определения ID врага



void takeDamage (character &person, int dmg)
{
    std::cout << person.name << " took damage: -" << dmg << std::endl;
    person.armor -= dmg;
    if (person.armor < 0)
    {
        person.health += person.armor;
        person.armor = 0;
    }
    if (person.health < 0)
    {
        person.health = 0;
        std::cout << person.name << " died" << std::endl;

    }
}


int main()
{
    //std::srand(std::time(nullptr));
    char field [SIZE][SIZE];
    std::vector <character> enemies;

    character gamer;
    setupField (field);

    createEnemies (field, enemies);

    std::cout << "enemies.size() is " << enemies.size() << std::endl;
    for (int i = 0; i < enemies.size(); i++)
    {
        displayCharacter (enemies[i]);
    }

    displayField (field);

    //if ()


    createGamer (field, gamer);
    displayField (field);
    for (int i = 0; i < 10; i++)
    {
        moveCharacter (field, gamer, enemies);
        displayField (field);
    }

    return 0;
}
