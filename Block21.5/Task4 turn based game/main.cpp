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

enum fightResult
{
    DEFENDWON,
    ATTAKCKWON,
    DRAW
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

void createGamer (char array [SIZE][SIZE], character &gmr)
{
    std::cout << "Set your character's options:\n";
    std::cout << "Enter the Name\n=>";
    std::cin >> gmr.name;

    std::cout << "Enter health\n=>";
    std::cin >> gmr.health;
    std::cout << "Enter armor\n=>";
    std::cin >> gmr.armor;
    std::cout << "Damage\n=>";
    std::cin >> gmr.damage;
    std::cout << "Enter horisontal's value, from 1 to 40\n=>";
    std::cin >> gmr.pos.coordY;
    std::cout << "Enter vertical's value, from 1 to 40\n=>";
    std::cin >> gmr.pos.coordX;
    array [gmr.pos.coordX][gmr.pos.coordY] = 'P';
    gmr.previosPos = gmr.pos;
}

void createEnemies (char array [SIZE][SIZE], std::vector <character> &enms)
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
        enms.push_back(enemy);
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

character detectEnemyName (character &person, std::vector <character> enm)
//int detectEnemyName (character &person, std::vector <character> enm)
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

    }


}

/*
fightResult fighting (character &attackPerson, character &defendPerson)
{
    takeDamage (defendPerson, attackPerson.damage);
    if (!attackPerson.health) return DEFENDWON;
    else if (!defendPerson.health) return ATTAKCKWON;
    else return DRAW;
}
 */


bool moveCharacter (char array [SIZE][SIZE], character &gamer, std::vector <character> &enms)
{
    array [gamer.pos.coordX][gamer.pos.coordY] = '*';
    array [gamer.previosPos.coordX][gamer.previosPos.coordY] = '*';

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

    std::cout << "Enter one of next commands:\n- \'l (left)\'\n- \'r (right)\'\n- \'t (top)\'\n- \'b (button)\'\n=>";
    gamer.previosPos = gamer.pos;
    std::cin >> cmd;

    if (cmd == 'l')
    {
        gamer.pos.coordY--;

    }
    else if (cmd == 'r')
    {
        gamer.pos.coordY++;



    }
    else if (cmd == 't')
    {

        gamer.pos.coordX--;

    }
    else
    {

        gamer.pos.coordX++;



    }




    //bool resultAttack;
    if (array [gamer.pos.coordX][gamer.pos.coordY] == 'E')
    {

        character enm = detectEnemyName(gamer, enms);
        int enmId = enm.id - 1;

        std::cout << "=================" << std::endl;
        std::cout << "You attack " << enm.name << std::endl;
        std::cout << "=================" << std::endl;

        attack(enm, gamer.damage);
        enms[enmId] = enm;

        //fighting (gamer, enm);

        int win;
        std::cout << "Enter winner 0 (Enemy), 1 (draw), 2 (gamer)" << std::endl;
        //std::cin >> win;

        if (win == 0)
        {
            std::cout << enms[enmId - 1].name << " won " << std::endl;
            array [gamer.pos.coordX][gamer.pos.coordY] = 'E';
            std::cout << "Game over " << std::endl;
            return true;
        }

        if (enms[enmId].health)
        {
            std::cout << "DRAW " << std::endl;
            gamer.pos = gamer.previosPos;
            displayCharacter(enms[enmId]);
        }
        else
        {
            std::cout << enms[enmId].name << " was killed " << std::endl;
        }


        /*




        displayCharacter(gamer);
        displayCharacter(enm);
        if (res == ATTAKCKWON) array [gamer.pos.coordX][gamer.pos.coordY] = 'P';
        else if (res == DEFENDWON)
        {
            array [gamer.pos.coordX][gamer.pos.coordY] = 'E';
            //array [gamer.previosPos.coordX][gamer.previosPos.coordY] = '*';
        }


        else if (res = DRAW)
        {
            gamer.pos = gamer.previosPos;
            gamer.previosPos = gamer.pos;
        }

            //array [gamer.previosPos.coordX][gamer.previosPos.coordY] = 'P';

            */


    }

       // if ()
        //array [gamer.previosPos.coordX][gamer.previosPos.coordY] = 'O';
        array [gamer.pos.coordX][gamer.pos.coordY] = 'P';
        return false;

   //if
   //else  array [gamer.pos.coordX][gamer.pos.coordY] = 'E';

}


int main()
{
    //std::srand(std::time(nullptr));
    char field [SIZE][SIZE];

    bool gameOver = false;
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



    //for (int i = 0; i < 10; i++)
    while (!gameOver)
    {
        gameOver = moveCharacter (field, gamer, enemies);
        displayField (field);
    }

    return 0;
}


/*
if (win == 0)
{
std::cout << enm.name << " won " << std::endl;
array [gamer.pos.coordX][gamer.pos.coordY] = 'E';
std::cout << "Game over " << std::endl;
return true;
}
 */