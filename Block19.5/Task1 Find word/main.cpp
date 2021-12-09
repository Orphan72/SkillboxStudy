#include <iostream>
#include <string>
#include <fstream>

bool search (std::string str1, std::string str2)
{
    if (str1.length() != str2.length())
        return false;
    else
    {
        for (int i = 0; str2[i] != '\0'; i++) {
            if (str2[i] != str1[i])
                return false;
        }
        return true;
    }
}

int main()
{
    std::string testWord = "winter";
    //std::string testWord = "river";
    //std::string testWord = "sprinf";
    //std::string testWord = "student";
    std::string oneWord;
    std::ifstream words;
    words.open ("..\\data\\words.txt");

    int count = 0;
    while (!words.eof())
    {
        words >> oneWord;
        if (search (testWord,oneWord))
            count++;
    }
    words.close();
    std::cout << "Word \"" << testWord << "\" was found " << count << " time(s)\n";
}
