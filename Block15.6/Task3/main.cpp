#include <iostream>
#include <vector>

std::vector <int> sort (std::vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1; j++)
        {
            if (vec[j] > vec[j + 1]) {
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
    std::vector <int> vect;


    int number = 0;

 //while (true)
 //{

     while (number != -2)
     {
         std::cout << "Enter numbers \n=>";
         std::cin >> number;
         vect.push_back(number);
         if (number == -1)
         {
             vect.pop_back();
             vect = sort(vect);
             for (int i = 0; i < vect.size(); i++)
             {
                 std::cout << vect[i] << " ";
             }
         }
         else if (number == -2)
             std::cout << "Bay " << std::endl;


     }

     //std::cout << "Bay " << std::endl;
       //  break;

 //}


    std::cout << std::endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}





/*

С клавиатуры вводятся числа. Когда пользователь вводит -1 --
необходимо выводить на экран пятое по возрастанию число среди введённых.
Когда пользователь вводит -2 -- программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1

вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})

ввод: 1 1 1 -1

вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})

ввод -2

завершение программы
*/