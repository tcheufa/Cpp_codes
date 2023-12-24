#include <iostream>
#include <algorithm>
#include <cctype>
#include <functional>
#include <string>

using namespace std;


string& ltrim (string & str, string const chars = " \t\v")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string& rtrim (string & str, string const chars = " \t\v")
{
    str.erase(str.find_last_not_of(chars)+1); // +1 to effectively erase the first_of(chars)
    return str;
}

string& trim (string & str, string const chars = " \t\v")
{
    ltrim(str, chars);
    rtrim(str, chars);
    return str;
}

int main () {

    std::string text {"\tg    voici un texte à trimer ... \"Trimer\" ça se dit même ?                  "};
    std::string::iterator text_start {};
    std::string::iterator text_end {};
    std::string::iterator trim_end {};

    std::cout << "Taille actuelle du texte : " << text.size() << std::endl;
//
//    for (int i = 0; i < 2; i++) {
//        text_start = std::begin(text);
//        text_end = std::end(text);
//        std::reverse(text_start, text_end);
//        trim_end = find_if_not(text_start, text_end, isspace);
//
//        if (trim_end == text_end || trim_end == text_start) break;
//
//        text.erase(text_start, trim_end);
//
//    }

    std::cout << "Nouveau texte : " << trim(text) << std::endl;
    std::cout << "Nouvelle taille après l'utilisation de trim : " << text.size() << std::endl;

    return 0;
}

