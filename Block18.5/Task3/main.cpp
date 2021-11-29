#include <iostream>

int steps (int n, int k = 3)
{
    if (n == 0) return 1;
    else if (n < 0) return 0;
    int result = 0;
    for (int i = 1; i <= k; i++)
    {
        result += steps (n - i);
    }

    return result;
}

int main()
{
    //std::cout << steps (4, 4);
    std::cout << steps (3);
    return 0;
}
