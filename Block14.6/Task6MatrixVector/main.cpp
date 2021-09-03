#include <iostream>
#include <vector>
const int SIZE = 4;

void displayArray (float mas [SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << mas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void dispVec (std::vector <float> vec)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <float> vec (SIZE);
    std::vector <float> result (SIZE);
    float array [SIZE][SIZE];

    std::cout << "Please, full vector" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> vec [i];
    }

    std::cout << "Please, full array" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> array [i][j];
        }

    }

    for (int i = 0; i < SIZE; i++)
   {
       for (int j = 0; j < SIZE; j++)
       {
           result [i] += vec [i] * array [j][i];
       }
   }

   std::cout << "Vector\n";
    dispVec(vec);

    std::cout << "Array\n";
    displayArray(array);

    std::cout << "Result\n";
    dispVec(result);

    return 0;
}
