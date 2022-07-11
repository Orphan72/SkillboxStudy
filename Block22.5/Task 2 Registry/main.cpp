#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::vector<std::string> SURNAMELIST
{
    "Sido", "Yan", "Ivanov", "Petrov", "Ivanov", "Kozlov"
};

void sortVec (std::vector <std::string> &vec)
{
    for (int i = 0; i < vec.size() ; i++)
    {
        for (int j = 0; j < vec.size() - 1; j++)
        {
            if (vec [j + 1] < vec [j])
            {
                std::string tmp = vec [j];
                vec [j] = vec [j + 1];
                vec [j + 1] = tmp;
            }
        }
    }
}

void addPair (std::map <int, std::string> &oMap, int nm, std::string str, std::vector<std::string> &vec)
{
    std::pair<int, std::string> oPair (nm, str);

    oMap.insert(oPair);
    vec.push_back(oPair.second);

}

int findKey (std::map <int, std::string> oMap, std::string str)
{
    for (std::map <int, std::string>::iterator it = oMap.begin();
         it != oMap.end (); ++it)
    {
        if (it->second == str)
        {
            std::cout << "We've found " << it->second << std::endl;

            return it->first;
        }
    }
}

void showVec (std::vector<std::string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec [i] << std::endl;
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

void showFirst (std::map <int, std::string> &oMap, std::vector<std::string> &vec)
{

    std::cout << "Vector:\n";
    showVec(vec);
    std::cout << "Sort vector:\n";
    sortVec (vec);
    showVec(vec);

    std::cout << "Map:\n";
    showMap(oMap);

    std::cout << "First is " << vec[0] << std::endl;

    int key = findKey(oMap, vec [0]);

    std::cout << "Key is " << key  << std::endl;


    std::map <int, std::string>::iterator itf = oMap.find(key);


            //findKey(oMap, vec[0]);

    std::cout << itf->second << std::endl;

    oMap.erase(itf);

    std::cout << "New map:\n";

    showMap (oMap);


    for (int i = 0; i < vec.size() - 1; i++)
    {
        vec [i] = vec [i + 1];
    }
    vec.pop_back();

    showVec (vec);

}








int main()
{
    std::map <int, std::string> ownMap;
    std::vector<std::string> ownVec;
    std::string answer = " ";
    int num = 0;

    while (true)
    {
        std::cout << "Enter surname\nor\n";
        std::cout << "For call first person enter \'Next\'\n";
        std::cout << "For show all map enter \'1\'\n";
        std::cout << "For exit enter \'0\'\n";
        std::cin >> answer;
        if (answer != "Next" && answer != "0" && answer != "1" && answer != "2")
        {
            addPair (ownMap, num, answer, ownVec);
            num++;
        }
        else if (answer == "Next")
        {
            showFirst (ownMap, ownVec);
        }
        else if  (answer == "1")
        {
            showMap(ownMap);
        }
        else if  (answer == "2")
        {
            showVec(ownVec);
            std::cout << "Sort:\n";
            sortVec (ownVec);
            showVec(ownVec);
        }

        else break;
    }




    return 0;
}
