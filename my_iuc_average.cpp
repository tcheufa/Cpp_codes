#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
void secured_cin (T &);


struct Subject {
    string name;
    float note_ca; // CA note
    float note_exam; // exam note
    unsigned short coeff;
};

struct Note {
    Subject* subject;
    unsigned short value;
};


template <typename Container>
void saveSubjects(Container);


template <typename Container>
void loadSubjects (Container &);

Subject createSubject ();
void displaySubject(Subject const & s);

void DisplayMenu ();
bool Confirm_continuation();

/**************************************************************************************************************************
 *                                                                                                                        *
 *  By linker                                                                                                             *
 *      The purpose of this code is to calculate my average using the following method used by many schools :             *
 * --> A final note of a subject is composed of 30% of the Continuous Assessment (CA) and 70% of the Semester Exam        *
 * --> Each note is associated with a coefficient that is used to calculate the average of a student                      *
 *                                                                                                                        *
 **************************************************************************************************************************
*/

int main () {

    vector<Subject> subjects {};
    vector<float> notes {};
    short action {};
    char confirm {};
    loadSubjects(subjects);

    while (1) {
        system("clear");
        DisplayMenu();
        secured_cin(action);
        switch (action) {
            case 1:
                do {
                    subjects.push_back(createSubject());
                } while (Confirm_continuation());
                break;
            case 2:
                if (subjects.empty()) {
                    cout << "Aucune matière n'existe encore";
                }
                do {
                    for_each(cbegin(subjects), cend(subjects), displaySubject);
                } while (Confirm_continuation());
                break;
            case 3:
                do {
                    for_each(begin(subjects), end(subjects), [] (Subject & s) -> void {
                        displaySubject(s);
                        cout << "\nEntrez la note de CC correspondante : ";
                        secured_cin(s.note_ca);
                        if (s.note_ca == -10) {
                            return;
                        }
                        cout << "\nEntrez la note de SN correspondante : ";
                        secured_cin(s.note_exam);
                        if (s.note_exam == -10) {
                            return;
                        }
                    });
                } while (Confirm_continuation());
                break;
            case 4:
                do {
                    for_each(cbegin(subjects), cend(subjects), displaySubject);
                } while (Confirm_continuation());
                break;
            case 5:
                do {
                    float avg {0.f};
                    int total_coeff {0};
                    for_each(cbegin(subjects), cend(subjects), [&avg, &total_coeff] (Subject const & s) {
                        avg += (s.note_ca * 0.3 + s.note_exam * 0.7) * s.coeff;
                        total_coeff += s.coeff;
                    });
                    avg /= total_coeff;
                    cout << "Votre moyenne est de " << avg;
                } while (Confirm_continuation());
                break;
            case 6:
                do {
                    saveSubjects(subjects);
                } while (Confirm_continuation());
                break;
            case 7:
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "Option non définie.\n";
        }
    }

    return 0;
}


Subject createSubject () {
    static Subject S {"", 0};
    cout << "Entrer le nom de la matière : ";
    secured_cin(S.name);
    cout << "Entrer le coefficient : ";
    secured_cin(S.coeff);
    cout << "Enregistrement terminé.\n";
    S.note_ca = -1.;
    S.note_exam = -1.;
    return S;
}


template <typename Container>
void saveSubjects(Container subjects)
{
    std::ofstream save_file {"../subjects.csv"};
    for (Subject const subject : subjects) {
        save_file << (subject.name) << ',' << (subject.coeff) << '\n';
    }
    save_file.close();
    cout << "Sauvegarde réussie. Stockage dans le fichier ../subjects.csv";
}


template <typename Container>
void loadSubjects (Container & subjects) {

    ifstream save_file {"../subjects.csv"};
    if (!save_file) {
        return;
    }
    Subject subject {};
    vector<string> substrings {};
    string::iterator text_start {};
    string::iterator text_end {};

    string::iterator word_start {};
    string::iterator word_end {};
    string text {u8""};

    char separator {','};
    while (getline(save_file, text)) {

        text_start = begin(text);
        text_end = end(text);
        word_start = text_start;

        do {
            word_end = find(word_start, text_end, separator);
            substrings.push_back({word_start, word_end});
            if (word_end == text_end) break;
            word_start = word_end + 1;
        }
        while (1);

        subject.name = substrings[0];
        subject.coeff = std::stod(substrings[1]);
        subject.note_ca = -1;
        subject.note_exam = -1;
        subjects.push_back(subject);
        substrings.clear();
    }
}



void displaySubject(Subject const & s)
{
    cout << flush << "\nNom : " << (s.name) << "\nCoefficient : " << (s.coeff);
    if (s.note_ca >= 0.) {
        cout << "\nNote du CC : " << (s.note_ca);
    }
    if (s.note_exam >= 0.) {
        cout << "\nNote de la SN : " << (s.note_exam);
    }
    cout << '\n';
}


void DisplayMenu()
{
    cout << "Gestion des notes et matières\n\n"
        "Choisissez une action à effectuer\n"
        "1. Créer une nouvelle matière\n"
        "2. Voir toutees les matières\n"
        "3. Attribuer des notes\n"
        "4. Voir toutes les notes\n"
        "5. Calculer la moyenne\n"
        "6. Sauvegarder la liste des matières\n"
        "7. Quitter \n"
        "> ";

}


bool Confirm_continuation()
{
    char again {};
    cout << "\nAppuyez sur 'r' pour effectuer une nouvelle opération... " << endl;
    secured_cin(again);
    return (again == 'r');
}

template <typename T>
void secured_cin (T & dest)
{
    while (!(cin >> dest)) {
        if (cin.eof())
            throw runtime_error("Le flux a été fermé.");
        cout << "Entrée incorrecte !\nVeuillez réessayer : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


