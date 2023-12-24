#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main () {
    std::vector<int> integers {1, 2, 3, -4, -5, 5, 5, 56, -0};

    std::cout << "Tableau non trié : \n";
    for (int const integer : integers) {
        std::cout << integer << "  ";
    }

    std::sort(std::begin(integers), std::end(integers), [] (auto a, auto b) -> bool {return std::abs(a) < std::abs(b);});

    std::cout << "\n\nTableau trié : \n";
    for (int const integer : integers) {
        std::cout << integer << "  ";
    }
}
