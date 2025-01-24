/*************************************************************************
                           Statistics  -  description
                             -------------------
    début                : $24/01/2025$
    copyright            : (C) $2025$ par $GALLARD Yanis/FRECHARD Eliott/DIDIETR Alexandre/PUTON Nicolas$
    e-mail               : $eliott.frechard@insa-lyon.fr
                            yanis.gallard@insa-lyon.fr
                            nicolas.puton@insa-lyon.fr
                            alexandre.didier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined(STATISTICS_H)
#define STATISTICS_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <map>
#include "../include/config.h"
#include "../include/Parser.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistics>
//
//
//------------------------------------------------------------------------

class Statistics
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Statistics();
    // Mode d'emploi :
    //
    // Contrat :
    //
    void MakeStats();
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Fill(Parser &parser, Flags &flags);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistics();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    map<string, int> stats;
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // STATISTICS_H
