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

void showATMboxes (int *bxs)
{
    std::cout << "ATM boxes: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << bxs[i] << " ";
    }
    std::cout << std::endl;
}

void showGetMoney (int *wlt)
{
    std::cout << "Your money: \n";
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (wlt[i] != 0)
        {
            std::cout << wlt[i] << " banknotes of " << BANKNOTES[i] << " RUR" << std::endl;
            count++;
        }

        if (i == (SIZE -1) && count == 0)
            std::cout << "Empty" << std::endl;
    }
}


int main()
{

    std::srand(std::time(nullptr));
    int boxes [] = {0, 0, 0, 0, 0, 0};
    int wallet [] = {0, 0, 0, 0, 0, 0};

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

        showATMboxes(boxes);

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
            std::cout << "Enter wish sum\n=>";
            std::cin >> wishSum;
            if (wishSum > availableSum)
            {
                std::cout << "Not enough money in the ATM\n";
            }
            else
            {
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

                        wishSum -= bank;
                        boxes[box]--;
                        wallet[box]++;
                    }
                }

                if (wishSum > 0)
                {
                    memoryFrom.close();

                    std::cout << "it is impossible to provide this sum " << std::endl;

                    std::ifstream memFrm ("..\\data\\memory.bin", std::ios::binary);
                    if (memFrm.is_open())
                    {
                        memFrm.read((char *) boxes, sizeof(boxes));
                        for (int i = 0; i < SIZE; i++)
                        {
                            wallet [i] = 0;
                        }
                    }
                    else
                    {
                        std::cout << "=The memory of ATM is not available for reading=\n";
                    }

                    memFrm.close();
                }
            }
        }

        availableSum = getavailableSum(boxes);
        countBank = getCountBankn (boxes);
        std::cout << "Rest in ATM  "<< availableSum << std::endl;
        std::cout << "Banknotes in ATM  "<< countBank << std::endl;

        showATMboxes(boxes);
        showGetMoney(wallet);

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