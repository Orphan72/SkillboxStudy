#include <iostream>
#include <vector>


int main() {

    const int SIZE = 10;
    std::vector<int> database (SIZE);
    for (int j = 0; j < database.size(); ++j){
        std::cout << database [j] << " ";
    }
    int surpos = 0;
    int number = 0;
    std::cout << "Enter number first\n=>";
    std::cin >> number;
    while (number != -2) {

    if (number == -1)
        {
            for (int j = 0; j < surpos; ++j){
                std::cout << database [j] << " ";
            }

            for (int j = surpos; j < database.size() ; ++j){
                std::cout << database [j] << " ";
            }
       }

    else {
        database[surpos] = number;
        surpos++;
        if (surpos == SIZE)
            surpos = 0;
    }

        std::cout << "Enter number second\n=>";
        std::cin >> number;
    }




    return 0;
}
