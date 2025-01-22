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


// -------------------------------------------------------------------- Macros



// -------------------------- Classe <Grapher> -----------------------------
class Grapher
{
public:
    //----------------------------------------------------- Méthodes publiques
    void Fill(Flags flags);


    //-------------------------------------------- Constructeurs - destructeur
    Grapher();
    Grapher(Flags flags);
    virtual ~Grapher();

protected:
  GraphMap graph;
};

#endif // GRAPHER_H