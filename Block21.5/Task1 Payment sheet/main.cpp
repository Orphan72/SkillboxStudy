#include <iostream>
#include <fstream>
#include <vector>

struct actor
{
    std::string name = "uncnown";
    std::string surname = "uncnown";;
    std::string date = "00.00.0000";
    int salary = 0;
};

int main()
{
    std::vector <actor> people;
    actor person;
    int vectorSize = 0;
    std::string answer = " ";
    bool correctAnswer = false;

    while (!correctAnswer)
    {
        std::cout << "For see add data input 'add'\n";
        std::cout << "For see list input 'list'\n";
        std::cin >> answer;
        correctAnswer = (answer == "add" || answer == "list");
        if (!correctAnswer)
        {
            std::cout << "Incorrect answer\nPlease try again\n";
        }
    }

    if (answer == "add")
    {
        std::ofstream paylist;
        paylist.open("..\\data\\paylist.txt", std::ios::app);
        if (paylist.is_open())
        {
            std::cout << "=The file is opened=\n";
            std::cout << "Enter the personal data:\n";
            std::cout << "Name =>";
            std::cin >> person.name;
            paylist << person.name << " ";

            std::cout << "Surname =>";
            std::cin >> person.surname;
            paylist << person.surname << " ";

            std::cout << "Date=>";
            std::cin >> person.date;
            paylist << person.date << " ";

            std::cout << "Salary =>";
            std::cin >> person.salary;
            paylist << person.salary << " ";
        } else
        {
            std::cout << "=The file is not opened=\n";
        }
        paylist.close();
    }
    else
    {
        std::ifstream bill;
        bill.open("..//data//paylist.txt");

        if (bill.is_open())
        {
            std::cout << "=The file is opened=\n";
            while (!bill.eof())
            {
                bill >> person.name >> person.surname
                     >> person.date >> person.salary;

                people.push_back(person);
            }

            vectorSize = people.size() - 1;
        }
        else
        {
            std::cout << "The file was not opened!!!\n";
        }

        bill.close();
    }
    for (int i = 0; i < vectorSize; i++)
    {
        std::cout << "Actor # " << i + 1 << ":" << std::endl;
        std::cout << people[i].name << " " << people[i].surname << std::endl;
        std::cout << "Date: " << people[i].date << std::endl;
        std::cout << "Salary: " << people[i].salary << " RUR" << std::endl;
        std::cout << "===================\n";
    }
    return 0;

}