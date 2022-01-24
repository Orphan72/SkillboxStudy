#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    std::ofstream picture;

    int count = 0;
    int width = 0;
    int height = 0;


    picture.open ("..\\data\\pic.txt", std::ios::binary);

    if (picture.is_open())
    {
        std::cout << "=The file is opened=\n";
        std::cout << "Enter the width of picture\n=>";
        std::cin >> width;
        std::cout << "Enter the height of picture\n=>";
        std::cin >> height;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                count = std::rand()%2;
                picture << count << " ";
            }
            picture << std::endl;
        }
        picture << std::endl;
        std::cout << "Picture ready\n";
    }
    else
    {
        std::cout << "=The file is not opened=\n";
    }

    picture.close();
    return 0;
}