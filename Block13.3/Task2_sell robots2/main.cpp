#include <iostream>
#include <vector>

int main() {
    int num = 0;
    int index = 0;
    int countReq = 0;
    int kindReq = 0;

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

    std::cout << "Enter count of request (K) \n=>";
    std::cin >> countReq;

    for (int i = 0; i < countReq; i++) {

        std::cout << "Enter kind of request (1 or 2)\n=>";
        bool correctKind = false;
        while (!correctKind) {
            std::cin >> kindReq;
            correctKind = (kindReq == 1 || kindReq == 2);
            if (!correctKind)
            {
                std::cout << "Incorrect kind of request. Try again\n";
            }
        }

        if (kindReq == 1) {
            std::cout << "Enter number\n=>";
            std::cin >> num;
            vec.resize(vec.size() + 1);
            vec[vec.size() - 1] = num;

            std::cout << "There are robots at the showcase:\n";
            for (int i = 0; i < vec.size(); i++) {
                std::cout << vec[i] << " ";
            }
        }
        else {
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

            if (vec.size() == 0) {
                std::cout << "All robots were sold";
                break;
            }
        }
    }

    return 0;
}
