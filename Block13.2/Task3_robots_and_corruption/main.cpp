#include <iostream>
#include <vector>


std::vector<int> add_to_position(std::vector <int> vec, int val, int position)
{
    std::vector<int> newVec (vec.size() + 1);
    int index = position - 1;
    for (int i = 0; i < index; i++)
    {
        newVec [i] = vec [i];
    }

    newVec [index] = val;
    for (int i = index; i < vec.size(); i++)
    {
       newVec [i + 1] = vec [i];
    }

    return newVec;
}


int main() {
    std::vector <int> vec = {10, 12, 5, 7, 9, 11, 3};
    int num = 0;
    int pos = 0;

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec [i] << " ";
    }

        std::cout << "Enter your number\n=>";
        std::cin >> num;

        std::cout << "Enter your position\n=>";
        std::cin >> pos;
        vec = add_to_position (vec, num, pos);

        for (int i = 0; i < vec.size(); i++) {
        std::cout << vec [i] << " ";
    }

    //}

    //for (int i = 0; i < vec.size(); i++) {
      //  std::cout << vec [i] << " ";
    //}

    return 0;
}
