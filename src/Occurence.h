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

using namespace std;

#if !defined(OCCURENCE_H)
#define OCCURENCE_H

//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Stockage>
//
//
//------------------------------------------------------------------------

class Occurence
{
    //----------------------------------------------------------------- PUBLIC

public:
    //-------------------------------------------- Constructeurs - destructeur

    int GetOccurence() {
        return occ;
    };

    string GetNomFichier() {
        return mySource.begin()->first;
    };

    unordered_map<string, int> GetMap() {
        return mySource;
    };


    Occurence() {
        occ = 1;
    };
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Occurence() {};
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend class Stockage;

    //------------------------------------------------------------------ PRIVE

protected:
    int occ;
    unordered_map<string, int> mySource;
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // OCCURENCE_H
