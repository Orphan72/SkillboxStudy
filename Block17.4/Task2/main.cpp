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

int main()
{
    int mas [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << mas << std::endl;

    std::cout << "Origin array:\n";

    for (int i = 0; i < 10; i++) {
        std::cout << *(mas + i) << " ";
    }
    std::cout << std::endl;

    reverse(mas);

    std::cout << "Reversed array:\n";

    for (int i = 0; i < 10; i++) {
        std::cout << *(mas + i) << " ";
    }

    std::cout << std::endl;

    return 0;

}