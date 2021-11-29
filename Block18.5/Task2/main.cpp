#include <iostream>

int steps (int n)
{
    if (n == 0) return 1;
    else if (n < 0) return 0;
    return steps (n - 1) + steps(n - 2) + steps(n - 3);
}

int main()
{
    std::cout << steps (3);
    return 0;
}
