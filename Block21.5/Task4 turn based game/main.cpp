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

void showListEnemies (std::vector <character> enms)
{
    std::cout << "LIST ENEMIES\n";
    for (int i = 0; i < enms.size(); i++)
    {
        std::cout << enms[i].name << " ID " << enms[i].id << std::endl;
    }
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

    if (array [enm.pos.coordX][enm.pos.coordY] == 'E')
    {
           std::cout << "BUSY!!" << std::endl;
            enm.pos = enm.previosPos;
            displayCharacter(gamer);
    }


    array [enm.pos.coordX][enm.pos.coordY] = 'E';
    return false;
}

bool moveCharacter (char array [SIZE][SIZE], character &gmr, std::vector <character> &enms)
{
    array [gmr.pos.coordX][gmr.pos.coordY] = '*';

    //array [gamer.previosPos.coordX][gamer.previosPos.coordY] = '*';
    if (array[gmr.previosPos.coordX][gmr.previosPos.coordY] == 'E')
    {
        array[gmr.previosPos.coordX][gmr.previosPos.coordY] = 'E';
    }

    gmr.previosPos = gmr.pos;

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
    gmr.previosPos = gmr.pos;
    std::cin >> cmd;

    if (cmd == 'l')      gmr.pos.coordY--;
    else if (cmd == 'r') gmr.pos.coordY++;
    else if (cmd == 't') gmr.pos.coordX--;
    else                 gmr.pos.coordX++;

    if (gmr.pos.coordY < 0 || gmr.pos.coordY == SIZE ||
        gmr.pos.coordX < 0 || gmr.pos.coordX == SIZE)
        gmr.pos = gmr.previosPos;

    if (array [gmr.pos.coordX][gmr.pos.coordY] == 'E')
    {
        character enm = getEnemy(gmr, enms);
        int num = getNumber (enm, enms);

        std::cout << "=================" << std::endl;
        std::cout << "You attack " << enm.name << std::endl;
        std::cout << "=================" << std::endl;
        attack(enm, gmr.damage);
        enms[num] = enm;

        if (enms[num].health)
        {
            std::cout << "DRAW " << std::endl;
            gmr.pos = gmr.previosPos;
            displayCharacter(enms[num]);
        }
        else
        {
            std::cout << enms[num].name << " was killed " << std::endl;

            enms.erase(enms.begin() + num);

            showListEnemies(enms);
            if (enms.empty())
            {
                std::cout << "LIST EMPTY\n";
                return true;
            }
        }
    }
    array [gmr.pos.coordX][gmr.pos.coordY] = 'P';
    return false;
}


void saveCharacter (std::ofstream & file, character & person)
{
    file.write ((char*) & person.id, sizeof (person.id));

    int len = person.name.length();
    file.write ((char *)& len, sizeof (len));
    file.write ((char *) person.name.c_str(), len);

    file.write ((char*) & person.health, sizeof (person.health));
    file.write ((char*) & person.armor, sizeof (person.armor));
    file.write ((char*) & person.damage, sizeof (person.damage));
    file.write ((char*) & person.pos.coordX, sizeof (person.pos.coordX));
    file.write ((char*) & person.pos.coordY, sizeof (person.pos.coordY));
    std::cout << "=Save succefuly=\n";
}


void loadCharacter (std::ifstream &file, character & person)
{
    file.read ((char*) & person.id, sizeof (person.id));
    int len = 0;
    file.read ((char*) & len, sizeof (len));
    person.name.resize(len);
    file.read((char*) person.name.c_str(), len);

    file.read ((char*) & person.health, sizeof (person.health));
    file.read ((char*) & person.armor, sizeof (person.armor));
    file.read ((char*) & person.damage, sizeof (person.damage));
    file.read ((char*) & person.pos.coordX, sizeof (person.pos.coordX));
    file.read ((char*) & person.pos.coordY, sizeof (person.pos.coordY));
}

