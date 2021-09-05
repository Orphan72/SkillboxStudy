#include <iostream>
#include <vector>
#include <valarray>

const int SIZE = 12;

void display (std::vector <std::vector <bool>> vec)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << (vec [i][j] ?  "O " : "X ");
        }
        std::cout << std::endl;
    }
}

bool checkEnter (int a, int b)
{
    return !(a < 1 || a > SIZE || b < 1 || b > SIZE);
}

std::vector<std::vector <bool>> pop (std::vector<std::vector <bool>> vec, int stY, int stX, int finY, int finX)
{
    for (int i = (stY - 1); i < finY; i++)
    {
        for (int j = (stX - 1); j < finX; j++)
        {
            if (vec[i][j])
            {
                vec [i][j] = false;
                std::cout << "Pop! ";
            }
        }
    }
    std::cout << std::endl;
    return vec;
}

bool checkIntact (std::vector <std::vector <bool>> vec)
{
    int countIntact = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (vec [i][j]) countIntact++;
        }
    }

    return countIntact > 0;
}

int main() {

    std::vector <std::vector<bool>> bubble (SIZE, std::vector<bool> (SIZE));
    int rowStart = 0;
    int colStart = 0;
    int rowFin   = 0;
    int colFin   = 0;
    bool intact  = true;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            bubble[i][j] = true;
        }
    }

    display(bubble);

    while (intact)
    {
        bool correct = false;
        while (!correct)
        {
            std::cout << "Please input start coordinates from 1 to " << SIZE << std::endl;
            std::cin >> rowStart >> colStart;
            correct = checkEnter(rowStart, colStart);
            if (!correct)
            {
                std::cout << "Values must be from 1 to to " << SIZE <<  " Please, try again\n";
            }
        }

        correct = false;

        while (!correct)
        {
            std::cout << "Please input finish coordinates from 1 to " << SIZE << std::endl;
            std::cin >> rowFin >> colFin;
            correct = checkEnter (rowFin, colFin);
            if (!correct)
            {
                std::cout << "Values must be from 1 to to " << SIZE <<  " Please, try again\n";
            }
        }

        bubble = pop (bubble, rowStart, colStart, rowFin, colFin);

        display(bubble);

        intact = checkIntact (bubble);
        if (!intact)
        {
            std::cout << "All bubbles are burst\n";
        }
    }

    return 0;
}