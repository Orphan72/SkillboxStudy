#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>





const int SIZE = 10;
const int ENEMYCOUNT = 3;

const int MINHEALTH = 50;
const int MAXHEALTH = 100;

const int MINARMOR = 0;
const int MAXARMOR = 50;

const int MINDAMAGE = 15;
const int MAXDAMAGE = 30;

enum direction
{
    LEFT,
    RIGHT,
    TOP,
    BUTTON,
    LAST
};

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
    position previosPos;
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

void createEnemies (char array [SIZE][SIZE], std::vector <character> &enms)
{
    for (int i = 0; i < ENEMYCOUNT; i++)
    {
        character enemy;
        bool correctPosition = false;
        std::string strName = "Enemy #";
        enemy.id = i + 1;
        enemy.name = strName + std::to_string (enemy.id);

        int diffHealth = MAXHEALTH - MINHEALTH;
        enemy.health = std::rand()%(diffHealth + 1) + MINHEALTH;

        int diffArmor = MAXARMOR - MINARMOR;
        enemy.armor = std::rand()%(diffArmor + 1) + MINARMOR;

        int diffDamage = MAXDAMAGE - MINDAMAGE;
        enemy.damage = std::rand()%(diffDamage + 1) + MINDAMAGE;

        while (!correctPosition)
        {
            enemy.pos.coordX = std::rand()%SIZE;
            enemy.pos.coordY = std::rand()%SIZE;

            if (array [enemy.pos.coordX][enemy.pos.coordY] == '*')
            {
                correctPosition = true;
            }
        }

        array [enemy.pos.coordX][enemy.pos.coordY] = 'E';
        enms.push_back(enemy);
    }
}

