/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stockage> (fichier Stockage.h) ----------------
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
    // TrajetSimple(const TrajetSimple &unTrajetSimple);
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
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // STOCKAGE_H
