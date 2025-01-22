#include <iostream>
#include <cstring>
using namespace std;

typedef struct Flags {
  string g ="";
  int t = -1;
  bool e = 0;
} Flags;

int main(int argc, char* argv[]) 
{
  Flags flags;

  for (int i = 1; i++; i<argc) 
  {
    if (strcmp(argv[i],"-g")==0)
    {
      string nom_fichier = argv[i+1];
      
      flags.g = argv[i+1];
      i++;
    }
    else if (strcmp(argv[i],"-t")==0)
    {
      int nombre = atoi(argv[i+1]);
      if (nombre > 0 and nombre < 24)
      {
        flags.t = nombre;
        i++;
      }
      else
      {
        cerr << "Le parametre de la commande -t doit etre un nombre entre 0 et 23 compris." << endl;
        return 1;
      }
    }
    else if (strcmp(argv[i],"-t")==0)
    {
      flags.e = 1;
    }

  }

  return 0;
}