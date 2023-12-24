#include <iostream>
#include <vector>


int main () {

    /* Exo : Calculate the average */
    std::vector<float> notes {};
    float note {};
    std::cout << "Calcul de la moyenne :" << std::endl;
    std::cout << "Note : Validez avec un nombre négatif pour mettre fin au remplissage des notes" << std::endl;
    int i {0};
    while(true) {
        std::cout << "Entrer votre " << i+1 << ((i == 0) ? "ère" : "e") << " note : ";
        while (!(std::cin >> note)) {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Entrée incorecte" << std::endl;
            std::cout << "Entrer votre " << i+1 << ((i == 0) ? "ère" : "e") << " note : ";
        }
        if (note < 0) break;
        notes.push_back(note);
        i++;
    }
    if (notes.empty()) {
        std::cout << "Nous ne pouvons pas calculer votre moyenne si vous ne nous donnez aucune note !" << std::endl;
    }
    else {
        float moyenne {0};
        for (auto const note : notes) {
            moyenne += note;
        }
        moyenne /= i;
        std::cout << "Votre moyenne est de : " << moyenne << std::endl;
    }


    return 0;
}
