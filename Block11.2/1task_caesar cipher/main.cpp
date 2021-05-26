#include <iostream>

std::string encrypt_caesar (std::string txt, int n)
{
    int const NUMLET = 26;
    for (int i = 0; i < txt.length(); i++)
    {
        int pos = (int)txt [i];

        if (pos >= 65 && pos <= 90)
        {
            pos = pos + n;
            while (pos > 90) pos -= NUMLET;
            while (pos < 65) pos += NUMLET;
        }
        else if (pos >= 97 && pos <= 122)
        {
            pos = pos + n;
            while (pos > 122) pos -= NUMLET;
            while (pos < 97) pos += NUMLET;
        }
        txt [i] = (char)pos;
    }
    return txt;
}

std::string decrypt_caesar (std::string txt, int n)
{
    return encrypt_caesar(txt, -n);
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

    encryptText = encrypt_caesar (text, shift);
    std::cout << "Encrypt text: \n";
    std::cout << encryptText << std::endl;

    decryptText = decrypt_caesar (encryptText, shift);
    std::cout << "Decrypt text: \n";
    std::cout << decryptText << std::endl;

    return 0;
}
