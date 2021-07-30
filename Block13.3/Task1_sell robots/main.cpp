#include <iostream>
#include <vector>

int main() {
    int num = 0;
    std::cout << "Enter count of robots\n=>";
    std::cin >> num;
    std::vector <int> vec (num);

    for (int i = 0; i < vec.size(); i++){
        std::cout << "Enter robot's number\n=>";
        std::cin >> vec [i];
    }

    std::cout << "There are robots at the showcase:\n";

    for (int i = 0; i < vec.size(); i++){
        std::cout << vec [i] << " ";
    }


    return 0;
}
