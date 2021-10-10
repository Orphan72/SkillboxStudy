#include <iostream>
#include <vector>

int main()
{
   std::vector <int> vec = {-2,1,-3,4,-1,2,1,-5,4};
   int size = vec.size();
   int maxsum = 0;
   int maxstart = 0;
   int maxend = 0;
   int sum = 0;

   for (int i = 1; i < size; i++)
   {
       for (int j = 0; j < (size - i); j++)
       {
            for (int k = j; k < (size - i + 1); k++)
            {
               sum += vec[k];
            }
            if (sum > maxsum)
            {
                maxsum = sum;
                maxstart = j;
                maxend = size - i;
            }
            sum = 0;
        }
    }

    std::cout << "maxsum " << maxsum << std::endl;
    std::cout << "maxstart " << maxstart << std::endl;
    std::cout << "maxend " << maxend << std::endl;

    return 0;
}
