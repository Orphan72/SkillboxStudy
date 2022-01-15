#include <iostream>
#include <ctime>
#include <fstream>

int SIZE = 6;
int MAXCOUNT = 100;

int main()
{

    std::srand(std::time(nullptr));

    std::ifstream memoryFrom;
    std::ofstream memoryTo;

    int banknotes [] = {5000, 2000, 1000, 500, 200, 100};

    memoryFrom.open ("..\\data\\river.txt");

    int boxes [] = {0, 0, 0, 0, 0, 0};

    int actualSum = 0;
    int sum = 13800;
    int bank = 0;


    for (int i = 0; i < MAXCOUNT; i++)
    {
        int num = std::rand()%SIZE;
        std::cout << banknotes [num] << std::endl;
        boxes [num]++;
        actualSum += banknotes [num];
    }

    std::cout << "actualSum " << actualSum << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << boxes[i] << " ";
    }

    std::cout << std::endl;


    std::cout << "actualSum " << actualSum << std::endl;
    std::cout << "Wish sum " << sum << std::endl;




    if (sum > actualSum)
    {
        std::cout << "Not enough money in the ATM ";
    }
    else
    {
        std::cout << "Get your money:\n";


        for (int box = 0; box < SIZE; box++)
        {
            if (boxes[box] == 0)
            {
                box++;
            }

            //std::cout << "box - " << box << std::endl;
            bank = *(banknotes + box);
            while (sum >= bank)
            {
                if (boxes[box] == 0) break;
                std::cout << "banknot  " << bank << std::endl;

                sum -= bank;
                boxes[box]--;
                std::cout << "sum in while " << sum << std::endl;
                //std::cout << "boxes [box] " << boxes [box] << std::e
            }
        }

        std::cout << "final sum " << sum << std::endl;
        if (sum > 0)
        {
            std::cout << "it is impossible to provide this sum " << std::endl;
        }

        for (int i = 0; i < SIZE; i++)
        {
            std::cout << boxes[i] << " ";
        }
    }

    actualSum = 0;


    for (int i = 0; i < SIZE; i++)
    {
        actualSum += (boxes [i] * banknotes [i]);
    }

    std::cout << "rest in ATM  "<< actualSum;

    return 0;
}