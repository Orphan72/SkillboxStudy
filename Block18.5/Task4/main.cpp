#include <iostream>

void evendigits (long long nm, int &ans)
{
    if (nm%2 == 0)
        ans++;

    nm /= 10;

    if (nm != 0)
        evendigits (nm, ans);
}

int main()
{
    long long num = 9223372036854775806;
    int answer = 0;
    evendigits (num, answer);
    std::cout <<answer << std::endl;

    return 0;
}
