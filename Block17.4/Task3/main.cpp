#include <iostream>

bool substr (const char* str1, const char* str2)
{
    for (int i = 0; *(str1 + i) != '\0'; i++)
    {
        bool match = true;
        for (int j = 0; *(str2 + j) != '\0'; j++)
        {
            if ( *(str1 + i + j) == '\0' || *(str2 + j) != *(str1 + j + i))
            {
                match = false;
                break;
            }
        }
        if (match)
           return true;
    }
}

int main()
{
    const char* main_str = "Hello, World!";
    const char* slave_str = "Bla";

    bool found = substr (main_str, slave_str);
    std::cout << (found ? "Yes!" : "No!");

    return 0;
}