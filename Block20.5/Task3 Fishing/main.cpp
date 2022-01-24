#include <iostream>
#include <fstream>

int main()
{
    std::ifstream river;
    std::ofstream basket;

    std::string wantedFish = " ";
    std::string fishInRiver = " ";

    int countFish = 0;

    std::cout << "What kind of fish do you want to catch?\n=>";
    std::cin >> wantedFish;

    river.open ("..\\data\\river.txt");
    basket.open ("..\\data\\basket.txt",  std::ios::app);
    if (river.is_open())
    {
        std::cout << "Fishing allowed\n";

        if (basket.is_open())
        {
            std::cout << "The basket is opened\n";
            while (!river.eof())
            {
                river >> fishInRiver;
                if (fishInRiver == wantedFish)
                {
                    countFish++;
                    std::cout << countFish << " " << fishInRiver << "s is caught\n";
                    basket << fishInRiver << std::endl;
                }
            }
        }
        else
            std::cout << "The basket isn't opened\n";
    }
    else
    {
        std::cout << "Fishing forbidden!\n";
    }

    basket.close();
    std::cout << "The basket is closed\n";
    river.close();
    std::cout << "Fishing is closed\n";

    std::cout << "For current fishing " << countFish << " " << wantedFish << " were caught\n";

    return 0;
}