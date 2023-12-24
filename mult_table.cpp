#include <iostream>
#include <iomanip>

#define INDENT_SIZE (4)

using namespace std;

int main(void){

    unsigned first_number {};
    unsigned last_number {};

    cout << "Table de multiplication \nEntrer le commencement et la fin de ce tableau : ";
    cin >> first_number >> last_number;

    int i, j;

    cout << "\nTable de multiplication de " << first_number << " à " << last_number <<":\n\n" ;

    /* First indentation I */
    cout << setw(7) << 'I';
    for (i = 1; i <= last_number; i++) {
        cout << setw(INDENT_SIZE) << i;
    }

    /* Horizontal bar */
    cout << '\n';
    unsigned line_width {last_number * INDENT_SIZE + 7};
    for (i = 1; i <= line_width; i++) {
        cout << '-';
    }

    /* Multiplication table fill */
    for (i = 1; i <= first_number; i++) {
        cout << '\n' << setw(INDENT_SIZE) << i << setw(3) << 'I';
        for (j = 1; j <= last_number; j++) {
            cout << setw(INDENT_SIZE) << (i * j);
        }
    }
    cout << endl;

    return 0;
}
