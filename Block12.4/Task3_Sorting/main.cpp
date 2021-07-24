#include <iostream>

int main() {

    int const N = 5;
    float number [N];

    std::cout << "Enter " << N << " numbers\n";

    for (int i = 0; i < N; i++){
        std::cout << "=>";
        std::cin >> number [i];
    }

    float min = 0.0;
    int pos = 0;

    std::cout << "Not sorted:\n";
    for (int i = 0; i < N; i++){
        std::cout << number [i] << ", ";
    }
    std::cout << std::endl;

   for (int j = 0; j < N; j++) {
       min = number[j];
       for (int i = j; i < N; i++) {
           if (number[i] <= min) {
               min = number[i];
               pos = i;
           }

       }

       number[pos] = number[j];
       number[j] = min;
   }

   std::cout << "Sorted:\n";
    for (int i = 0; i < N; i++) {
        std::cout << number[i] << ", ";
    }

    return 0;
}
