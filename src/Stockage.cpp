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

void CheckStartDest(string *str)
{
    if (str->find("http://intranet-if.insa-lyon.fr") != string::npos) {
        str->substr(0, 33);
    }
}

Stockage::Stockage(vector<vector<string> > myLignes, bool exclure, string heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stockage>" << endl;
#endif
    int size = myLignes.size();

    for (int i = 0; i < size; i++) {
        Occurence tmp2;

        if (myLignes[i][7].find("http://intranet-if.insa-lyon.fr") != string::npos) {
            myLignes[i][7] = myLignes[i][7].substr(31, myLignes[i][7].length());
        }

        if (myMap2.find(FormatFile(myLignes[i][4])) == myMap2.end()) {
            if (exclure) {
                if (myLignes[i][4].find(".css") != string::npos || myLignes[i][4].find(".js") != string::npos || FormatFile(myLignes[i][4]).find(".png") != string::npos || FormatFile(myLignes[i][4]).find(".jpg") != string::npos || myLignes[i][4].find(".gif") != string::npos || myLignes[i][4].find(".ico") != string::npos || myLignes[i][4].find(".svg") != string::npos || myLignes[i][4].find(".woff") != string::npos || myLignes[i][4].find(".ttf") != string::npos || myLignes[i][4].find(".eot") != string::npos || myLignes[i][4].find(".woff2") != string::npos || myLignes[i][4].find(".otf") != string::npos) {
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
    sort(sortedMap.begin(), sortedMap.end(), [](const pair<string, Occurence>& a, const pair<string, Occurence>& b) {
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
