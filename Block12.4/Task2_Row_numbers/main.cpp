#include <iostream>

int main() {

    int numbers [] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int newNumbers [15];
    int min = numbers [0];
    for (int i = 0; i < 15; i++)
    {
        if (numbers [i] < min)
            min = numbers [i];
    }

    std::cout << "min: " << min << std::endl;
    for (int i = 0; i < 15; i++)
    {
        newNumbers [i] = min;
        min++;
    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << i << ": " << newNumbers [i] << std::endl;
    }


    return 0;
}
