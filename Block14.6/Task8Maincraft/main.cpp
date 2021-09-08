#include <iostream>
#include <vector>

const int SIZE = 3;
void displayAll (std::vector <bool> vec [SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < vec[i][j].size(); k++)
            {
                std::cout << vec[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void displaySlice (std::vector <bool> vec [SIZE][SIZE], int k)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << vec[i][j][k] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector <bool> sector [SIZE][SIZE];
    const int maxHight = 10;
    int hightPillar    = 0;
    int hightSlice     = 0;

    for (int i = 0, l = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << "Enter hight of " << i + j + l << " pillar=>";
            std::cin >> hightPillar;
            for (int k = 0; k < hightPillar; k++)
            {
                sector[i][j].push_back(true);
            }
            for (int k = hightPillar; k < maxHight; k++)
            {
                sector[i][j].push_back(false);
            }
       }
        l += SIZE - 1;
    }

    displayAll (sector);

    bool correctEnter = false;
    while (!correctEnter)
    {
        std::cout << "Enter hight of slice \n=>";
        std::cin >> hightSlice;
        correctEnter = (hightSlice >= 0 && hightSlice < maxHight);
        if (!correctEnter)
        {
            std::cout << "Hight of slice should be from 1 to 9. Try again\n";
        }
        else
        {
            displaySlice(sector, hightSlice);
        }
    }
    return 0;
}
