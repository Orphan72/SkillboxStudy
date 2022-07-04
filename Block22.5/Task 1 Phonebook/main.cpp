#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>

const int MINNUMBER = 600000;
const int MAXNUMBER = 700000;

const std::vector<std::string> SURNAMELIST
{
    "Petrov", "Sidorov", "Ivanov", "Kozlov", "Abramov", "Peredelkin", "Kashhkin"
};

void fullNumberList (std::vector <int> &vec)
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

void fullPhonebook (std::map <int, std::string> &oMap, std::vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        addPair (oMap, vec[i], SURNAMELIST[i]);
    }
}

void showPhonebook (std::map<int, std::string> oMap)
{
    for (std::map <int, std::string>::iterator it = oMap.begin();
         it != oMap.end (); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

int stringToInt (std::string str)
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

bool checkExistSurname (std::map<int, std::string> oMap, std::string str)
{
    int exist = 0;
    for (std::map <int, std::string>::iterator it = oMap.begin(); it != oMap.end (); ++it)
    {
        if (str == it->second) exist++;
    }
    if (exist == 0) return false;
    else return true;
}

int main()
{
    std::srand(std::time(nullptr));
    std::map <int, std::string> phonebook;
    std::vector <int> numberList;
    int answer = -1;
    int intPhoneNomber = 0;
    std::string strPhoneNomber = " ";
    std::string surname = " ";
    std::string res = "RESULT:\n";
    std::string line = "==================\n";
    bool busyNumber = false;
    bool existNumber = false;
    bool existSurname = false;

    fullNumberList (numberList);
    fullPhonebook (phonebook, numberList);

    while (answer)
    {
        std::cout << "Enter one of the next keys:\n";
        std::cout << "1 - add new subscriber\n";
        std::cout << "2 - find out subscriber's surname\n";
        std::cout << "3 - find out subscriber's number\n";
        std::cout << "4 - show all phonebook\n";
        std::cout << "0 - EXIT\n=>";
        std::cin >> answer;

        if (answer == 1)
        {
            std::cout << "Enter pnone number\n";
            std::cin >> strPhoneNomber;
            intPhoneNomber = stringToInt (strPhoneNomber);
            busyNumber = checkBusyNumber (phonebook, intPhoneNomber);

            if (busyNumber)
            {
                std::cout << "This number busy already. Try again\n";
            }
            else
            {
                std::cout << "Enter surname \n";
                std::cin >> surname;
                addPair (phonebook, intPhoneNomber, surname);
                std::cout << "Enter surname \n";
            }
       }
       else if (answer == 2)
       {
           std::cout << "Enter pnone number\n";
           std::cin >> strPhoneNomber;
           intPhoneNomber = stringToInt (strPhoneNomber);
           existNumber = checkExistNumber(phonebook,intPhoneNomber);

           if (!existNumber)
           {
               std::cout << "This number doesn't exist. Try again\n";
           }
           else
           {
               std::cout << res;
               std::cout << phonebook [intPhoneNomber] << std::endl;
               std::cout << line;
           }
       }

       else if (answer == 3)
       {
           std::cout << "Enter surname \n";
           std::cin >> surname;
           existSurname = checkExistSurname(phonebook, surname);
           if (!existSurname)
           {
                std::cout << "This surname doesn't exist. Try again\n";
           }
           else
           {
               std::cout << res;
               for (std::map <int, std::string>::iterator it = phonebook.begin();
                    it != phonebook.end (); ++it)
               {
                   if (it->second == surname)
                   {
                       std::cout << it->first << std::endl;
                   }
               }
              std::cout << line;
           }
       }

       else if (answer == 4)
       {
           std::cout << res;
           showPhonebook(phonebook);
           std::cout << line;
       }

       else if (answer == 0)
       {
            std::cout << "EXIT\n";
            break;
       }

       else
       {
            std::cout << "Number incorrect. Please try again\n";
       }
   }

    return 0;
}