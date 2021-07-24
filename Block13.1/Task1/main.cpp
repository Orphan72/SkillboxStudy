#include <iostream>
#include <vector>

int main() {
    int N = 0;
    int sum = 0;
    std::cout << "Enter amount of numbers\n=>";
    std::cin >> N;
    std::vector <int> vec (N);
    std::cout << "Enter numbers\n";
    for (int i = 0; i < N; i++){
        std::cout << "=>";
        std::cin >> vec [i];
        sum += vec [i];
    }
    float average = sum/N;
    std::cout << "Average is " << average << std::endl;

 return 0;
}


/*
Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
Необходимо вычислить их среднее арифметическое и вывести на экран.
 */