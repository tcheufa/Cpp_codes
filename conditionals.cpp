#include <iostream>
#include <vector>


bool myXOR (bool a, bool b) {
    return (a && !b) || (!a && b);
}


 int main () {
// Learning about booleans

    std::cout << std::boolalpha;
    std::cout << std::endl << (true xor true) << std::endl; // prints `0`
    std::cout << std::endl << myXOR (true, true) << std::endl; // prints `false`
    std::cout << (1. == 1) << std::endl;
    exit(0);


// Learning about conditionals

    int age {};

    std::cout << "Veuillez me donner votre âge : " << std::endl;
    while (!(std::cin >> age)) {
        std::cout << "Un peu de sérieux, voyons!\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
        std::cout << "Veuillez me donner votre âge : " << std::endl;
    }
    if (age > 20) {
        std::cout << "Vous êtes donc mon aîné !";
    }
    else {
        std::cout << "Vous êtes donc mon cadet !";
    }

    return 0;
}
