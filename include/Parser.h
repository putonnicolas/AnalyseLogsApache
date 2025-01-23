/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined(PARSER_H)
#define PARSER_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
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
    void openFile(const string& path);

    LineParsed* parse(); 


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
