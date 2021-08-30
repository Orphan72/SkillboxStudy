#include <iostream>

const int SIZE = 5;

void display (int mas [SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << mas [i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int snake [SIZE][SIZE];
    int count = 0;

    int i = -1;
    int j = -1;
    for (int n = 0; n <= SIZE/2 ; n++)
    {
        i++;
        j++;
        for (; j < SIZE; j++)
        {
            snake[i][j] = count++;
        }

        i++;
        j--;
        for (; j >= 0; j--)
        {
            snake[i][j] = count++;
        }
    }

    return 0;
}
