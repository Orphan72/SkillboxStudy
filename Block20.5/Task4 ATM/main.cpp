#include <iostream>
#include <ctime>
#include <fstream>

int SIZE = 6;
int MAXCOUNTBANKN = 1000;
const int BANKNOTES [] = {5000, 2000, 1000, 500, 200, 100};

int getavailableSum (int *bxs)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += (bxs [i] * BANKNOTES [i]);
    }
    return sum;
}

int getCountBankn (int *bxs)
{
    int bnk = 0;
    for (int i = 0; i < SIZE; i++)
    {
        bnk += bxs [i];
    }
    return bnk;
}

int main()
{

    std::srand(std::time(nullptr));
    int boxes [] = {0, 0, 0, 0, 0, 0};
    int availableSum = 0;
    int wishSum = 0;
    int bank = 0;
    int countBank = 0;
    char answer = ' ';


    bool correctAnswer = false;


    std::ifstream memoryFrom ("..\\data\\memory.bin", std::ios::binary);


    if (memoryFrom.is_open())
    {
        std::cout << "=memory open=\n";
        memoryFrom.read((char *) boxes, sizeof(boxes));
        availableSum = getavailableSum(boxes);
        std::cout << "rest in ATM  "<< availableSum << std::endl;

        countBank = getCountBankn (boxes);
        std::cout << "banknotes in ATM  "<< countBank << std::endl;

        std::cout  << "if you want to full ATM, please, press \"+\"\n";
        std::cout  << "if you want to get monery, please, press \"-\"\n=>";

        while (!correctAnswer)
        {
            std::cin >> answer;
            correctAnswer = (answer == '+' || answer == '-');
            if (!correctAnswer)
                std::cout << "Answer incorrect, please, try again\n";
        }

        if (answer == '+')
        {
            for (int i = 0; i < (MAXCOUNTBANKN - countBank); i++)
            {
                int num = std::rand()%SIZE;
                boxes [num]++;
            }

            availableSum = getavailableSum(boxes);
            std::cout << "rest in ATM  "<< availableSum << std::endl;

            countBank = getCountBankn (boxes);
            std::cout << "banknotes in ATM  "<< countBank << std::endl;
        }
        else
        {
            availableSum = getavailableSum(boxes);
            std::cout << "rest in ATM  "<< availableSum << std::endl;

            countBank = getCountBankn (boxes);
            std::cout << "banknotes in ATM  "<< countBank << std::endl;

            for (int i = 0; i < SIZE; i++)
            {
                std::cout << boxes[i] << " ";
            }

            std::cout << std::endl;

            std::cout << "Enter wish sum\n=>";
            std::cin >> wishSum;
            if (wishSum > availableSum)
            {
                std::cout << "Not enough money in the ATM ";
            }
            else
            {
                std::ofstream banknotes ("..\\data\\banknotes.bin", std::ios::binary);

                std::cout << "Get your money:\n";
                for (int box = 0; box < SIZE; box++)
                {
                    if (boxes[box] == 0)
                    {
                        box++;
                    }
                    bank = *(BANKNOTES + box);
                    while (wishSum >= bank)
                    {
                        if (boxes[box] == 0) break;
                        std::cout << "banknot  " << bank << std::endl;

                        wishSum -= bank;
                        boxes[box]--;

                        std::cout << "wishsum  " << wishSum << std::endl;

                    }
                }

                if (wishSum > 0)
                {

                    memoryFrom.close();
                    std::cout << "it is impossible to provide this sum " << std::endl;

                    std::ifstream memFrom ("..\\data\\memory.bin", std::ios::binary);
                    memFrom.read((char *) boxes, sizeof(boxes));
                    for (int i = 0; i < SIZE; i++)
                    {
                        std::cout << boxes[i] << " ";
                    }
                    memFrom.close();

                }

                for (int i = 0; i < SIZE; i++)
                {
                    std::cout << boxes[i] << " ";
                }
            }
        }

        availableSum = getavailableSum(boxes);
        countBank = getCountBankn (boxes);
        std::cout << "rest in ATM  "<< availableSum << std::endl;
        std::cout << "banknotes in ATM  "<< countBank << std::endl;
    }
    else
    {
        std::cout << "=The memory of ATM is not available for reading=\n";
    }

    memoryFrom.close();

    std::ofstream memoryTo ("..\\data\\memory.bin", std::ios::binary);
    if (memoryTo.is_open())
    {
        memoryTo.write((char*)boxes, sizeof (boxes));
    }
    else
    {
        std::cout << "=The memory of ATM is not available for writing=\n";
    }
    memoryTo.close();

    return 0;
}