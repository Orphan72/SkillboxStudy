#include <iostream>

const int SIZE = 5;
void display (int mas [SIZE][SIZE])
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int n = 0; n < SIZE; n++)
        {
            std::cout << mas[k][n] << " ";
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

        i++;
        j++;
        for (; j < SIZE; j++)
        {
            snake[i][j] = count++;
        }


    display (snake);

    return 0;
}
