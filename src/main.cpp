#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Lecture.h"
#include "Stockage.h"

using namespace std;

struct args {
    string g;
    bool e;
    string t;
};


unordered_map<string, Occurence> lireFichier(const string& nomFichier, bool exclure, const string& heure) {
    vector<vector<string> > lignes;
    ifstream fichier(nomFichier);

    if (fichier.is_open()) {
        string ligne;

        while (getline(fichier, ligne)) {
            Lecture lecture(ligne);
            lignes.push_back(lecture.lireUneLigne());
        }

        fichier.close();
    } else {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }

    Stockage stockage(lignes, exclure, heure);
    
    return stockage.GetMap();
}

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [-g <nomfichier.dot>] [-e] [-t <heure>] <fichier>" << endl;
        return 1;
    }

    string nomFichier = argv[argc - 1];
    args arguments { "NULL", false, "NULL" };

    for (int i = 1; i < argc-1;) {
        string option = argv[i];
        string argument = argv[i + 1];

        if (option == "-g") {
            arguments.g = argument;
            cout << "Option -g non implémentée." << endl;
            i += 2;
        } else if (option == "-e") {
            arguments.e = true;
            i++;
        } else if (option == "-t") {
            arguments.t = argument;
            i += 2;
        } else {
            i++;
        }

    }

    unordered_map<string, Occurence> res = lireFichier(nomFichier, arguments.e, arguments.t);

        
    auto it = res.begin();
    while (it != res.end()) {
        std::cout << it->first << "  (" << it->second.GetOccurence() << " hits" << ')' << std::endl;
        ++it;
    }

    return 0;
}