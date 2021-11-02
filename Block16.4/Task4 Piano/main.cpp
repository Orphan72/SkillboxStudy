#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

int main()
{
    const int DIFFASCII = 48;
    const int REPET = 4;
    const int NOT = 7;

    enum notes
    {
        DO = 1,
        RE = 2,
        MI = 4,
        FA = 8,
        SOL = 16,
        LA = 32,
        TI = 64
    };

    std::stringstream text;

    for (int i = 1; (i < REPET); )
    {
       std::string str = " ";
        int note = 0;
        int state = 0;
        int length = 0;
        bool correctStr = false;
        std::vector<int> intVec (10);
        while (!correctStr)
        {
            std::cout << "Enter " << i << " code\n=>";
            std::cin >> str;
            length = str.length();
            int incorrect = 0;
            for (int k = 0; k < length; k++)
            {
                intVec [k]  = (str[k] - DIFFASCII);
                if (intVec[k] > NOT)
                {
                    incorrect++;
                }
            }
            correctStr = (incorrect == 0);

            if (!correctStr)
            {
                std::cout << "Incorrect number of note\n";
                std::cout << "Please, try again\n";
            }
         }

        i++;

        for (int j = 0; j < length; j++)
        {
            intVec [j] = str[j] - DIFFASCII - 1;
            note = 1 << intVec[j];
            state |= note;
            if (state & DO) text << "DO ";
            if (state & RE) text << "RE ";
            if (state & MI) text << "MI ";
            if (state & FA) text << "FA ";
            if (state & SOL) text << "SOL ";
            if (state & LA) text << "LA ";
            if (state & TI) text << "TI ";
        }
        text << " ";
    }

    std::cout << text.str();
    return 0;
}