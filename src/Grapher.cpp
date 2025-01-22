//---------- Réalisation de la classe <Grapher> (fichier Grapher.cpp) ------------

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "./include/Grapher.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------- Surcharge d'opérateurs
Grapher &Grapher::operator=(const Grapher &unGrapher)
{
} //----- Fin de operator =



//-------------------------------------------- Constructeurs - destructeur
Grapher::Grapher()
{
#ifdef MAP
    cout << "Appel au constructeur de <Grapher>" << endl;
#endif
} //----- Fin de Grapher


Grapher::Grapher(Flags flags)
{
#ifdef MAP
    cout << "Appel au constructeur de <Grapher>" << endl;
#endif
  Fill(flags);
} //----- Fin de Grapher


Grapher::~Grapher()
{
#ifdef MAP
    cout << "Appel au destructeur de <Grapher>" << endl;
#endif
} //----- Fin de ~Grapher

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées