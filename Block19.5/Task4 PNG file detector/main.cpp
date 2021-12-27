#include <iostream>
#include <fstream>

bool checkPath (const std::string pth)
{
    const std::string ext = ".png";
    std::string pthExt = pth.substr (pth.length() - ext.length(),pth.length());

    return (ext == pthExt);
}

bool checkContent (char* buf)
{
    std::string ext = "PNG";
    const int num = -119;

    std::string strBuf = buf;
    std::string contExt = strBuf.substr (1,ext.length());
    std::cout << "buffer  " << contExt << std::endl;

    int contNum = (int)buf [0];
    std::cout << "num " << contNum << std::endl;
    return ((ext == contExt) && (num == contNum));
}

int main()
{
    std::string path;
    char buffer [10];
    std::ifstream detector;

    bool correctPath = false;

    while (!correctPath)
    {
        std::cout << "Please, enter the path\n=>";
        std::cin >> path;
        //path = "..\\data\\picture.png";
        //path = "..\\data\\text.png";
        //path = "..\\data\\text.txt";

        detector.open(path, std::ios::binary);

        if (detector.is_open())
        {
            correctPath = true;
        }
        else
        {
            std::cout << "The file was not opened!!!\n";
            std::cout << "Try again\n";
        }
    }

    bool isPng = false;

    if (checkPath(path))
    {
        detector.read(buffer, sizeof(buffer));
        isPng = checkContent(buffer);
    }

    std::cout << (isPng ? "Yes" : "No");

    detector.close();

    return 0;
}