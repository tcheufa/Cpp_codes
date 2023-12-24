#include <iostream>


void rectangle (unsigned width, unsigned height) {
    int i {0}, j {0};

    --height; // the purpose of this is to print a rectangle with no unnecessary endlines at the end or at the begining
    for (; i < height; i++) {
        for (j = 0; j < width; j++)
            std::cout << "*";

        std::cout << '\n';
    }
    for (j = 0; j < width; j++)
            std::cout << "*";

}

int main () {

    /* Learning functions */
    /* Ex: Print a rectangle */
    rectangle(14, 3);


    return 0;
}
