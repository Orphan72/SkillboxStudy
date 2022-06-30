#include <iostream>
#include <map>
#include <string>
#include <vector>

const int MINNUMBER = 60;
const int MAXNUMBER = 70;

const std::vector<std::string> SURNAMELIST
{
    "Petrov", "Sidorov", "Ivanov", "Kozlov", "Abramov", "Peredelkin", "Kashhkin", "Ivanov"
};

bool checkExistenceNumber (std::map<int, std::string> oMap, int num)
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

std::vector <int> strinfToInt (std::string str)
{
    std::vector <int> vec;
    for (int i = 0; i < str.length(); i++)
    {
        int intNumber = 0;
        if (str [i] >= '0' && str [i] <= '9')
        {
            intNumber = str [i] - '0';
            vec.push_back(intNumber);
        }
    }
    return vec;
}


int main()
{
    std::map <int, std::string> phonebook;
    std::vector <int> numberList;

    fullVector(numberList);
    fullMap (phonebook, numberList);
    showMap(phonebook);

    std::cout << "To add new subscriber press 1\n";
    std::cout << "To find out subscriber's surname press 2\n";
    std::cout << "To find out subscriber's number press 2\n";

int number = 70;
checkExistenceNumber (phonebook, number);

 std::cout << "Number "<< number << " busy. Try again\n";



//2
    std::cout << phonebook [603] << std::endl;

//3
    for (std::map <int, std::string>::iterator it = phonebook.begin();
         it != phonebook.end (); ++it)
    {
        if (it->second == "Ivanov")
        std::cout << it->first << std::endl;
    }



    /*

    std::string stringNumber = " ";

    std::cout << "Input the phone number\n";
    std::cin >> stringNumber;
    vecNumber = strinfToInt(stringNumber);

    for (int i = 0; i < vecNumber.size(); i++)
    {
        std::cout << vecNumber[i];
    }

        */
    return 0;
}
