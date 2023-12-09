/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



string removeSpaces(string input) {
    int start = 0;
    int end = input.length() - 1;

    // Supprimer les espaces au début de la chaîne
    while (start <= end && input[start] == ' ') {
        start++;
    }

    // Supprimer les espaces à la fin de la chaîne
    while (end >= start && input[end] == ' ') {
        end--;
    }

    // Retourner la sous-chaîne sans les espaces au début et à la fin
    return input.substr(start, end - start + 1);
}


vector<string> Lecture::lireUneLigne()
{

    for (int i = 0; ligne[i] != '\0'; i++) {
        if (ligne[i] == ' ') {
            string ip = ligne.substr(0, i);
            ligneParsee.push_back(removeSpaces(ip));
            ligne.erase(0, i);
            i = 0; 
        }
        if (ligne[i] == '[') {
            ligne.erase(0, i+1);
            i = 0;
            string ip = ligne.substr(0, ligne.find(']'));
            ligneParsee.push_back(removeSpaces(ip));
            i = ligne.find(']')+1;
            ligne.erase(0, i);
            i = 0;
        }
        if (ligne[i] == '\"') {
            ligne.erase(0, i+1);
            i = 0;
            string ip = ligne.substr(0, ligne.find('\"'));
            ligneParsee.push_back(removeSpaces(ip));
            i = ligne.find('\"')+1;
            ligne.erase(0, i);
            i = 0;
        }
        if (ligne[i] == '\n' || ligne[i] == '\0') {
            if (i != 0) {
                string ip = ligne.substr(0, i);
                ligneParsee.push_back(removeSpaces(ip));
                ligne.erase(0, i);
                i = 0; 
            }
            return ligneParsee;
        }
    }
    return ligneParsee;
}

Lecture::Lecture(string uneLine)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
    ligne = uneLine;

} //----- Fin de Lecture

Lecture::Lecture()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif
    
    
} //----- Fin de Lecture

Lecture::~Lecture()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
    
} //----- Fin de ~Lecture

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
