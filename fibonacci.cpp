#include <iostream>

using namespace std;

int main() {

    unsigned Uminus1 {1}; // Initialised at U1 = 1
    unsigned Uminus2 {1}; // Initialised at U2 = 1
    unsigned Un {1}; // Initialised at U3 = 2
    unsigned n {};

    cout << "Suite de Fibonnacci\n\nDonner la valeur de n : ";
    cin >> n;

    for (unsigned i {3}; i <= n; i++) {
        Un = Uminus1 + Uminus2;
        Uminus2 = Uminus1;
        Uminus1 = Un;
//        cout << "i = "<< i << "Ui-2 = " << Uminus2 << " Ui-1 = " << Uminus1 <<" Ui = " << Un << endl;
    }

    cout << "U" << n << " = " << Un;
    return 0;
}
