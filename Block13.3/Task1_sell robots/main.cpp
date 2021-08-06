#include <iostream>
#include <vector>

int main() {
    int num = 0;
    int index = 0;
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

    while (vec.size() != 0) {
        std::cout << "Enter index:\n";
        bool correncIndex = false;
        while (!correncIndex) {
            std::cin >> index;
            correncIndex = (index > 0 && index <= vec.size());
            if (!correncIndex) {
                std::cout << "index incorrect! Try again\n";
            }
        }
            
            for (int i = (index - 1); i < (vec.size() - 1); i++) {
                vec[i] = vec[i + 1];
            }
            vec.resize(vec.size() - 1);
			for (int i = 0; i < vec.size(); i++) {
                std::cout << vec[i] << " ";
            }
    }

    if (vec.size() == 0){
        std::cout << "All robots were sold";
    }

    return 0;
}
