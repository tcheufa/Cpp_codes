#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

void secured_cin (auto & dest) {
    while (!(std::cin >> dest)) {
        if (std::cin.eof())
            throw std::runtime_error("Le flux a été fermé.");
        std::cout << "Entrée incorrecte !\nVeuillez réessayer : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main () {
    struct InfosPersonnelles {
        std::string nom {};
        std::string prenom {};
        unsigned age {};
        char sexe {};
    };

    auto demanderInfos = [] (InfosPersonnelles & infos) -> std::string {
        std::cout << "Nom ? ";
        secured_cin(infos.nom);
        std::cout << "Prenom ? ";
        secured_cin(infos.prenom);
        std::cout << "Sexe ? ";
        secured_cin(infos.sexe);
        infos.sexe = std::toupper(infos.sexe);
        std::cout << "Age ? ";
        secured_cin(infos.age);
        return "../" + infos.nom + '.' + infos.prenom + ".csv";
    };
    auto stockerInfos = [] (const InfosPersonnelles & infos, const std::string nom_fichier) -> void {
        std::ofstream csv {nom_fichier};
        csv << infos.nom << ',' << infos.prenom << ',' << infos.sexe << ',' << infos.age << '\n';
        csv.close();
    };

    InfosPersonnelles infos {};
    std::string nom_fichier {demanderInfos(infos)};
    stockerInfos(infos, nom_fichier);

    std::cout << "Les informations ont été enregistrées avec succès dans le fichier " << nom_fichier << std::endl;

    return 0;
}
