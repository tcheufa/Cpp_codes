#include <iostream>
#include <fstream>
#include <algorithm>

int main () {

    /* Learning to read and write files */
    /* Ex : statistics in a file (letters, words, lines) */

    std::string const file_to_read {"../filetest.txt"};
    std::ifstream f {file_to_read};
    std::string str {};
    unsigned lines {0};
    unsigned words {0};
    unsigned letters {0};
    bool prev_char_is_space {false};
    while (std::getline(f , str)) {
        lines++;
        for (char c : str) {
            if (isspace(c)) {
                if (!prev_char_is_space) {
                    words++;
                }
                prev_char_is_space = true;
            }
            else {
                prev_char_is_space = false;
                letters++;
            }
        }
        // the number of words is the number of spaces + 1
        words++;
    }
    std::cout << "Ce texte comprends " << "lettres dont " << letters << " lettres, " << words << " mots, et " << lines << " lignes.";
    return 0;
}

