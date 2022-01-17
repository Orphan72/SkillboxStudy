#include <iostream>
#include <ctime>
#include <fstream>

int SIZE = 6;
int MAXCOUNT = 10;
const int BANKNOTES [] = {5000, 2000, 1000, 500, 200, 100};

int getavailableSum (int *bxs)
{
    int suum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        suum += (bxs [i] * BANKNOTES [i]);
    }

    return suum;
}

int main()
{

    std::srand(std::time(nullptr));

    int boxes [] = {0, 0, 0, 0, 0, 0};
    int availableSum = 0;
    int wishSum = 2000;
    int bank = 0;


    std::ifstream memoryFrom ("..\\data\\memory.bin", std::ios::binary);

    if (memoryFrom.is_open())
    {
        std::cout << "=memory open=\n";
        memoryFrom.read((char *) boxes, sizeof(boxes));



        /*
        for (int i = 0; i < MAXCOUNT; i++)
        {
            int num = std::rand()%SIZE;
            std::cout << BANKNOTES [num] << std::endl;
            boxes [num]++;
        }
         */

        availableSum = getavailableSum(boxes);
        std::cout << "rest in ATM  "<< availableSum << std::endl;

        for (int i = 0; i < SIZE; i++)
        {
            std::cout << boxes[i] << " ";
        }

        std::cout << std::endl;


        std::cout << "Wish sum " << wishSum << std::endl;

        if (wishSum > availableSum)
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
                bank = *(BANKNOTES + box);
                while (wishSum >= bank)
                {
                    if (boxes[box] == 0) break;
                    std::cout << "banknot  " << bank << std::endl;

                    wishSum -= bank;
                    boxes[box]--;
                    std::cout << "sum in while " << wishSum << std::endl;
                    //std::cout << "boxes [box] " << boxes [box] << std::e
                }
            }

            std::cout << "final sum " << wishSum << std::endl;
            if (wishSum > 0)
            {
                std::cout << "it is impossible to provide this sum " << std::endl;
            }

            for (int i = 0; i < SIZE; i++)
            {
                std::cout << boxes[i] << " ";
            }
        }


        availableSum = getavailableSum(boxes);



        std::cout << "rest in ATM  "<< availableSum;
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