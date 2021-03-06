#include <iostream>

std::string encryptCaesar (std::string txt, int n)
{
    int const NUMLET = 26;
    for (int i = 0; i < txt.length(); i++)
    {
        int pos = (int)txt [i];

        if (pos >= 'A' && pos <= 'Z')
        {
            pos = pos + n;
            while (pos > 'Z') pos -= NUMLET;
            while (pos < 'A') pos += NUMLET;
        }
        else if (pos >= 'a' && pos <= 'z')
        {
            pos = pos + n;
            while (pos > 'z') pos -= NUMLET;
            while (pos < 'a') pos += NUMLET;
        }
        txt [i] = (char)pos;
    }
    return txt;
}

std::string decryptCaesar (std::string txt, int n)
{
    return encryptCaesar(txt, -n);
}

int main()
{
    std::string text = "";
    std::string encryptText = "";
    std::string decryptText = "";
    int shift = 0;
    std::cout << "Enter text \n=>";
    std::getline(std::cin, text);
    std::cout << "Enter shift \n=>";
    std::cin >> shift;

    std::cout << "Initial text: \n";
    std::cout << text << std::endl;

    encryptText = encryptCaesar (text, shift);
    std::cout << "Encrypt text: \n";
    std::cout << encryptText << std::endl;

    decryptText = decryptCaesar (encryptText, shift);
    std::cout << "Decrypt text: \n";
    std::cout << decryptText << std::endl;

    return 0;
}
