#include <iostream>

const int SIZE = 5;
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
    int snake [SIZE][SIZE];
    int count = 0;

    int i = 0;
    int j = 0;

    while  (i <= SIZE/2)
    {
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
        i++;
        j++;
    }

    for (; j < SIZE; j++)
    {
        snake[i][j] = count++;
    }

    display (snake);

    return 0;
}
