/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : $24/01/2025$
    copyright            : (C) $2025$ par $GALLARD Yanis/FRECHARD Eliott/DIDIETR Alexandre/PUTON Nicolas$
    e-mail               : $eliott.frechard@insa-lyon.fr
                            yanis.gallard@insa-lyon.fr
                            nicolas.puton@insa-lyon.fr
                            alexandre.didier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined(PARSER_H)
#define PARSER_H

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../include/config.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PARSER>
//  Permet de faire la lecture du fichier de log. Classe réutilisable pour d'autres applications.
//
//------------------------------------------------------------------------

class Parser
{
protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    ifstream file;

    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    void openFile(const string &path);

    LineParsed *parse();

    //-------------------------------------------- Constructeurs - destructeur

    Parser();
    // Mode d'emploi :
    //

    Parser(const string &path);
    // Mode d'emploi :
    //

    virtual ~Parser();
    // Mode d'emploi :
    //
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
