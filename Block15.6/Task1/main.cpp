#include <iostream>
#include <vector>

int main()
{
   std::vector <int> vec = {-2,1,-3,4,-1,2,1,-5,4};
   // std::vector <int> vec = {0, 0, 10, -1};
   int size = vec.size();
   int maxsum = 0;
   int maxstart = 0;
   int maxend = 0;
   int sum = 0;
   int minpos = -1;


    for (int i = 0; i < size; i++)
    {
        sum = sum + vec [i];
        if (sum > maxsum)
        {
            maxsum = sum;
            maxend = i;
            maxstart = minpos + 1;
        }

        if (sum < 0)
        {
            sum = 0;
            minpos = i;
        }
    }

    std::cout << "maxsum " << maxsum << std::endl;
    std::cout << "maxstart " << maxstart << std::endl;
    std::cout << "maxend " << maxend << std::endl;

    return 0;
}
