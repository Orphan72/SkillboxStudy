#include <iostream>
#include <vector>

int main()
{
    std::vector <int> vec = {2, 7, 11, 15};
    int result = 22;
    bool pairfound = false;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size() - 1; j++)
        {
            int sum = vec[i] + vec[j + 1];
            if (sum == result)
            {
                std::cout << "pair is " << vec[i] << " and " << vec[j + 1] << std::endl;
                pairfound = true;
                break;
            }
        }
        if (pairfound) break;
    }

    return 0;
}

