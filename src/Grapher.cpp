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

//---------- Réalisation de la classe <Grapher> (fichier Grapher.cpp) ------------

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "../include/Grapher.h"

//-------------------------------------------- Constructeurs - destructeur
Grapher::Grapher()
{
#ifdef MAP
  cout << "Appel au constructeur de <Grapher>" << endl;
#endif
} //----- Fin de Grapher

Grapher::Grapher(Parser &parser, Flags &flags)
{
#ifdef MAP
  cout << "Appel au constructeur de <Grapher>" << endl;
#endif
  Fill(parser, flags);
  MakeGraph(flags);
} //----- Fin de Grapher

Grapher::~Grapher()
{
#ifdef MAP
  cout << "Appel au destructeur de <Grapher>" << endl;
#endif
} //----- Fin de ~Grapher

//----------------------------------------------------- Méthodes protégées
void Grapher::Fill(Parser &parser, Flags &flags)
{
  LineParsed *line;
  // On parcourt le fichier à l'aide de parse
  while ((line = parser.parse()) != nullptr)
  {
    // Si l'heure de la ligne est en dehors de la plage horaire
    if (flags.t != -1)
    {
      int line_hour = stoi((*line)["Hour"]);
      if (line_hour < flags.t || line_hour >= (flags.t + 1))
        continue;
    }

    // Si le type de fichier est CSS, js, jpg ou png
    if (flags.e == 0)
    {
      const string &ext = (*line)["Ext"];
      if (ext == "png" || ext == "jpg" || ext == "css" || ext == "js")
        continue;
    }

    // Si les conditions précédentes n'ont pas été validées, alors on ajoute la ligne au graph
    const string &file = (*line)["File"];
    const string &referer = (*line)["Referer"];
    graph[file][referer]++;
    delete line;
  }
} //----- Fin de Fill(Parser &parser, Flags &flags)

void Grapher::MakeGraph(Flags &flags) const
{
  // Ouvre / Créé le fichier
  ofstream outputFile("resources/Graphs/" + flags.g);
  if (!outputFile.is_open())
  {
    cerr << "Erreur lors de l'ouverture du fichier en écriture" << endl;
    return;
  }

  // Ecrit la première ligne
  outputFile << "digraph {" << endl;

  // Création d'un vecteur qui stocke les différents noms de fichiers dans un vecteur, afin d'y associer un indice
  vector<string> files;
  int index = 0;

  // -------------------------------------------------------- Ecriture de la première partie du .dot
  for (const auto &node : graph)
  {
    files.push_back(node.first);
    const string &file = node.first;
    outputFile << "node" << index << " [label=" << file << "\"];" << endl;
    index++;
  }

  // -------------------------------------------------------- Ecriture de la deuxième partie du .dot
  // On parcourt tous les indices de la liste des fichiers
  for (int index = 0; index < files.size(); index++)
  {
    // On prend le dictionnaire des referers du fichier à l'indice 'index'
    for (const auto &referer : graph.at(files[index]))
    {
      // On cherche l'indice du referer
      for (const auto &referer : graph.at(files[index]))
      {
        // Debugging output
        cout << "Recherche de referer: " << referer.first << endl;

          auto it = find_if(files.begin(), files.end(), [&referer](const string &file)
          {
            return referer.first.find(file) != string::npos;
          });

          if (it != files.end())
          {
              int refererIndex = distance(files.begin(), it);
              outputFile << "node" << refererIndex << " -> node" << index << " [label=\"" << referer.second << "\"];" << endl;
          }
          else
          {
              // Debugging output
              cout << "Referer non trouvé: " << referer.first << endl;
          }
      }
    }
  }

  outputFile << "}" << endl;
  outputFile.close();
} //----- Fin de MakeGraph(Flags &flags)