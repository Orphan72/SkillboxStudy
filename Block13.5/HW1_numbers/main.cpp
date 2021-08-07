#include <iostream>
#include <vector>

int main() {
    int count = 0;
    std::cout << "Enter count of elements\n=>";
    std::cin >> count;
    std::vector<int> vec (count);

    for (int i = 0; i < count; i++){
        std::cout << "Enter " << i + 1 << " element\n=>";
        std::cin >> vec [i];
    }

    for (int i = 0; i < vec.size(); i++){
        std::cout << vec [i] << " ";
    }

    int num = 0;
    int index = 0;
    std::cout << "Enter number\n=>";
    std::cin >> num;

    for (int i = 0; i < vec.size(); i++) {
        if (vec.size() == 1 && vec[0] == num) {
            vec.clear();
        }
        else {
            while (vec[i] == num) {
                index = i;
                for (int j = index; j < vec.size() - 1; j++) {
                    vec[j] = vec[j + 1];
                }
                vec.pop_back();
            }
        }
    }

    if (vec.empty()){
        std::cout << "Vector is empty\n";
    }
    else {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    }

    return 0;
}
