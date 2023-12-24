#include <iostream>
#include <algorithm>
#include <vector>

bool is_all_positive (std::vector<auto> collection)
{
    return std::all_of(
        std::cbegin(collection),
        std::cend(collection),
        [](auto x) -> bool {return x >= 0;}
    );
}


int main () {
    std::vector<float> integers {1., 2., 3., 4., 5., 5., 5., 56., -0};

    std::cout << std::boolalpha << "Cette collection est entièrement positive : " << is_all_positive(integers) << std::endl;


}
