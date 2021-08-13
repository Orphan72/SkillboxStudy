#include <iostream>
#include <vector>

int main() {
    int count = 0;
    int num = 0;
    std::cout << "Enter count of elements\n=>";
    std::cin >> count;
    std::vector<int> vec (count);

    for (int i = 0; i < count; i++){
        std::cout << "Enter " << i + 1 << " element\n=>";
        std::cin >> vec [i];
    }

    std::cout << "Initial vector:\n";
    for (int i = 0; i < vec.size(); i++){
        std::cout << vec [i] << " ";
    }
    std::cout << "Enter number\n=>";
    std::cin >> num;

    int n = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec [i] != num) {
            vec [n++] = vec [i];
        }
    }
    vec.resize(n);

    std::cout << "Final vector:\n";
    if (vec.empty()) {
        std::cout << "Vector is empty\n";
    }
    else {
        for (int i = 0; i < vec.size(); i++){
            std::cout << vec [i] << " ";
        }
    }

    return 0;
}
