/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stockage> (fichier Stockage.h) ----------------
#include <string>
#include <vector>
#include <unordered_map>
#include "Occurence.h"

using namespace std;

#if !defined(STOCKAGE_H)
#define STOCKAGE_H

//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Stockage>
//
//
//------------------------------------------------------------------------

class Stockage
{
    //----------------------------------------------------------------- PUBLIC

public:
    //-------------------------------------------- Constructeurs - destructeur
    // string Stockage::FormatHorraire(string horraire);

    unordered_map<string, Occurence> GetMap();
    void CheckConfigFile();
    bool CheckIsInIgnoreFiles(string file);


    Stockage(vector<vector<string> > myLignes, bool exclure, string heure);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stockage();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stockage();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    unordered_map<string, Occurence> myMap2;
    string ignoreSource;
    vector<string> ignoreFiles;
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

int FormatHorraire(string horraire);
string FormatFile(string file);
//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // STOCKAGE_H
