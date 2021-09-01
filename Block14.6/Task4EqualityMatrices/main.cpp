#include <iostream>

const int SIZE = 4;
void display (int mas [SIZE][SIZE])
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

int main()
{
    int matrix1 [SIZE][SIZE];
    int matrix2 [SIZE][SIZE];

    std::cout << "Please, full first matrix\n" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> matrix1[i][j];
        }
    }

    display (matrix1);

    std::cout << "Please, full second matrix\n" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> matrix2[i][j];
        }
    }

    display (matrix2);

    bool equal = true;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
               equal = false;
               break;
            }
        }
    }

    std::cout << ((!equal) ? " NOT EQUAL" : " EQUAL");
    return 0;
}

