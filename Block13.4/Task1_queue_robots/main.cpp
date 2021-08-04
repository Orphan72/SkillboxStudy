#include <iostream>
#include <vector>

int main() {
    std::vector <int> vec;
    int num = 0;
    while (num != -1) {
        std::cout << "Enter number of robot\n=>";
        std::cin >> num;
        vec.push_back(num);
        if (num != -1) {
            for (int i = 0; i < vec.size(); i++) {
                std::cout << vec[i] << " ";
            }
        }
        else {
            for (int i = 0; i < (vec.size() -1); i++) {
                std::cout << vec[i] << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
