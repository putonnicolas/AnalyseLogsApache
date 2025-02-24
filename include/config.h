#ifndef CONFIG_H
#define CONFIG_H

using namespace std;
#include <string>
#include <unordered_map>

// ------------------------------------------------------------- Structures
typedef struct Flags
{
  string g = "";
  int t = -1;
  bool e = 0;
  bool i = 0;
} Flags;

// ----------------------------------------------------------------- Macros
using GraphMap = unordered_map<string, unordered_map<string, int>>;
using LineParsed = unordered_map<string, string>;

#endif // CONFIG_H