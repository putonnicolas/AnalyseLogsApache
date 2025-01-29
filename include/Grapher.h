/*************************************************************************
                           Grapher  -  description
                             -------------------
    début                : $24/01/2025$
    copyright            : (C) $2025$ par $GALLARD Yanis/FRECHARD Eliott/DIDIETR Alexandre/PUTON Nicolas$
    e-mail               : $eliott.frechard@insa-lyon.fr
                            yanis.gallard@insa-lyon.fr
                            nicolas.puton@insa-lyon.fr
                            alexandre.didier@insa-lyon.fr$
*************************************************************************/

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
#include "../include/Parser.h"

// -------------------------- Classe <Grapher> -----------------------------
class Grapher
{
public:
  //----------------------------------------------------- Méthodes publiques
  void Fill(Parser &parser, Flags &flags);
  void MakeGraph(Flags &flags) const;

  //-------------------------------------------- Constructeurs - destructeur
  Grapher();
  Grapher(Parser &parser, Flags &flags);
  virtual ~Grapher();

protected:
  GraphMap graph;
};

#endif // GRAPHER_H