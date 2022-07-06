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

void addPair (std::map <int, std::string> &oMap, int num, std::string str, std::vector<std::string> &vec)
{
    std::pair<int, std::string> oPair (num, str);

    oMap.insert(oPair);
    vec.push_back(oPair.second);

}

std::map <int, std::string>::iterator findKey (std::map <int, std::string> oMap, std::string str)
{
    for (std::map <int, std::string>::iterator it = oMap.begin();
         it != oMap.end (); ++it)
    {
        if (it->second == str)
        {
            return it;
        }
    }
}


void showFirst (std::map <int, std::string> &oMap, std::vector<std::string> &vec)
{
    sortVec (vec);
    std::map <int, std::string>::iterator itf = findKey(oMap, vec[0]);

    std::cout << itf->second << std::endl;

    oMap.erase(itf);
    for (int i = 0; i < vec.size() - 1; i++)
    {
        vec [i] = vec [i + 1];
    }
    vec.pop_back();
}

void showMap (std::map<int, std::string> oMap)
{
    for (std::map <int, std::string>::iterator it = oMap.begin();
         it != oMap.end (); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void showVec (std::map<int, std::string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec [i] << std::endl;
    }
}





int main()
{
    std::map <int, std::string> ownMap;
    std::vector<std::string> ownVec;


    for (int i = 0; i < SURNAMELIST.size(); i++)
    {
        std::string surname = " ";
        std::cout << "Enter surname\n=>";
        surname = SURNAMELIST[i];
        addPair (ownMap, i, surname, ownVec);
    }


    std::cout << "======= MAP ===========\n";



    return 0;
}
