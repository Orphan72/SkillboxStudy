#include <iostream>
#include <vector>

std::vector <int> sort (std::vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                vec[j] = vec[j] + vec[j + 1];
                vec[j + 1] = vec[j] - vec[j + 1];
                vec[j] = vec[j] - vec[j + 1];
            }
        }
    }
    return vec;
}

int main()
{
    const int INDEX = 5;
    std::vector <int> vect;
    int number = 0;

     while (number != -2)
     {
         std::cout << "Enter numbers \n=>";
         std::cin >> number;
         vect.push_back(number);
         if (number == -1)
         {
             vect.pop_back();
             vect = sort(vect);
             if (vect.size() < INDEX)
             {
                 std::cout << INDEX  << " member doesn't exist " << std::endl;
             }
             else
             {
                 std::cout << INDEX  << " member is " << vect[INDEX - 1] << std::endl;
             }
         }
         else if (number == -2)
             std::cout << "Bye " << std::endl;
     }
    std::cout << std::endl;
    return 0;
}