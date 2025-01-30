#include <iostream>
#include <string>
#include "../include/config.h"
#include "../include/Parser.h"
#include "../include/Grapher.h"
#include "../include/Statistics.h"
using namespace std;

bool isNumber(const string& str) {
    for (char const &c : str) 
    {
        if (!isdigit(c)) 
        {
          return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) 
{
  string nomFichierLog;
  Flags flags;
  //Analyse de la ligne de commande
  for (int i = 1; i < argc; i++) 
  {
    //--------------------------s'il reste 1 argument
    //c'est le fichier de log sinon c'est une erreur
    if (i == argc-1)
    {
      string nom_fichier = argv[i]; //on vérifie la taille du fichier puis on vérifie que le fichier est bien un .log
      if (nom_fichier.size() < 4)
      {
        cerr << "Fichier invalide" << endl;
        return 1;
      }
      else if (nom_fichier.substr(nom_fichier.size()-4) != ".log")
      {
        cerr << "Le fichier de log doit etre un fichier .log" << endl;
        return 1;
      }
      else
      {
        nomFichierLog = nom_fichier;
      }
    }

    //--------------------------s'il reste plus d'un argument donc une commande
    if (i < argc-1)
    {
      //si l'argument est -e
      if (string(argv[i]) == "-e")
      {
        flags.e = 1;
      }

      //si l'argument est -g, on vérifie que le fichier donc le texte qui suit est bien un .dot
      else if (string(argv[i]) == "-g")
      {
        if (i == argc-2)
        {
          cerr << "Il manque un argument pour la commande -g" << endl;
          return 1;
        }
        string nom_fichier = argv[i+1];

        //Compare les 4 derniers caractères de la chaine de caractères (.dot) (verifie d'abord si il y en a 4)
        if (nom_fichier.size() < 4)
        {
          cerr << "L'argument de la commande -g doit etre un fichier .dot" << endl;
          return 1;
        }
        if (nom_fichier.substr(nom_fichier.size()-4) != ".dot")
        {
          cerr << "L'argument de la commande -g doit etre un fichier .dot" << endl;
          return 1;
        }
        flags.g = argv[i+1];
        i++;
      }

      //si l'argument est -t, on vérifie que l'heure (donc le texte qui suit) est bien un nombre entre 0 et 23
      else if (string(argv[i]) == "-t")
      {
        if (i == argc-2)
        {
          cerr << "Il manque un argument pour la commande -t" << endl;
          return 1;
        }
        //verification de la validité de l'argument
        if (isNumber(argv[i+1]))
        {
          int nombre = atoi(argv[i+1]);
          if (nombre >= 0 && nombre <24)
          {
            flags.t = nombre;
            i++;  //prend en compte le fait qu'on a pris 2 arguments
          }
          else
          {
            cerr << "L'argument de la commande -t doit etre un nombre entre 0 et 23 compris." << endl;
            return 1;
          }
        }
        else
        {
          cerr << "L'argument de la commande -t doit etre un nombre entre 0 et 23 compris." << endl;
          return 1;
        }
      }

      //si l'argument est -i 
      else if (string(argv[i]) == "-i")
        flags.i = 1;
      
      else
      {
        cerr << "La commande entree est incorrect" << endl;
        return 1;
      }
    }
  }





  //Appel des stats et affichage du top 10 dans la console
  Parser parser(nomFichierLog);

  
  if (flags.g != "")
  {
    // ------------------------------------------------- Créer le .dot
    Grapher grapher(parser, flags);
    cout << "Dot-file " << flags.g << " created at ./"<< flags.g << endl;

    // ------------------------------------------------- Créer l'image

    if (flags.i == 1)
    {
      // Recherche de la présence du fichier
      string graphname = flags.g.substr(0, flags.g.size() - 4);
      ifstream infile("./" + graphname + ".dot");
      if (infile.good())
        system(("dot -Tpng -o ./" + graphname + ".png ./" + graphname + ".dot").c_str());
    }
  }

  if (flags.t != -1)
  {
    cout << "Warning: only hits between " << flags.t << ":00 and " << flags.t+1<< ":00 have been taken into account " << endl;
  }

  //debuggage
  #ifdef MAP
  cout<< "g = "<<flags.g<<", e = "<<flags.e<<", t = "<<flags.t<<", i = "<<flags.i<<", nom de fichier = "<< nomFichierLog <<endl;
  #endif

  //création des stats
  Statistics stats;
  stats.Fill(parser,flags);
  stats.MakeStats();
  
  return 0;
  }