#include <iostream>
#include <string>
#include <iomanip>

int main()
{
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

    const int DIFFASCII = 48;
    std::stringstream text;
    bool fl = true;

    for (int i = 0; (i < 3 & fl == true); i++)
    {
        std::cout << "Enter " << i << " code\n=>";

        std::string str = " ";
        int length = 0;

        std::cin >> str;
        length = str.length();
        int arr[length];

        int note = 0;

        int state = 0;
        for (int j = 0; j < length; j++)
        {
            arr[j] = str[j] - DIFFASCII - 1;
            if (arr[j] < 7)
            {
                note = 1 << arr[j];
                state |= note;

                if (state & DO) text << "DO ";
                if (state & RE) text << "RE ";
                if (state & MI) text << "MI ";
                if (state & FA) text << "FA ";
                if (state & SOL) text << "SOL ";
                if (state & LA) text << "LA ";
                if (state & TI) text << "TI ";


            }
            else
            {

                std::cout << "Fall\n";
                fl = false;
                break;



            }



        }

       // if (state & DO)
         //   text << "DO ";




        text << " ";

    }

    std::cout << text.str();

    return 0;
}