//void loadGame (char array [SIZE][SIZE], character &gmr, std::vector <character> &enms)
void loadGame (char (&array) [SIZE][SIZE], character &gmr, std::vector <character> &enms)
//void ShowData(int(&arr)[N]);
{
    std::ifstream memoryFrom("..\\data\\memory.bin", std::ios::binary);
    character enemy;
    if (memoryFrom.is_open())
    {
        std::cout << "ENEMIES LOADING...\n";
        int countEnemy = 0;
        memoryFrom.read((char *) &countEnemy, sizeof(countEnemy));
        std::cout << "countEnemy = " << countEnemy << std::endl;

        for (int i = 0; i < countEnemy; i++)
        {
            loadCharacter(memoryFrom, enemy);
            enms.push_back(enemy);
            array[enms[i].pos.coordX][enms[i].pos.coordY] = 'E';
            enms[i].previosPos = enms[i].pos;

        }

        std::cout << "ENEMIES LOADED SUCCESFUL\n";

        for (int i = 0; i < enms.size(); i++)
        {
            displayCharacter(enms[i]);
        }

        displayField(array);

        std::cout << "CHARACTER LOADING...\n";

        loadCharacter(memoryFrom, gmr);

        array[gmr.pos.coordX][gmr.pos.coordY] = 'P';
        gmr.previosPos = gmr.pos;

        std::cout << "CHARACTER LOADED SUCCESFUL\n";

        displayField(array);
    }
    else
    {
        std::cout << "=The data is not available for writing=\n";
    }
    memoryFrom.close();
}




void saveGame (character &gmr, std::vector <character> &enms)
{
    std::ofstream memoryTo ("..\\data\\memory.bin", std::ios::binary);
    if (memoryTo.is_open())
    {
        std::cout << "SAVING ENEMIES....\n";
        int countEnemies = enms.size();
        memoryTo.write ((char*) & countEnemies, sizeof (countEnemies));
        for (int i = 0; i < enms.size(); i++)
        {
            saveCharacter (memoryTo, enms[i]);
        }
        std::cout << "ENEMIES SAVED SUCCESFUL\n";
        std::cout << "SAVING CHARACTER....\n";

        saveCharacter (memoryTo, gmr);

        std::cout << "CHARACTER SAVED SUCCESFUL\n";
    }
    else
    {
        std::cout << "=The data is not available for reading=\n";
    }
    memoryTo.close();
}







int main()
{
    std::srand(std::time(nullptr));
    char field [SIZE][SIZE];

    bool gameOver = false;
    std::vector <character> enemies;
    character gamer;

    char cmdSafeLoad = ' ';


    setupField (field);


    std::cout << "Press \'n\' for new game or \'l\' for loading game\n=>";
    std::cin >> cmdSafeLoad;



    if (cmdSafeLoad == 'l')
    {
        loadGame(field, gamer, enemies);
    }
    else if (cmdSafeLoad == 'n')
    {
        createEnemies (field, enemies);

        showListEnemies(enemies);

        for (int i = 0; i < enemies.size(); i++)
        {
            displayCharacter (enemies[i]);
        }
        displayField (field);
        createGamer (field, gamer);
        displayField (field);
    }

    while (!gameOver)
    {
        std::cout << "Enter \'s\' for safing or \'l\' for loading game\nEnter \'e\' for exit\n=>";
        std::cin >> cmdSafeLoad;
        if (cmdSafeLoad == 's')
        {
            saveGame (gamer, enemies);
           /*
            std::ofstream memoryTo ("..\\data\\memory.bin", std::ios::binary);
            if (memoryTo.is_open())
            {
                std::cout << "SAVING ENEMIES....\n";
                int countEnemies = enemies.size();
                memoryTo.write ((char*) & countEnemies, sizeof (countEnemies));
                for (int i = 0; i < enemies.size(); i++)
                {
                    saveCharacter (memoryTo, enemies[i]);
                }
                std::cout << "ENEMIES SAVED SUCCESFUL\n";
                std::cout << "SAVING CHARACTER....\n";

                saveCharacter (memoryTo, gamer);

                std::cout << "CHARACTER SAVED SUCCESFUL\n";
            }
            else
            {
                std::cout << "=The data is not available for reading=\n";
            }
            memoryTo.close();
            */
        }
        else if (cmdSafeLoad == 'l')
        {
            setupField (field);
            displayField (field);
            enemies.clear();
            loadGame(field, gamer, enemies);









           // loadGame(field, gamer, enemies);
        }
        else if (cmdSafeLoad == 'e')
        {
            gameOver = true;
            std::cout << "EXIT";
            break;
        }

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