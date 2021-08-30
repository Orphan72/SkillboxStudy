#include <iostream>

int main()
{
   int SIZE = 5;
   int mas [SIZE][SIZE];
   int count = 0;


  int i = 0;

   for (int j = 0; j < 5; j++)
   {
       mas [i][j] = count++;
   }

   i = 1;

   for (int j = 4; j >= 0; j--)
   {
       mas [i][j] = count++;
   }

    i = 2;

    for (int j = 0; j < 5; j++)
    {
        mas [i][j] = count++;
    }
    i = 3;
    for (int j = 4; j >= 0; j--)
    {
        mas [i][j] = count++;
    }

    i = 4;

    for (int j = 0; j < 5; j++)
    {
        mas [i][j] = count++;
    }



    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << mas [i][j] << " ";
        }
        std::cout << std::endl;
    }



    return 0;
}
