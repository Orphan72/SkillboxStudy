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
    //path = "..\\data\\BD.png";
    //path = "..\\data\\skill.png";
    //path = "..\\data\\test.png";
    char buffer [10];
    std::ifstream detector;

    detector.open(path, std::ios::binary);

   // double value;
    if (detector.is_open())
    {
        bool correctExtension = checkPngExtension(path);
        if (!correctExtension)
        {
            std::cout << "No";
        }
        else
        {
          //  detector.read((char*)&value, 10);
            detector.read(buffer, sizeof(buffer));

            //std::cout << "value  " << value;
            std::cout << "buffer  " << buffer;
            std::cout << "buffer [2]  " << (int)buffer [0];


            std::cout << "Yes";

        }

    }
    else
    {
        std::cout << "The file was not opened!!!\n";
    }













    return 0;
}
