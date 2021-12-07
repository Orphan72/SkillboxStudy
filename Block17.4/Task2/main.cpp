#include <iostream>

const int SIZE = 10;

void reverse (int* arr)
{
    for (int i = 0; i < SIZE / 2; i++)
    {
        *(arr + i) += *(arr + SIZE - 1 - i);
        *(arr+ SIZE - 1 - i) = *(arr + i) - *(arr + SIZE - 1 - i);
        *(arr + i) -= *(arr + SIZE - 1 - i);
    }
}

void show (int* arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int mas [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
    std::cout << "Origin array:\n";
    show(mas);

    reverse(mas);

    std::cout << "Reversed array:\n";
    show(mas);

    return 0;
}