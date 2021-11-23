#include <iostream>
#include <vector>

int const SIZE = 5;

void swapvec (std::vector<int> &vc, int* ar)
{
    for (int i = 0; i < SIZE; i++)
    {
        ar [i] += vc [i];
        vc [i] = ar [i] - vc [i];
        ar [i] -= vc [i];
    }
}

void showVec (std::vector<int> vc)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << vc [i] << " ";
    }
    std::cout << std::endl;
}

void showArr (int *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr [i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5};
    int arr [] = {6,7,8,9,10};

    std::cout << "Origin: \n";

    showVec (vec);
    showArr (arr);

    swapvec (vec, arr);

    std::cout << "After swap: \n";

    showVec (vec);
    showArr (arr);

    return 0;
}

