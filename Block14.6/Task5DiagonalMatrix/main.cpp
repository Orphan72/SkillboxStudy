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

int main() {
    int matrix [SIZE][SIZE];

    std::cout << "Please, full matrix" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0, k = 1; k < SIZE; i++, k++)
    {
        for (int j = k; j < SIZE; j++)
        {
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }
    }

    display (matrix);
    return 0;
}
