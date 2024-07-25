#include <iostream>
#include "odnosi_valuta.h"
using namespace std;

int main() {
  Valuta valuta;
  valuta.dodajOdnos("USD","GBP",0.79);
   valuta.dodajOdnos("USD","JPY",148.14);
   valuta.dodajOdnos("EUR","BAM",1.96);
   valuta.dodajOdnos("USD","EUR",0.92);
   valuta.dodajOdnos("TRY","DKK",0.23);
   valuta.dodajOdnos("TRY","JPY",4.91);
   valuta.dodajOdnos("RSD","TRY",0.28);
   valuta.dodajOdnos("EGP","DKK",0.22);
   valuta.dodajOdnos("AUD","USD",0.66);
   valuta.dodajOdnos("AUD","CAD",0.89);
   valuta.dodajOdnos("CHF","GBP",0.91);
   valuta.dodajOdnos("RUB","RSD",1.22);
   valuta.dodajOdnos("CAD","EUR",0.68);
   valuta.dodajOdnos("JPY","GBP",0.0053);
   //cout<<valuta.transfer("USD","EGP")<<endl;
   cout<<valuta.transfer2("USD","EGP")<<endl;
  // cout<<valuta.transfer("USD","BAM")<<endl;
   cout<<valuta.transfer2("USD","BAM")<<endl;
  // cout<<valuta.transfer("CAD","JPY")<<endl;
   cout<<valuta.transfer2("CAD","JPY")<<endl;
  // cout<<valuta.transfer("GBP", "TRY")<<endl;
   cout<<valuta.transfer2("GBP", "TRY");


}
