#include <iostream>

const int N = 15;
int getMin (int num [N]) {
    int min = num [0];
    for (int i = 1; i < N; i++)
    {
        if (num [i] < min)
            min = num [i];
    }
   return min;
 }

int getDouble (int min, int num [N]) {
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < 7; j++) {
            if (num [j] == min) {
                num[j] = 0;
                break;
             }
         }
         min++;
     }
     for (int i = 0; i < N; i++) {
         if (num [i] != 0)
             return num [i];
     }
    return 0;
  }

int main() {

    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
    int minimum = getMin(numbers);
    int doubled = 0;
    std::cout << "min: " << minimum << std::endl;
    doubled = getDouble(minimum, numbers);
    std::cout << "doubled: " << doubled << std::endl;
    return 0;
}