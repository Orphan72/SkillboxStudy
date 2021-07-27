#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cout << "Enter amount of numbers\n=>";
    std::cin >> n;
    std::vector <int> vec (n);
    for (int i = 0; i < n; i++){
        std::cout << "=>";
        std::cin >> vec [i];
    }

    int max = 0;
    for (int i = 1; i < n; i++){
        if (vec [i] > max){
            max = vec [i];
        }
    }
    int first = max, second = max;
    for (int i = 0; i < n; i++){
        if (vec [i] < first) {
            second = first;
            first = vec [i];
        }
        else if (vec [i] < second) {
            second = vec [i];
         }
    }
    std::cout << "Second number is " << second << std::endl;
    return 0;
}
