#include <iostream>
#include <vector>

void displayVector (std::vector<int> vec) {
    for (int i = 0; i < vec.size() - 1 ; i++){
        std::cout << vec [i] << " ";
    }
}

int main() {

    std::vector<int> database;
    int number = 0;
    const int SIZE = 20;

    for (int i = 0; number != -1; i++) {
        std::cout << "Enter number\n=>";
        std::cin >> number;
        database.push_back (number);

        if (database.size() > SIZE + 1) {
            for (int j = 0; j < database.size(); j++){
                database [j] = database [j + 1];
            }
            database.pop_back();
        }

        if (number == -1)
            displayVector (database);
    }
    return 0;
}
