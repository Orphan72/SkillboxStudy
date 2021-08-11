#include <iostream>
#include <vector>

int main() {

    std::vector<float> price = {0.5, 1.25, 2.25, 3.75, 4.0};
    std::vector<float> purchase = {1, 1, 0, 3, 1};
    float total = 0.0;

    for (int i = 0; i < purchase.size(); i++) {
        total += price [purchase [i]];
    }

    std::cout << "Total cost is: " << total  << std::endl;

    return 0;
}





