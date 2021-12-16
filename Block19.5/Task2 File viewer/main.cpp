#include <iostream>
#include <string>
#include <fstream>

const int SIZE = 20;

int main()
{
    std::ifstream poem;

    char buffer [SIZE];

    poem.open ("..\\data\\poem.txt");

    if (poem.is_open())
    {
        std::cout << "=The file is opened=\n";

        while (!poem.eof())
        {
            poem.read(buffer, sizeof(buffer)-1);

            if (poem.gcount() < SIZE -1 )
            {
                int count = poem.gcount();
                buffer [count] = 0;
            }
                std::cout << buffer;
        }
    }
    else
    {
        std::cout << "The file was not opened!!!\n";
    }

    poem.close();
}
