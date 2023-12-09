#include <iostream>
#include <fstream>
#include <vector>
#include "Lecture.h"

using namespace std;

void lireFichier(const string& nomFichier) {
    vector<vector<string> > lignes;
    ifstream fichier(nomFichier);

    if (fichier.is_open()) {
        string ligne;
        Lecture lecture;

        while (getline(fichier, ligne)) {
            Lecture lecture(ligne);
            // vector<string> res = lecture.lireUneLigne();
            lignes.push_back(lecture.lireUneLigne());
            
        }

        fichier.close();
    } else {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }

    int size = lignes.size();
    for (int i = 0; i < size; i++) {
        int size2 = lignes[i].size();
        for (int j = 0; j < size2; j++) {
            cout << lignes[i][j] << " ";
        }
        cout << endl;
    }
}




int main() {
    string nomFichier = "Fichier-Fournis/exemple-mini-non-exhaustif.txt";
    // string nomFichier = "Fichier-Fournis/anonyme.log";
    lireFichier(nomFichier);

    return 0;
}