#include <iostream>
#include <fstream>

bool checkPngExtension (std::string str)
{
    const int LENGHTPNG = 4;
    std::string ext = ".png";
    int leghtPath = str.length();

    for (int i = leghtPath - LENGHTPNG, j = 0; i < leghtPath; i++, j++)
    {
        if (str [i] != ext [j])
           return false;
    }
    return true;
}

int main()
{
    std::string path;
    path = "..\\data\\Challenge.png";
    char buffer [10];
    std::ifstream detector;

    detector.open(path);

    if (detector.is_open(), std::ios::binary)
    {
        bool correctExtension = checkPngExtension(path);
        if (!correctExtension)
        {
            std::cout << "No";
        }
        else
        {
            detector.read(buffer, sizeof(buffer));

            std::cout << "buffer  " << buffer;
            std::cout << "Yes";

        }

    }
    else
    {
        std::cout << "The file was not opened!!!\n";
    }













    return 0;
}
