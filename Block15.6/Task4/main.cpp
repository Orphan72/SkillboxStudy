#include <iostream>
#include <vector>

int main()
{
    std::vector <int> vect = {-100,-50, -5, 1, 10, 15};
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.size() - 1; j++)
        {
            if (vect [j] < 0)
            {
                if (vect [j + 1] < 0)
                {
                    //case 1
                    if (vect [j] < vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
                else if (vect [j + 1] >= 0)
                {
                    //case 2
                    if (-vect [j] > vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
            }

            else if (vect [j] >= 0)
            {
                if (vect [j + 1] < 0)
                {
                    //case 3
                    if (vect [j] > -vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
                else if (vect [j + 1] >= 0)
                {
                    //case 4
                    if (vect [j] > vect [j + 1])
                    {
                        int temp = vect [j];
                        vect [j] = vect [j + 1];
                        vect [j + 1] = temp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect [i] << " ";
    }

    return 0;
}
