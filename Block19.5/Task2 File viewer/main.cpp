#include <iostream>
#include <string>
#include <fstream>

const int SIZE = 20;

int main()
{
    std::ifstream words;

    char buffer [SIZE];

    words.open ("..\\data\\words.txt", std::ios::binary);

    if (words.is_open())
    {
        std::cout << "=The file is opened=\n";

        while (!words.eof())
        {
            words.read(buffer, sizeof(buffer)-1);

            if (words.gcount() < SIZE -1 )
            {
                int count = words.gcount();
                for (int i = 0; i < count; i++)
                    std::cout << buffer [i];
            }
            else
                std::cout << buffer;
        }
    }
    else
    {
        std::cout << "The file was not opened!!!\n";
    }
}
