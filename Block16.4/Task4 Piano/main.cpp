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
    std::string str = " ";
    int length = 0;

    for (int i = 1; (i < REPET); )
    {
        bool correctStr = false;
        std::vector<int> intVec;
        while (!correctStr)
        {
            std::cout << "Enter " << i << " code\n=>";
            std::cin >> str;
            length = str.length();
            intVec.resize(length);
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
            int state = 0;

            intVec [j] = str[j] - DIFFASCII - 1;
            int note = 1 << intVec[j];
            state |= note;
            if (state & DO) text << "DO";
            if (state & RE) text << "RE";
            if (state & MI) text << "MI";
            if (state & FA) text << "FA";
            if (state & SOL) text << "SOL";
            if (state & LA) text << "LA";
            if (state & TI) text << "TI";
            text << " ";
        }
        text << "\n";
    }

    std::cout << text.str();
    return 0;
}