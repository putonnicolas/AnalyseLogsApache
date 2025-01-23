/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Parser> (fichier Parser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//------------------------------------------------------ Include personnel
#include "../include/Parser.h"
#include "Parser.h"
#include "config.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Parser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Parser::openFile(const string& path) {
    if (file.is_open()) 
    {
      file.close();  
    }
    file.open(path);  
    
    if (!file.is_open()) {
      cout << "Erreur : Impossible d'ouvrir le fichier " << path << endl;
    }
}

// 192.168.0.1    -           -       [08/Sep/2012:12:59:00 +0200] "GET        /page2.html  HTTP/1.1"              200         2000      "http://intranet-if.insa-lyon.fr/page1.html" "Mozilla/5.0"
// 0: IP       1: logName 2: userName    3: Date   4: Hour   5: GMT 6: Method   7: File   8: ProtocolVersion     9: Status  10:dataSize              11: referer                        12:browser         
LineParsed* Parser::parse() {
  LineParsed* lineData = new unordered_map<string, string>();

  string temp;

  if(!getline(file, temp, ' '))
  {
    cout << "Fichier vide" << endl;
    return nullptr;
  }; 
  lineData->insert(make_pair("IP", temp));  
  
  getline(file, temp, ' ');
  lineData->insert(make_pair("LogName", temp));  
  
  getline(file, temp, ' ');
  lineData->insert(make_pair("UserName", temp));  

  getline(file, temp, '[');  
  getline(file, temp, ':');  
  lineData->insert(make_pair("Date", temp));

  getline(file, temp, ' ');  
  lineData->insert(make_pair("Hour", temp));

  getline(file, temp, ']');  
  lineData->insert(make_pair("GMT", temp));

  getline(file, temp, '"');  
  getline(file, temp, ' ');  
  lineData->insert(make_pair("Method", temp));

  getline(file, temp, ' ');  
  lineData->insert(make_pair("File", temp));
  
  size_t pos = temp.find_last_of('.');
  string ext = (pos != string::npos) ? temp.substr(pos + 1) : "";
  lineData->insert(make_pair("Ext", ext));

  getline(file, temp, '"');  
  lineData->insert(make_pair("ProtocolVersion", temp));

  getline(file, temp, ' ');
  getline(file, temp, ' ');
  lineData->insert(make_pair("Status", temp)); 
  getline(file, temp, ' ');
  lineData->insert(make_pair("DataSize", temp));  

  getline(file, temp, '"');  
  getline(file, temp, '"'); 
  lineData->insert(make_pair("Referer", temp));

  getline(file, temp, '"'); 
  getline(file, temp, '"'); 
  lineData->insert(make_pair("Browser", temp));

  getline(file, temp, '\n'); 
  return lineData;
}

//-------------------------------------------- Constructeurs - destructeur

Parser::Parser() 
{
#ifdef MAP
    cout << "Appel au constructeur de <Parser>" << endl;
#endif
  this->file = ifstream();
} //----- Fin de Parser


Parser::Parser(const string &path)
{
  openFile(path);
}


Parser::~Parser()
{
#ifdef MAP
    cout << "Appel au destructeur de <Parser>" << endl;
#endif
  if (file.is_open()) {
    file.close();  
  }
} //----- Fin de ~Parser


