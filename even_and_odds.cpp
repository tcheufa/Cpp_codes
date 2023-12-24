#include <iostream>
#include <vector>


int main () {

    /* Ex : Division of a vector of numbers into two vectors, one of even numbers and another of odd ones  */

    std::vector<int> tab = {1, 4, 5, 6, 8, 10, 13, 11, 12, 4};
    std::vector<int> evens = {};
    std::vector<int> odds = {};

//     special method : with a vector pointer
    std::vector<int>* selected;

    for (int const number : tab) {
//         with vector pointer (my favorite)
        selected = (number % 2 == 0) ? &evens : &odds;
        (*selected).push_back(number);

//         simplier method I guess
//        if (number % 2 == 0) {
//            evens.push_back(number);
//        }
//        else {
//            odds.push_back(number);
//        }
    }



    /* Printing process is same for both methods */
    std::cout << "Nombres : impairs :";
    for (int const odd : odds) {
        std::cout << std::endl << odd;
    }

    std::cout << std::endl << "Nombres : pairs :";
    for (int const even : evens) {
        std::cout << std::endl << even;
    }
    return 0;
}
