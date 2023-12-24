#include <iostream>
#include <limits>
#include <stdexcept>


using namespace std; // Great discovery ! No more de std::cout, just cout !

void secured_cin (auto & dest) {
    while (!(cin >> dest)) {
        if (cin.eof())
            throw runtime_error("Le flux a été fermé.");
        cout << "Entrée incorrecte !\nVeuillez réessayer : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main () {

    /* Learning references and exceptions */
    try {
        int entier {};
        cout << "Saisir un entier : ";
        secured_cin(entier);
        int & ref_entier {entier};
        cout << "Entier : " << entier;
        cout << "\nRéférence : " << ref_entier;
    }
    catch (runtime_error const & e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}

