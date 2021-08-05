#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int num = 0;
    while (num != -1) {
        std::cout << "Enter number of robot\n=>";
        std::cin >> num;
        vec.push_back(num);
        for (int i = 0; i < vec.size(); i++) {
            while (num > vec[i]) {
                int index = i;
                vec.resize(vec.size() - 1);
                for (int j = index; j < vec.size(); j++) {
                    vec[j] = vec[j + 1];
                }
            }
        }

        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    }
    return 0;
}
