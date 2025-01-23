/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>

//------------------------------------------------------ Include personnel
#include "../include/Statistics.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Statistics::MakeStats()
{ // Top 10 des fichiers les plus consultés (nombre de hits)
    // parcourire ma map
    for (int i = 0; i < 10; i++)
    {
        int max_prov = -1;
        for (auto it = stats.begin(); it != stats.end(); it++)
        {
            // calcul du max
            if (it->second > max_prov)
            {
                max_prov = it->second;
            }
            cout << it->first << " (" << it->second << " hits)" << endl;
        }
    }
}

void Statistics::Fill(Flags flag)
{
  
}

//-------------------------------------------- Constructeurs - destructeur
Statistics::Statistics() : stats()
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistics>" << endl;
#endif
}

Statistics::~Statistics()
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistics>" << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
