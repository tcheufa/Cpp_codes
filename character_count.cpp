#include <iostream>
#include <vector>
#include <algorithm>

int main () {

    std::string text {};
    std::string scan {};
    char needle {'a'};

    std::cout << "Saisissez du texte : \n";
    do {
        std::cin >> scan;
        text += scan;
        text += " ";
    }
    while (std::cin.get() != '\n');


    auto word_it {text.begin()};
    auto it {word_it};
    auto text_end {text.end()};

    std::cout << "Le texte que vous avez saisi est : \n"
              << text
              << "\nCe texte comporte "
              << std::count(word_it, text_end, needle)
              << " fois la lettre \""
              << needle
              << "\" :"
              << std::endl
              << std::endl;

    while (word_it != text_end) {
        for (it = word_it; *it != ' ' && it != text_end; ++it) {
            std::cout<< *it;
        }
        std::cout<<" : "<<std::count(word_it, it, needle)<<"occurence(s)"<< std::endl;
        word_it = it;
        ++word_it;

    }


    return 0;
}