void createGamer (char array [SIZE][SIZE], character &gmr)
{
    bool correctPosition = false;
    std::cout << "Set your character's options:\n";
    std::cout << "Enter the Name\n=>";
    std::cin >> gmr.name;
    std::cout << "Enter health\n=>";
    std::cin >> gmr.health;
    std::cout << "Enter armor\n=>";
    std::cin >> gmr.armor;
    std::cout << "Damage\n=>";
    std::cin >> gmr.damage;

    while (!correctPosition)
    {
        std::cout << "Enter vertical's value, from 1 to " << SIZE << "\n=>";
        std::cin >> gmr.pos.coordX;
        std::cout << "Enter horisontal's value, from 1 to " << SIZE << "\n=>";
        std::cin >> gmr.pos.coordY;

        if (array [gmr.pos.coordX][gmr.pos.coordY] == '*')
        {
            correctPosition = true;
        }
        else  std::cout << "This position is occupied. Try again\n=>";
    }

    array [gmr.pos.coordX][gmr.pos.coordY] = 'P';
    gmr.previosPos = gmr.pos;
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

character getEnemy (character &person, std::vector <character> enm)
{
    for (int i = 0; i < enm.size(); i++)
    {
        if (person.pos.coordX == enm[i].pos.coordX &&
            person.pos.coordY == enm[i].pos.coordY)
        {
           return enm[i];
        }
    }
}

void attack (character &person, int dmg)
{
    person.armor -= dmg;
    if (person.armor < 0)
    {
        person.health += person.armor;
        person.armor = 0;
    }
    if (person.health < 0)
    {
        person.health = 0;
    }
}

void showEnemies (std::vector <character> enms)
{
    std::cout << "LIST ENEMIES\n";
    for (int i = 0; i < enms.size(); i++)
    {
        std::cout << enms[i].name << " ID " << enms[i].id << std::endl;
    }
}

void delElement (std::vector<character> &enms, int nm)
{
    for (int i = nm; i < enms.size(); i++)
    {
        enms [i] = enms [i+1];
    }
    enms.pop_back();
}

int getNumber (character enm, std::vector<character> enms)
{
    for (int i = 0; i < enms.size(); i++)
    {
        if (enm.id == enms[i].id) return i;
    }
}

bool moveEnemy (char array [SIZE][SIZE], character &enm, character &gamer)
{
    array [enm.pos.coordX][enm.pos.coordY] = '*';

    if (array[enm.previosPos.coordX][enm.previosPos.coordY] == 'P')
    {
        array[enm.previosPos.coordX][enm.previosPos.coordY] = 'P';
    }
    else
    {
        array [enm.previosPos.coordX][enm.previosPos.coordY] = '*';
    }

    enm.previosPos = enm.pos;

    std::cout << enm.name << "turn\n=>";

    std::cout << "Enter one of next commands  :\n- \'l (left)\'\n- \'r (right)\'\n- \'t (top)\'\n- \'b (button)\'\n=>";
    char cmd = ' ';
    std::cin >> cmd;

    if (cmd == 'l')      enm.pos.coordY--;
    else if (cmd == 'r') enm.pos.coordY++;
    else if (cmd == 't') enm.pos.coordX--;
    else                 enm.pos.coordX++;

    if (enm.pos.coordY < 0 || enm.pos.coordY == SIZE ||
        enm.pos.coordX < 0 || enm.pos.coordX == SIZE)
        enm.pos = enm.previosPos;
    /*

    int cmd = rand ()% (LAST);

    if (cmd == LEFT)        enm.pos.coordY--;
    else if (cmd == RIGHT)  enm.pos.coordY++;
    else if (cmd == TOP)    enm.pos.coordX--;
    else                    enm.pos.coordX++;

    */

    if (array [enm.pos.coordX][enm.pos.coordY] == 'P')
    {
        std::cout << "=================" << std::endl;
        std::cout << enm.name << "Attack you!!! " << std::endl;
        std::cout << "=================" << std::endl;
        attack(gamer, enm.damage);

        if (gamer.health)
        {
            std::cout << "DRAW " << std::endl;
            enm.pos = enm.previosPos;
            displayCharacter(gamer);
        }
        else
        {
            array [gamer.pos.coordX][gamer.pos.coordY] = 'E';
            return true;
        }
    }
        array [enm.pos.coordX][enm.pos.coordY] = 'E';
        return false;
}

bool moveCharacter (char array [SIZE][SIZE], character &gamer, std::vector <character> &enms)
{
    array [gamer.pos.coordX][gamer.pos.coordY] = '*';

    array [gamer.previosPos.coordX][gamer.previosPos.coordY] = '*';
    if (array[gamer.previosPos.coordX][gamer.previosPos.coordY] == 'E')
    {
        array[gamer.previosPos.coordX][gamer.previosPos.coordY] = 'E';
    }

    gamer.previosPos = gamer.pos;

    char cmd = ' ';
    //  bool correctAnswer = false;
/*
    while (!correctAnswer)
    {
        std::cout << "Enter one of next commands:\n- \'l (left)\'\n- \'r (right)\'\n- \'t (top)\'\n- \'b (button)\'\n=>";
        std::cin >> cmd;
        correctAnswer = (cmd == 'l' || cmd == 'r'
                      || cmd == 't'  || cmd == 'b');
        if (!correctAnswer)
        {
            std::cout << "Answer incorrect. Try again\n";
            array [gamer.pos.coordX][gamer.pos.coordY] = 'P';
            displayField (array);
        }
        else
            array [gamer.pos.coordX][gamer.pos.coordY] = '*';
    };
*/
    std::cout << "Your turn\n";
    std::cout << "Enter one of next commands:\n- \'l (left)\'\n- \'r (right)\'\n- \'t (top)\'\n- \'b (button)\'\n=>";
    gamer.previosPos = gamer.pos;
    std::cin >> cmd;

    if (cmd == 'l')      gamer.pos.coordY--;
    else if (cmd == 'r') gamer.pos.coordY++;
    else if (cmd == 't') gamer.pos.coordX--;
    else                 gamer.pos.coordX++;

    if (gamer.pos.coordY < 0 || gamer.pos.coordY == SIZE ||
        gamer.pos.coordX < 0 || gamer.pos.coordX == SIZE)
        gamer.pos = gamer.previosPos;

    if (array [gamer.pos.coordX][gamer.pos.coordY] == 'E')
    {
        character enm = getEnemy(gamer, enms);
        int num = getNumber (enm, enms);

        std::cout << "=================" << std::endl;
        std::cout << "You attack " << enm.name << std::endl;
        std::cout << "=================" << std::endl;
        attack(enm, gamer.damage);
        enms[num] = enm;

        if (enms[num].health)
        {
            std::cout << "DRAW " << std::endl;
            gamer.pos = gamer.previosPos;
            displayCharacter(enms[num]);
        }
        else
        {
            std::cout << enms[num].name << " was killed " << std::endl;
            delElement (enms, num);
            showEnemies (enms);
            if (enms.empty())
            {
                std::cout << "LIST EMPTY\n";
                return true;
            }
        }
    }
    array [gamer.pos.coordX][gamer.pos.coordY] = 'P';
    return false;
}

int main()
{
   // std::srand(std::time(nullptr));
    char field [SIZE][SIZE];

    bool gameOver = false;
    std::vector <character> enemies;

    character gamer;
    setupField (field);
    createEnemies (field, enemies);

    std::ifstream memoryFrom ("..\\data\\memory.bin", std::ios::binary);

    showEnemies (enemies);

    for (int i = 0; i < enemies.size(); i++)
    {
        displayCharacter (enemies[i]);
    }

    displayField (field);

    createGamer (field, gamer);
    displayField (field);

    while (!gameOver)
    {
        gameOver = moveCharacter (field, gamer, enemies);
        displayField (field);
        if (gameOver)
        {
            std::cout << "You won!! \n";
            break;
        }

        for (int i = 0; i < enemies.size(); i++)
        {
            gameOver = moveEnemy (field, enemies[i], gamer);
            displayField (field);
            if (gameOver)
            {
                std::cout << "You lose\n";
                break;
            }
        }
    }

    return 0;
}
