
#include "odnosi_valuta.h"
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

// napomena: ostavljena je mogucnost testiranja preko bfs da bi se moglo lakse uporediti rjesenje

void Valuta::dodajOdnos(string i, string j, double odnos) {
  //lista_susjedstva[i].push_back({j, odnos});
   //lista_susjedstva[j].push_back({i,1/odnos});

  // slucaj kada obje valute prvi put ubacujemo u graf valuta, te jednostavno stavljamo roditelja od prvog na njega samoga,
  // te za roditelja od drugoga postavljamo prvoga te odnos izmedju njih

   if (roditelj[i].second==0&&roditelj[j].second==0){
        pair<string, double> par1 {i,1};
        roditelj[i]=par1;
        pair<string, double> par {i,odnos};
        roditelj[j]=par;
   }

// slucaj kada je prva valuta sama sebi roditelj, da bismo sve valute spojili tj. napravili disjunktni skup od njih moramo roditelja
// od roditelja od j postaviti  na i ukoliko roditelj od j postoji
// ukoliko roditelj od j ne postoji samo mu direktno postavljamo roditelja na i
  else if (roditelj[i].first==i && roditelj[j].first!=j){
        if (roditelj[j].second==0){
            pair<string, double> par {i,odnos};
            roditelj[j]=par;
        }
        else{
            pair<string, double> par {i,odnos};
            pair<string, double> par2;
            par2.first=i;
            par2.second=round(odnos*10000000/roditelj[j].second)/10000000;
            roditelj[roditelj[j].first]=par2;
        }
   }

 // slucaj kada je druga valuta sama sebi roditelj, da bismo sve valute spojili tj. napravili disjunktni skup od njih moramo roditelja od
// roditelja od i postaviti  na j ukoliko roditelj od i postoji
// ukoliko roditelj od i ne postoji samo mu direktno postavljamo roditelja na j

   else if (roditelj[j].first==j && roditelj[i].first!=i){
        if (roditelj[i].second==0){
            pair<string, double> par {j,round((10000000/odnos))/10000000};
            roditelj[i]=par;
        }
        else{
            pair<string, double> par {j,round(10000000/odnos)/10000000};
            pair<string, double> par2;
            par2.first=j;
            par2.second=round((10000000/odnos)/roditelj[i].second)/10000000;
            roditelj[roditelj[i].first]=par2;
        }
   }


   // Slicno kao i slucaj kada je i roditelj sam sebi, a j ima nekog drugog roditelja, samo je sad razlika sto je j sam sebi roditelj
   // i sve sto je u tom slucaju vrijedilo za roditelja od j,  sad vrijedi za j

   else if (roditelj[i].first==i && roditelj[j].first==j) {
        pair<string, double> par {i,round(odnos*10000000)/10000000};
        roditelj[j]=par;
   }

   // Slicno kao i kada je i sam sebi roditelj, samo je sada razlika sto moramo staviti kao roditelja od roditelja od j
   //  roditelja od i umjesto sa i ako roditelj od i postoji
   // Ako roditelj od i ne postoji onda se slucaj svodi na slucaj kad je j sam sebi roditelj
   // samo je sada razlika sto moramo postaviti roditelja od i na roditelja od j umjesto sa j ako roditelj od j postoji
   // ako nijedan roditelj ne postoji to je vec obradjeno u prethodnim slucajevima
   else if (roditelj[i].first!=i && roditelj[j].first!=j && roditelj[i].first!=roditelj[j].first) {

        if (roditelj[i].second!=0 && roditelj[j].second!=0){
        pair<string, double> par2;
            par2.first=roditelj[i].first;
            par2.second=round((roditelj[i].second*odnos /roditelj[j].second)*100000)/100000;
            roditelj[roditelj[j].first ]=par2;

       }
       else if (roditelj[i].second!=0 && roditelj[j].second==0){
        pair<string, double> par2;
       par2.first=roditelj[i].first;
       par2.second=roditelj[i].second*odnos;
        roditelj[j]=par2;

       }
       else if (roditelj[j].second!=0 && roditelj[i].second==0){
            pair<string, double> par2;
       par2.first=roditelj[j].first;
       par2.second=roditelj[j].second/odnos;
        roditelj[i]=par2;

       }

   }
}

// jednostavna funkcija koja gleda da li se valute nalaze u istom skupu, odnosno da li pripadaju istoj komponenti grafa
// te ako je odgovor potvrdan onda preko njihovog zajednickog roditelja racuna odnos, a ako ne onda sigurno ne postoji nikakva poveznica
// izmedju te dvije valute i rezultat je po defaultu 0

double Valuta::transfer2(string pocetni, string krajnji){

    string trenutni_roditelj_pocetnog=pocetni;
    string trenutni_roditelj_krajnjeg=krajnji;
    double trenutni_odnos_pocetnog=1;
    double trenutni_odnos_krajnjeg=1;
    while(trenutni_roditelj_pocetnog!=roditelj[trenutni_roditelj_pocetnog].first || trenutni_roditelj_krajnjeg!=roditelj[trenutni_roditelj_krajnjeg].first){
       trenutni_odnos_pocetnog*=roditelj[trenutni_roditelj_pocetnog].second;
       trenutni_odnos_krajnjeg*=roditelj[trenutni_roditelj_krajnjeg].second;
       trenutni_roditelj_pocetnog=roditelj[trenutni_roditelj_pocetnog].first;
       trenutni_roditelj_krajnjeg=roditelj[trenutni_roditelj_krajnjeg].first;
    }

    if (trenutni_roditelj_pocetnog==trenutni_roditelj_krajnjeg){
        return trenutni_odnos_krajnjeg/trenutni_odnos_pocetnog;

        }

    return 0;
}


