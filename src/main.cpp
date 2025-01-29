#include <iostream>
#include <string>
#include "../include/config.h"
/*
#include "../include/Parser.h"
#include "../include/Grapher.h"
#include "../include/Statistics.h"*/
using namespace std;

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
        cerr << "Le fichier de log doit etre un fichier .log" << endl;
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
        int nombre = atoi(argv[i+1]);
        if (nombre < 0 || nombre >= 24)
        {
          cerr << "L'argument de la commande -t doit etre un nombre entre 0 et 23 compris." << endl;
          return 1; 
        }
        flags.t = nombre;
        i++;
      }
      
      else
      {
        cerr << "La commande entree est incorrect" << endl;
        return 1;
      }
    }
  }





//Appel des stats et affichage du top 10 dans la console
if (flags.g != "")
  {
    Grapher grapher(parser, flags);
  }
Parser parser(nomFichierLog);
  //debug
  cout<< "g = "<<flags.g<<", e = "<<flags.e<<", t = "<<flags.t<<", nom de fichier = "<< nomFichierLog <<endl;
  return 0;
}