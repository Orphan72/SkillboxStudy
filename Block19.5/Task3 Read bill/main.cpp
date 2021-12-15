#include <iostream>
#include <fstream>

int main()
{
    std::ifstream bill;

    std::string maxName;
    std::string maxSurname;
    std::string date;
    int maxSalary = 0;
    int sumSalary = 0;

    bill.open ("..\\data\\bill.txt");

    if (bill.is_open())
    {
        std::cout << "=The file is opened=\n";
        int salary;
        std::string name;
        std::string surname;

        while (!bill.eof())
        {
            bill >> name >> surname >> salary >> date;

            if (salary > maxSalary)
            {
                maxSalary = salary;
                maxName = name;
                maxSurname = surname;
            }
            sumSalary += salary;
        }
    }
    else
    {
        std::cout << "The file was not opened!!!\n";
    }

    std::cout << "Max salary is " << maxSalary << std::endl;
    std::cout << maxName << " " << maxSurname << " has it" << std::endl;
    std::cout << "Sum salary is " << sumSalary << std::endl;

    return 0;

}