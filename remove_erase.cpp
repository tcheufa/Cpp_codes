#include <iostream>
#include <vector>
#include <algorithm>

int main () {

    /* Learning std::remove and std::erase */

    std::string paroles {"bee baa boo je chante comme un pou"};
    std::cout << "size = " << paroles.size() << std::endl;
    auto end_iterator {std::remove(std::begin(paroles), std::end(paroles), 'b')};
    std::cout << "remove : " << paroles << std::endl;
    std::cout << "size = " << paroles.size() << std::endl;
    paroles.erase(end_iterator, std::end(paroles));
    std::cout << "erase : " << paroles << std::endl;
    std::cout << "size = " << paroles.size() << std::endl;

    return 0;
}
