#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

int main () {

    /* Practicing with algorithms and strings. Ex : Splitting a string into substrings */
    std::string text {"bla blabla et voici un texte  ? Voyez-vous même ce qui m'arrive. La programmation c'est vraiment quelque chose. Bref"};

    std::vector<std::string> substrings {};

    char separator {' '};

    std::string::iterator const text_start {std::begin(text)};
    std::string::iterator const text_end {std::end(text)};

    std::string::iterator word_start {text_start};
    std::string::iterator word_end {};

    do {
        word_end = std::find(word_start, text_end, separator);
//        std::cout << std::distance(word_start, word_end);
        substrings.push_back({word_start, word_end});
        if (word_end == text_end) break;
        word_start = word_end + 1;
    }
    while (1);

    for (const std::string word : substrings) {
        std::cout << word << std::endl;
    }


    return 0;
}

