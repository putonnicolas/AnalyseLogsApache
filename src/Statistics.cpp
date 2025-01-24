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
void Statistics::Fill(Parser &parser, Flags &flags)
{
    LineParsed *line;

    // Lire les logs ligne par ligne
    while ((line = parser.parse()) != nullptr)
    {
        // Vérifier les conditions de Flags
        // Si l'heure de la ligne est en dehors de la plage horaire
        if (flags.t != -1)
        {
            int line_hour = stoi((*line)["Hour"]);
            if (line_hour < flags.t || line_hour >= (flags.t + 1))
            {
                delete line; // Libérer la mémoire avant de passer à la ligne suivante
                continue;
            }
        }

        // Ignorer certains types de fichiers si le flag e est désactivé
        if (flags.e == 0)
        {
            const string &ext = (*line)["Ext"];
            if (ext == "png" || ext == "jpg" || ext == "css" || ext == "js")
            {
                delete line; // Libérer la mémoire avant de passer à la ligne suivante
                continue;
            }
        }

        // Extraire le nom de fichier et mettre à jour la map
        const string &file = (*line)["File"];
        stats[file]++; // Incrémenter le compteur d'accès pour ce fichier

        delete line;
    }
}
void Statistics::MakeStats()
{ // Top 10 des fichiers les plus consultés (nombre de hits)
    // parcourire ma map
    for (int i = 0; i < 10; i++)
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
