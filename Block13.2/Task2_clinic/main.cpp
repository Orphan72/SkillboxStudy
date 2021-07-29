#include <iostream>
#include <vector>

std::vector<int> add (std::vector<int> vec, int n) {
    std::vector<int> newVec (vec.size() + 1);
    for (int i = 0; i < vec.size(); i++) {
        newVec [i] = vec [i];
    }
    newVec [vec.size()] = n;
    return newVec;
}

int main() {
    int ages = 0;
    std::vector <int> vec;
    int sum = 0;
    float average = 0.0;

    while (ages != -1){
        std::cout << "Enter age\n=>";
        std::cin >> ages;
        vec = add (vec, ages);
    }

    for (int i = 0; i < (vec.size() - 1); i++) {
        sum += vec [i];
    }
    average = sum/(vec.size() - 1);

    std::cout << "average is " << average;
    return 0;
}
