#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdlib>


int main()
{
    int control_sum = 0;
    std::vector <int> buildings;
    int count = std::rand () %901 + 100;
    for (int i = 0; i < count; i++)
    {
        buildings.push_back(std::rand () %51);
        control_sum += buildings [i];
    }

    std::cout << "Control_sum is "<< control_sum << std::endl;
    std::ofstream file ("..\\data\\buildings.txt");
    file << count << std::endl;

    for (int i = 0; i < count; i++)
    {
        file << buildings [i] << std::endl;
    }
    file << "SkillCity" << std::endl;

    file.close();

        std::ifstream in_file ("..\\data\\buildings.txt");
        std::vector <int> in_buildings;
        int in_count;
        int in_sum = 0;
        in_file >> in_count;

        for (int i = 0; i < in_count; i++)
        {
            int in_people;
            in_file >> in_people;
            in_buildings.push_back(in_people);
        }

        std::string in_city;
        in_file >> in_city;


        for (int i = 0; i < in_count; i++)
        {
            in_sum += in_buildings [i];
        }



        std::cout << "Population of " << in_city << " is "<< in_sum << std::endl;



}

