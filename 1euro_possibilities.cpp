#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () {

    unsigned nb10c {0};
    unsigned nb5c {0};
    unsigned nb2c {0};
    unsigned nb_possibilities {0};

    for (; nb2c < 100; nb2c++) {
        for (nb5c = 0; nb5c < 100; nb5c++) {
            for (nb10c = 0; nb10c < 100; nb10c++) {
                if (nb10c*10 + nb5c*5 + nb2c*2 == 100) {
                    cout << "1 euro = "
                        << setw(4) << nb2c << " X 2c, "
                        << setw(4) << nb5c << " X 5c, "
                        << setw(4) << nb10c << " X 10c"
                        << '\n';
                    ++nb_possibilities;
                }
            }
        }
    }
    cout << "Il y en tout " << nb_possibilities << " possibilités " << endl;

    return 0;

}
