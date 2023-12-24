#include <iostream>
#include <fstream>
#include <string>

void creerMassa (std::string const & nom) {
    std::ofstream f {nom, std::ios::app};
    if (!f) {
        throw std::runtime_error("Exception des exceptions");
    }
    f << "Dans mon projet ça ne marche pas. Ici Eh ça marche même Jizus\n";
    f.close();
}

int main () {
    std::string const nom = "test_massa";
    creerMassa(nom);
    return 0;
}
