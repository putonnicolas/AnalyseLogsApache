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
{
    for (int i = 0; i < 10 && !stats.empty(); i++) // S'arrêter si la map est vide
    {
        int max_prov = -1;
        auto max_it = stats.end(); // Itérateur pour stocker l'élément avec le max

        // Parcourir la map pour trouver l'élément avec le maximum
        for (auto it = stats.begin(); it != stats.end(); ++it)
        {
            if (it->second > max_prov)
            {
                max_prov = it->second;
                max_it = it; // Garder l'itérateur vers cet élément
            }
        }

        // Si un maximum a été trouvé, afficher et supprimer l'élément correspondant
        if (max_it != stats.end())
        {
            cout << max_it->first << " (" << max_it->second << " hits)" << endl;
            stats.erase(max_it); // Supprimer l'élément avec le max
        }
    }
}
//------------------------------------------------- Surcharge d'opérateurs

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
