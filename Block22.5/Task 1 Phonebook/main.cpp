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
    int exist = 0;
    while (vec.size() < SURNAMELIST.size())
    {
        int diffNumber = MAXNUMBER - MINNUMBER;
        int num = std::rand() % (diffNumber + 1) + MINNUMBER;


        for (int i = 0; i < vec.size(); i++)
        {
            if (num == vec[i])
            {
                exist++;
            }
        }
        if (!exist) vec.push_back(num);
        else
        {
            std::cout << "Number "<< num << " busy\n";
            exist = 0;
        }

        //exist = false;
    }
}





;




void fullMap (std::map <int, std::string> &oMap)
{
    oMap.insert(std::make_pair<int, std::string>(12348, "ten"));
    oMap.insert(std::make_pair<int, std::string>(11, "eleven"));
    oMap.insert(std::make_pair<int, std::string>(8, "eight"));
    oMap.insert(std::make_pair<int, std::string>(6, "six"));
    oMap.insert(std::make_pair<int, std::string>(7, "seven"));
    oMap.insert(std::make_pair<int, std::string>(12, "twelve"));
    oMap.insert(std::make_pair<int, std::string>(2, "two"));

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
    std::map <std::vector<int>, std::string> phonebook;
    std::vector <int> vecNumber;


    fullVector(vecNumber);

    for (int i = 0; i < vecNumber.size(); i++)
    {
        std::cout << i+1 << " - " <<  vecNumber[i] << std::endl;
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





     //hoursStart = 10* (start[0] - '0') + (start[1] - '0');
     //minutesStart = 10* (start[3] - '0') + (start[4] - '0');

   // hoursStart = '0';
    //minutesStart = 10* (start[3] - '0') + (start[4] - '0');



    //std::cout << hoursStart << std::endl;
    //std::cout << minutesStart << std::endl;



        std::cout << "Hello, World!" << std::endl;

        */
    return 0;
}
