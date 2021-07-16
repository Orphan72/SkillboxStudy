#include <iostream>

int main() {

    const int FLATS = 10;
    const int CHOISE = 3;
    std::string tenants [FLATS];
    int number = 0;
    for (int i = 0; i < FLATS; i++){
        std::cout << "Enter Full name " << (i+1) << " tenant\n=>";
        std::getline(std::cin, tenants[i]);
    }

    for (int i = 0; i < CHOISE; i++){
        bool correctNumber = false;
        std::cout << "Enter number of flats from 1 to " << FLATS << "\n=>";
        while (!correctNumber){
            std::cin >> number;
            correctNumber = (number > 0 && number <= FLATS);
            if (!correctNumber)
              std::cout << "Number incorrect\nTry again\n";
        }
        std::cout << "In the flat number " << number << " lives " << tenants[number-1] << std::endl;
    }

    return 0;
}
