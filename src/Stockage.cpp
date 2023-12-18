/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Stockage> (fichier Stockage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Stockage.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


unordered_map<string, Occurence> Stockage::GetMap() {
    return myMap2;
}

int FormatHorraire(string horraire) {
    horraire = horraire.substr(horraire.find(":") + 1, 2);
    return stoi(horraire);
}

string FormatFile(string file) {
    file = file.substr(file.find("/"), file.find("HTTP") - 5);
    return file;
}

void Stockage::CheckConfigFile()
{
    const string nomFichier = "ConfigFile/ConfigFile.txt";

    std::ifstream fichier(nomFichier);

    if (fichier.is_open()) {
        std::string ligne;
        int numeroLigne = 1;
        while (std::getline(fichier, ligne)) {
            if (numeroLigne == 2) {
                ignoreSource = ligne.substr(7, ligne.length());
            }
            if (numeroLigne == 3) {
                string tmp = ligne.substr(11, ligne.length());

                size_t start = 0, end = 0;

                // Trouver les éléments en utilisant ',' comme délimiteur
                while ((end = tmp.find(',', start)) != std::string::npos) {
                    ignoreFiles.push_back(tmp.substr(start, end - start));
                    start = end + 1;
                }

                // Ajouter le dernier élément
                ignoreFiles.push_back(tmp.substr(start));                
            }
            numeroLigne++;
        }
        fichier.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier de configuration \"ConfigFile.txt\"." << std::endl;
    }
}

bool Stockage::CheckIsInIgnoreFiles(string file) {
    int size = ignoreFiles.size();

    for (int i = 0; i < size; i++) {
        if (file.find(ignoreFiles[i]) != string::npos) {
            return true;
        }
    }
    return false;
}

Stockage::Stockage(vector<vector<string> > myLignes, bool exclure, string heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stockage>" << endl;
#endif
    int size = myLignes.size();
    Stockage::CheckConfigFile();

    vector<string> ignoreFiles; // Nouveau vecteur ignoreFiles

    for (int i = 0; i < size; i++) {
        Occurence tmp2;

        if (myLignes[i][7].find(ignoreSource) != string::npos) {
            myLignes[i][7] = myLignes[i][7].substr(31, myLignes[i][7].length());
        }

        if (myMap2.find(FormatFile(myLignes[i][4])) == myMap2.end()) {
            if (exclure) {
                if (CheckIsInIgnoreFiles(FormatFile(myLignes[i][4]))) {
                    continue;
                }
            }
            if (heure != "NULL") {
                if (FormatHorraire(myLignes[i][3]) < stoi(heure) || FormatHorraire(myLignes[i][3]) > stoi(heure) + 1 ) {
                    continue;
                }
            }
            tmp2.mySource[myLignes[i][7]] = 1;
            myMap2[FormatFile(myLignes[i][4])] = tmp2;
            
        } else {
            if (myMap2[FormatFile(myLignes[i][4])].mySource.find(myLignes[i][7]) == myMap2[FormatFile(myLignes[i][4])].mySource.end()) {
                myMap2[FormatFile(myLignes[i][4])].mySource[myLignes[i][7]] = 1;
            } else {
                myMap2[FormatFile(myLignes[i][4])].mySource[myLignes[i][7]] += 1;
            }
            myMap2[FormatFile(myLignes[i][4])].occ += 1;
        }
    }

    // Sort myMap2 by occurrence count in ascending order
    vector<pair<string, Occurence>> sortedMap(myMap2.begin(), myMap2.end());
    std::sort(sortedMap.begin(), sortedMap.end(), [](const pair<string, Occurence>& a, const pair<string, Occurence>& b) {
        return a.second.occ < b.second.occ;
    });

    if (sortedMap.size() > 10) {
        sortedMap.erase(sortedMap.begin(), sortedMap.end() - 10);
    } else {
        sortedMap.erase(sortedMap.begin(), sortedMap.end() - sortedMap.size());
    }


    // Update myMap2 with the top 10 entries
    myMap2.clear();
    for (const auto& entry : sortedMap) {
        myMap2[entry.first] = entry.second;
    }

} //----- Fin de Stockage


Stockage::Stockage()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stockage>" << endl;
#endif
    
    
} //----- Fin de Stockage

Stockage::~Stockage()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stockage>" << endl;
#endif
    
} //----- Fin de ~Stockage

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
