// ---------- Interface de la classe <Grapher> (fichier Grapher.h) ----------------
#if !defined(GRAPHER_H)
#define GRAPHER_H

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <unordered_map>
#include <string>

// -------------------------------------------------------- Include personnel
#include "../include/config.h"


// -------------------------- Classe <Grapher> -----------------------------
class Grapher
{
public:
    //----------------------------------------------------- Méthodes publiques
    void Fill(Parser &parser, Flags &flags);
    void MakeGraph(Flags &flags);

    //-------------------------------------------- Constructeurs - destructeur
    Grapher();
    Grapher(Parser &parser, Flags &flags);
    virtual ~Grapher();

protected:
  GraphMap graph;
};

#endif // GRAPHER_H