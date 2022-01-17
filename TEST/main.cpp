#include <iostream>
#include <fstream>



int main()
{

    int boxes [6];

    std::ifstream memoryFrom ("..\\data\\memory.bin", std::ios::binary);
    memoryFrom.read((char*)boxes, sizeof (boxes));


    //std::cout << sizeof (boxes);


    for (int i = 0; i < 6; i++)
    {
        boxes [i] = 0;
    }

    for (int i = 0; i < 6; i++)
    {
        std::cout << boxes [i] << " ";
    }



    memoryFrom.close();



    std::ofstream memoryTo ("..\\data\\memory.bin", std::ios::binary);

    memoryTo.write((char*)boxes, sizeof (boxes));
    memoryTo.close();

    for (int i = 0; i < 6; i++)
    {
        std::cout << boxes [i] << " ";
    }






    /*


    for (int i = 0; i < 6 || (!memoryFrom.eof()); i++)
    {
        memoryFrom >> boxes [i];
    }


    for (int i = 0; i < 6 || (!memoryFrom.eof()); i++)
    {
        std::cout <<  boxes [i] << std:: endl;
    }

    std::cout <<  "Enter six numbers\n=>";

    for (int i = 0; i < 6 || (!memoryFrom.eof()); i++)
    {
        std::cin >> boxes [i];
    }

    for (int i = 0; i < 6 || (!memoryFrom.eof()); i++)
    {
        std::cout <<  boxes [i] << std:: endl;
    }

*/






}

