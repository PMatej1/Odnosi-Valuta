#ifndef ODNOSI_VALUTA_H
#define ODNOSI_VALUTA_H
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

class Valuta {
    unordered_map<string, pair<string, double>> roditelj;
  public:
       Valuta () {}
        void dodajOdnos(string i, string j, double odnos);
        double transfer(string pocetni, string krajnji);
        double transfer2(string pocetni, string krajnji);
};




#endif // ODNOSI_VALUTA_H

