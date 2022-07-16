#include <iostream>
#include <map>
#include <string>
#include <vector>


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
        if (it->second == str) return it->first;
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
    sortVec (vec);
    int key = findKey(oMap, vec [0]);
    std::map <int, std::string>::iterator itf = oMap.find(key);
    std::cout << itf->second << std::endl;
    oMap.erase(itf);

    for (int i = 0; i < vec.size() - 1; i++)
    {
        vec [i] = vec [i + 1];
    }
    vec.pop_back();
}

int main()
{
    std::map <int, std::string> ownMap;
    std::vector<std::string> ownVec;
    std::string answer = " ";
    int num = 0;

    std::cout << "Enter surname\nor\n";
    std::cout << "For call first person enter \'Next\'\n";
    std::cout << "For exit enter \'0\'\n";

    while (true)
    {
        std::cout << "=>";
        std::cin >> answer;
        if (answer != "Next" && answer != "0")
        {
            addPair (ownMap, num, answer, ownVec);
            num++;
        }
        else if (answer == "Next")
        {
            if (ownMap.empty())
                std::cout << "Map is empty!\n";
            else
                showFirst (ownMap, ownVec);
        }
         else break;
    }

    return 0;
}
