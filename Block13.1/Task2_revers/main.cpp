#include <iostream>
#include <vector>

int main() {

    int n = 0;
    std::cout << "Enter amount of numbers\n=>";
    std::cin >> n;
    std::vector <float> vec (n);
    for (int i = 0; i < n; i++){
        std::cout << "=>";
        std::cin >> vec [i];
    }

    for (int i = n - 1; i >= 0; i--){
        std::cout << vec [i] << ", ";
        }
    std::cout << std::endl;
    return 0;
}
