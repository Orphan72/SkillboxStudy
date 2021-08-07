#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int num = 0;
    while (num != -1) {
        std::cout << "Enter number of robot\n=>";
        std::cin >> num;
        vec.push_back(num);
        for (int i = 0; i < vec.size(); i++) {
            while (num > vec[i]) {
                int index = i;
                for (int j = index; j < (vec.size() - 1); j++) {
                    vec[j] = vec[j + 1];
                }
                vec.pop_back();
            }
        }
    }

    for (int i = 0; i < vec.size() - 1; i++) {
        std::cout << vec[i] << " ";
    }
    return 0;
}
