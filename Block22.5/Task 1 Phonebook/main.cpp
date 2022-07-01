#include <iostream>
#include <map>
#include <string>
#include <vector>

const int MINNUMBER = 60;
const int MAXNUMBER = 70;

const std::vector<std::string> SURNAMELIST
{
    "Petrov", "Sidorov", "Ivanov", "Kozlov", "Abramov", "Peredelkin", "Kashhkin"
};


void fullVector (std::vector <int> &vec)
{
    bool exist = false;
    while (vec.size() < SURNAMELIST.size())
    {
        int diffNumber = MAXNUMBER - MINNUMBER;
        int num = std::rand() % (diffNumber + 1) + MINNUMBER;
        for (int i = 0; i < vec.size(); i++)
        {
            if (num == vec[i])
            {
                exist = true;
                break;
            }
        }
        if (!exist) vec.push_back(num);
        else exist = false;
    }
}

void addPair (std::map <int, std::string> &oMap, int num, std::string str)
{
    std::pair<int, std::string> oPair (num, str);
    oMap.insert(oPair);
}

void fullMap (std::map <int, std::string> &oMap, std::vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        addPair (oMap, vec[i], SURNAMELIST[i]);
    }
}

void showMap (std::map<int, std::string> oMap)
{
    for (std::map <int, std::string>::iterator it = oMap.begin();
         it != oMap.end (); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

int strinfToInt (std::string str)
{
    std::vector <int> vec;
    int num = 0;
    int dec = 1;
    for (int i = 0; i < str.length(); i++)
    {
        int intNumber = 0;
        if (str [i] >= '0' && str [i] <= '9')
        {
            intNumber = str [i] - '0';
            vec.push_back(intNumber);
        }
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        num += (vec[i] * dec);
        dec *= 10;
    }

    return num;
}

bool checkBusyNumber (std::map<int, std::string> oMap, int num)
{
    for (std::map <int, std::string>::iterator it = oMap.begin(); it != oMap.end (); ++it)
    {
        if (num == it->first)
        {
            return true;
        }
    }
    return false;
}

bool checkExistNumber (std::map<int, std::string> oMap, int num)
{
    int exist = 0;
    for (std::map <int, std::string>::iterator it = oMap.begin(); it != oMap.end (); ++it)
    {
        if (num == it->first) exist++;
    }
    if (exist == 0) return false;
    else return true;
}


int main()
{
    std::map <int, std::string> phonebook;
    std::vector <int> numberList;
    int answer = -1;
    int intPhoneNomber = 0;
    std::string strPhoneNomber = " ";
    std::string surname = " ";
    bool busyNumber = true;
    bool existNumber = false;
    bool correctAnswer = false;


    fullVector(numberList);
    fullMap (phonebook, numberList);
    showMap(phonebook);

    while (!correctAnswer)

    std::cout << "Enter one of the next numbers:\n";
    std::cout << "To add new subscriber press 1\n";
    std::cout << "To find out subscriber's surname press 2\n";
    std::cout << "To find out subscriber's number press 3\n";
    std::cout << "To show all phonebook press 4\n";
    std::cout << "To exit press 0\n";

    std::cin >> answer;

    if (answer == 1)
    {
        while (busyNumber)
        {
            std::cout << "Enter pnone number\n";
            std::cin >> strPhoneNomber;
            intPhoneNomber = strinfToInt (strPhoneNomber);
            busyNumber = checkBusyNumber (phonebook, intPhoneNomber);
            if (busyNumber)
            {
                std::cout << "This number busy already. Try again\n";
            }
        }

        std::cout << "Enter surname \n";
        std::cin >> surname;
        addPair (phonebook, intPhoneNomber, surname);
    }
    else if (answer == 2)
    {
        while (!existNumber)
        {
            std::cout << "Enter pnone number\n";
            std::cin >> intPhoneNomber;
            existNumber = checkExistNumber(phonebook,intPhoneNomber);
            if (!existNumber)
            {
                std::cout << "This number doesn't exist. Try again\n";
            }
        }

        std::cout << "For your request there is subscriber:\n";
        std::cout << phonebook [intPhoneNomber] << std::endl;
    }
    else if (answer == 3)
    {
        std::cout << "Enter surname \n";
        std::cin >> surname;

        std::cout << "This subscriber has next numbers:\n";

        for (std::map <int, std::string>::iterator it = phonebook.begin();
             it != phonebook.end (); ++it)
        {
            if (it->second == surname)
                std::cout << it->first << std::endl;
        }
    }

    return 0;
}
