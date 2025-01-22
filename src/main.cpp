#include <iostream>
#include <string>
#include "../include/config.h"
using namespace std;

int main(int argc, char* argv[]) 
{
  string nom_fichier_log;
  Flags flags;
  //Analyse de la ligne de commande
  for (int i = 1; i < argc; i++) 
  {
    //--------------------------s'il reste 1 argument
    //soit c'est -e soit c'est le fichier de log sinon c'est une erreur
    if (i == argc-1)
    {
      if (string(argv[i]) == "-e")  //si l'argument est -e
      {
        flags.e = 1;
      }
      else 
      {
        string nom_fichier = argv[i]; //sinon on vérifie la taille du fichier puis on vérifie que le fichier est bien un .log
        if (nom_fichier.size() < 4)
        {
          cerr << "Le fichier doit etre un fichier .log" << endl;
          return 1;
        }
        else if (nom_fichier.substr(nom_fichier.size()-4) != ".log")
        {
          cerr << "Le fichier doit etre un fichier .log" << endl;
          return 1;
        }
        else
        {
          nom_fichier_log = nom_fichier;
        }
      }
    }
    //--------------------------s'il reste plus d'un argument
    //si l'argument est -g, on vérifie que le fichier est bien un .dot
    else if (string(argv[i]) == "-g")
    {
      string nom_fichier = argv[i+1];

      //Compare les 4 derniers caractères de la chaine de caractères (.dot) (verifie d'abord si il y en a 4)
      if (nom_fichier.size() < 4)
      {
        cerr << "Le fichier doit etre un fichier .dot" << endl;
        return 1;
      }
      if (nom_fichier.substr(nom_fichier.size()-4) != ".dot")
      {
        cerr << "Le fichier doit etre un fichier .dot" << endl;
        return 1;
      }
      flags.g = argv[i+1];
      i++;
    }


    //si l'argument est -t, on vérifie que l'heure est bien un nombre entre 0 et 23
    else if (string(argv[i]) == "-t")
    {
      int nombre = atoi(argv[i+1]);
      if (nombre < 0 || nombre >= 24)
      {
        cerr << "L'argument de la commande -t doit etre un nombre entre 0 et 23 compris." << endl;
        return 1; 
      }
      flags.t = nombre;
      i++;
    }
  }

  return 0;
}