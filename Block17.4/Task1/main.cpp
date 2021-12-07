#include <iostream>

void swap (int *x, int* y)
{
    *x += *y;
    *y = *x - *y;
    *x -=*y;
}


int main()
{
    int a = 10;
    int b = 20;

    swap (&a, &b);

    std::cout << a << " " << b << std::endl;

    return 0;
}
