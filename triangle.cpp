#include <iostream>
using namespace std;

void iso_triangle (unsigned height, char symbol = '*') {

    // le nombre d'étoiles suivent une suite arithmétique de raison 2 et de premier terme 1 (Un = 1 + 2n);
    unsigned base {1 + 2 * height};
    unsigned middle {base/2. + 0.5};
    unsigned spaces {middle - 1};
    unsigned stars {0};
    unsigned j {};
    unsigned i {0};
    for (; i < height; i++) {
        stars = 1 + 2*i;
        --spaces;
        for (j = 0; j <= spaces; j++) {
            cout << ' ';
        }
        for (j = 0; j < stars; j++) {
            cout << symbol;
        }
        cout << '\n';
    }

}

int main () {

    unsigned height {};
    cout << "Entrer la hauteur du triangle : ";
    cin >> height;
    iso_triangle(height, '.');

    return 0;
}
