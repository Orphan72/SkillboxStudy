#include <iostream>
#include <fstream>

int main()
{
    std::ofstream paylist;
    std::string name = " ";
    std::string surname = " ";
    std::string date = " ";
    int salary = 0;

    paylist.open ("..\\data\\paylist.txt", std::ios::app);

    if (paylist.is_open())
    {
        std::cout << "=The file is opened=\n";

       char answer = 'y';
        while (answer == 'y')
        {
            std::cout << "Enter name\n=>";
            std::cin >> name;
            paylist << name << " ";

            std::cout << "Enter surname\n=>";
            std::cin >> surname;
            paylist << surname << " ";

            std::cout << "Enter date\n=>";
            std::cin >> date;
            paylist << date << " ";

            std::cout << "Enter salary\n=>";
            std::cin >> salary;
            paylist << salary << " RUR" << std::endl;

            std::cout << "Continue the enter? y/n? \n";
            std::cin >> answer;
        }
    }
    else
    {
        std::cout << "=The file is not opened=\n";
    }

    paylist.close();
    return 0;
}