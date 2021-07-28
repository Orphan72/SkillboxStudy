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

   std::vector <int> vec;
    int num = 0;

     while (num != -1){
        std::cout << "Enter your number\n=>";
        std::cin >> num;
        vec = add (vec, num);
    }

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec [i] << " ";
    }

    return 0;
}





