/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#include <string>
#include <vector>
#if !defined(LECTURE_H)
#define LECTURE_H

//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------

class Lecture
{
    //----------------------------------------------------------------- PUBLIC

public:
    //-------------------------------------------- Constructeurs - destructeur
    std::vector<std::string> lireUneLigne();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Lecture(std::string nomFichier);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecture();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecture();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    std::string ligne;
    std::vector<std::string> ligneParsee;

    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // LECTURE_H
