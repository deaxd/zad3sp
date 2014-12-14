#include <iostream>
#include <cstring>
#include <ctime>
#include "red_polje.h"
//#include "red_pokazivac.h"
using namespace std;

int N=0;
qu Q;
klijent *polje;

void generiranje(qu &Q){
     srand(time(NULL));
     
     cout << "Koliko cetvorki <ai,bi,ci,di> ? "; 
     cin >> N;
     polje = new klijent[N];
     cout << "Generira se " << N << " cetvorki. A to su: " << endl;
     for(int i=0; i<N; i++){
             polje[i].ai = rand()%450+10;
             polje[i].bi = rand()%720+80;
             polje[i].ci = rand()%5+1;
             polje[i].di = rand()%5+1;
             cout << "----------" << endl;
             cout << "Vrem jed ulaska nakon prethodnog: " << polje[i].ai << endl
                  << "Vrem jed posluzivanja: " << polje[i].bi << endl
                  << "Prioritet: ";
             if(polje[i].ci == 1) {
                        cout << "VIP" << endl;
                        polje[i].prioritet = "VIP";
             }
             if(polje[i].ci == 2) {
                        cout << "invalid" << endl;
                        polje[i].prioritet = "invalid";
             }
             if(polje[i].ci == 3) {
                        cout << "trudnica" << endl;
                        polje[i].prioritet = "trudnica";
             }
             if(polje[i].ci == 4) {
                        cout << "umirovljenik" << endl;
                        polje[i].prioritet = "umirovljenik";
             }
             if(polje[i].ci == 5) {
                        cout << "obicni smrtnik" << endl;
                        polje[i].prioritet = "smrtnik";
             }
             cout << "Vrsta usluge: ";
             if(polje[i].di == 1) {
                        cout << "predaja/preuzimanje posiljke" << endl;
                        polje[i].vrsta = "predaja/preuzimanje posiljke";
             }
             if(polje[i].di == 2) {
                        cout << "placanje racuna" << endl;
                        polje[i].vrsta = "placanje racuna";
             }
             if(polje[i].di == 3) {
                        cout << "uplata lutrije" << endl;
                        polje[i].vrsta = "uplata lutrije";
             }
             if(polje[i].di == 4) {
                        cout << "Western Union" << endl;
                        polje[i].vrsta = "Western Union";
             }
             if(polje[i].di == 5) {
                        cout << "EvoTV" << endl;
                        polje[i].vrsta = "EvoTV";
             }
     }
}

int brojac=0;
void unos(qu &Q){
     klijent novi;
     string ime_m[10] = {"Stjepan","Mateo","David","Ivo","Pero","Luka","Ivan","Dominik","Fran","Nikola"},
            ime_z[10] = {"Ana","Dolores","Maja","Ivana","Marija","Lana","Nikolina","Nina","Martina","Paula"},
            prezime[10] = {"A","B","C","D","E","F","G","H","I","J"};
     
     for(int i=0; i<5; i++){
             for(int j=0; j<N; j++){
                     brojac++;

                     novi.ai = polje[j].ai;
                     novi.bi = polje[j].bi;
                     novi.ci = polje[j].ci;
                     novi.di = polje[j].di;
                     if(novi.ci == 1) {
                                novi.prioritet = "VIP";
                     }
                     if(novi.ci == 2) {
                                novi.prioritet = "invalid";
                     }
                     if(novi.ci == 3) {
                                novi.prioritet = "trudnica";
                     }
                     if(novi.ci == 4) {
                                novi.prioritet = "umirovljenik";
                     }
                     if(novi.ci == 5) {
                                novi.prioritet = "smrtnik";
                     }
                     
                     if(novi.di == 1) {
                                novi.vrsta = "predaja/preuzimanje posiljke";
                     }
                     if(novi.di == 2) {
                                novi.vrsta = "placanje racuna";
                     }
                     if(novi.di == 3) {
                                novi.vrsta = "uplata lutrije";
                     }
                     if(novi.di == 4) {
                                novi.vrsta = "Western Union";
                     }
                     if(novi.di == 5) {
                                novi.vrsta = "EvoTV";
                     }

                     novi.s = rand()%3;
                     if(novi.ci == 3) novi.s = 1;
                     if(novi.s != 1) {
                               novi.s = 0;
                               novi.spol = "musko";
                     }
                     if(novi.s == 1) novi.spol = "zensko";
                     
                     if(novi.s == 0) novi.ime = ime_m[rand()%10];
                     if(novi.s == 1) novi.ime = ime_z[rand()%10];
                     novi.prezime = prezime[rand()%10];          
                     if(novi.ci == 3) novi.god = rand()%31+1964; // trudnice 18-55 god
                     if(novi.ci == 4) novi.god = rand()%19+1930; // umirovljenici 65-84
                     else novi.god = rand()%65+1930;
                     
                     novi.mj = rand()%11+1;
                     
                     if (novi.mj == 1 || novi.mj == 3 || novi.mj == 5 || novi.mj == 7 || novi.mj == 8 || novi.mj == 10 || novi.mj == 12) 
                        novi.dan = rand()%30+1;
                     if (novi.mj == 2 && novi.god % 4 == 0) 
                        novi.dan = rand()%28+1;
                     if (novi.mj == 2 && novi.god % 4 != 0) 
                        novi.dan = rand()%27+1;
                     if (novi.mj == 4 || novi.mj == 6 || novi.mj == 9 || novi.mj == 11) 
                        novi.dan = rand()%29+1;
                     EnQueueQ(novi,Q);
             }
     }
}

void ispis(qu &Q){
     klijent tekuci;
     qu pom;
     InitQ(pom);
     
     while(!IsEmptyQ(Q)){
                         tekuci = FrontQ(Q);
                         cout << "Ime i prezime: " << tekuci.ime << " " << tekuci.prezime << endl
                              << "Spol: " << tekuci.spol << endl
                              << "Datum rodjenja: " << tekuci.dan << "." << tekuci.mj << "." << tekuci.god << endl
                              << "Prioritet i vrsta: " << tekuci.prioritet << ", " << tekuci.vrsta << endl
                              << "===================" << endl;
                         DeQueueQ(Q);
                         EnQueueQ(tekuci,pom);
     }
     while(!IsEmptyQ(pom)){
                           tekuci = FrontQ(pom);
                           DeQueueQ(pom);
                           EnQueueQ(tekuci,Q);
     }
}

void ispis_ime(qu &Q){
     klijent tekuci;
     qu pom;
     InitQ(pom);
     
     while(!IsEmptyQ(Q)){
                         tekuci = FrontQ(Q);
                         cout << "Ime i prezime: " << tekuci.ime << " " << tekuci.prezime << endl;
                         cout << "Vrsta: " << tekuci.vrsta << endl;
                         cout << "----------------------" << endl;
                         DeQueueQ(Q);
                         EnQueueQ(tekuci,pom);
     }
     while(!IsEmptyQ(pom)){
                           tekuci = FrontQ(pom);
                           DeQueueQ(pom);
                           EnQueueQ(tekuci,Q);
     }
}

void sort(qu &Q){
     klijent tekuci;
     qu pom1, pom2;
     InitQ(pom1);
     InitQ(pom2);
     
     for(int i=1; i<=5; i++){
             while(!IsEmptyQ(Q)){
                                 tekuci = FrontQ(Q);
                                 DeQueueQ(Q);
                                 if(tekuci.ci == i) EnQueueQ(tekuci,pom1);
                                 else EnQueueQ(tekuci,pom2);
             }
             while(!IsEmptyQ(pom2)){
                                    tekuci = FrontQ(pom2);
                                    DeQueueQ(pom2);
                                    EnQueueQ(tekuci,Q);
             }
     }
     while(!IsEmptyQ(pom1)){
                            tekuci = FrontQ(pom1);
                            DeQueueQ(pom1);
                            EnQueueQ(tekuci,Q);
     }
}

void sort_obrnuto(qu &brzi){
     klijent tekuci;
     qu pom1, pom2;
     InitQ(pom1);
     InitQ(pom2);
     
     for(int i=5; i>=1; i--){
             while(!IsEmptyQ(brzi)){
                                 tekuci = FrontQ(brzi);
                                 DeQueueQ(brzi);
                                 if(tekuci.di == i) EnQueueQ(tekuci,pom1);
                                 else EnQueueQ(tekuci,pom2);
             }
             while(!IsEmptyQ(pom2)){
                                    tekuci = FrontQ(pom2);
                                    DeQueueQ(pom2);
                                    EnQueueQ(tekuci,brzi);
             }
     }
     while(!IsEmptyQ(pom1)){
                            tekuci = FrontQ(pom1);
                            DeQueueQ(pom1);
                            EnQueueQ(tekuci,brzi);
     }
}

bool nadjen = false;
int brojac_jarac = 0;
void jarac(qu &Q){
     klijent tekuci;
     if(IsEmptyQ(Q)) return;
     tekuci = FrontQ(Q);
     
     
     int god;
     god = 2014 - tekuci.god;
     
     if( tekuci.dan >= 22 && tekuci.mj == 12 && god < 40 && tekuci.di == 3) {
         cout << "Ime, prezime, godina: "
              << tekuci.ime << " " << tekuci.prezime << "; " << god << endl;
         nadjen = true;
         brojac_jarac++;
     }
     if( tekuci.dan <=20 && tekuci.mj == 1 && god < 40 && tekuci.di == 3) {
         cout << "Ime, prezime, godina: "
              << tekuci.ime << " " << tekuci.prezime << "; " << god << endl;
         nadjen = true;
         brojac_jarac++;
     }
     DeQueueQ(Q);
     jarac(Q);
     EnQueueQ(tekuci,Q);
}

int brojac_trudnica = 0;
void trudnice(qu &Q){
     klijent tekuci;
     qu pom;
     InitQ(pom);
     bool trudnica = false;
     
     cout << "Trudnice koje predugo cekaju na uslugu EvoTV" << endl;
     while(!IsEmptyQ(Q)){
                         tekuci = FrontQ(Q);
                         DeQueueQ(Q);
                         EnQueueQ(tekuci,pom);
     }
     while(!IsEmptyQ(pom)){
                           tekuci = FrontQ(pom);
                           DeQueueQ(pom);
                           if(tekuci.ci == 3 && tekuci.di == 5) {
                                        cout << "Trudnica: " << tekuci.ime << " " << tekuci.prezime << endl;
                                        trudnica = true;
                                        brojac_trudnica++;
                           }
                           else EnQueueQ(tekuci,Q);
     }
     if(!trudnica) cout << "Nema trudnica :(" << endl;
     cout << "Stanje glavnog reda: " << endl;
     ispis_ime(Q);
}

int pos=0,rac=0,lut=0,wu=0,evo=0;
int brojac_ostali = 0;
void brzi_red(qu &Q, qu &brzi){
     klijent tekuci;
     
     if(IsEmptyQ(Q)) return;
     
     tekuci = FrontQ(Q);
     DeQueueQ(Q);
     brzi_red(Q,brzi);

     if(tekuci.ci == 4) EnQueueQ(tekuci,brzi);
     else if(tekuci.ci != 4 && pos < 2 && tekuci.di == 1) {
            EnQueueQ(tekuci,brzi);
            pos++;
     }
     else if(tekuci.ci != 4 && rac < 2 && tekuci.di == 2) {
            EnQueueQ(tekuci,brzi);
            rac++;
     }
     else if(tekuci.ci != 4 && lut < 2 && tekuci.di == 3) {
            EnQueueQ(tekuci,brzi);
            lut++;
     }
     else if(tekuci.ci != 4 && wu < 2 && tekuci.di == 4) {
            EnQueueQ(tekuci,brzi);
            wu++;
     }
     else if(tekuci.ci != 4 && evo < 2 && tekuci.di == 5) {
            EnQueueQ(tekuci,brzi);
            evo++;
     }
     else {
          EnQueueQ(tekuci,Q);
          brojac_ostali++;
     }
}

int main(){
    qu Q;
    InitQ(Q);
    qu brzi;
    InitQ(brzi);
    bool generirano = false;
    
    int izbor;
    do{
       cout << "---------------" << endl
            << "I Z B O R N I K" << endl
            << "---------------" << endl
            << "1. Generiranje N cetvorki <ai,bi,ci,di>" << endl
            << "2. Unos zapisa o klijentu (ime, prezime, datum rodjenja, spol)" << endl
            << "3. Ispis jarac, godina < 40, uplata lutrije" << endl
            << "4. Odlazak trudnica" << endl
            << "5. Brzi red" << endl
            << "8. Ispis" << endl
            << "9. Izlaz iz programa" << endl;
       cin >> izbor;
       switch(izbor){
                     case 1: 
                          generiranje(Q);
                          generirano = true;
                          break;
                     case 2: 
                          if(!generirano) cout << "Odaberi 1 i generiraj N cetvorki!" << endl;
                          else {
                               unos(Q);
                               sort(Q);
                               ispis(Q);
                               cout << "Dodalo se " << brojac << " novih klijenata. " << endl;
                          }
                          break;
                     case 3: 
                          if(!generirano) cout << "Odaberi 1 i generiraj N cetvorki!" << endl;
                          else {
                               jarac(Q);
                               if (nadjen == false) cout << "Nema ih!" << endl;
                               if (nadjen == true) cout << "Pronadjeno je: " << brojac_jarac << endl;
                          }
                          break;
                     case 4: 
                          if(!generirano) cout << "Odaberi 1 i generiraj N cetvorki!" << endl;
                          else {
                               trudnice(Q);
                               cout << "Pronadjeno je: " << brojac_trudnica << endl;
                          }
                          break;
                     case 5: 
                          if(!generirano) cout << "Odaberi 1 i generiraj N cetvorki!" << endl;
                          else {
                               brzi_red(Q,brzi);
                               sort_obrnuto(brzi);
                               ispis_ime(brzi);
                               cout << "==============================================" << endl
                                    << "STANJE GLAVNOG REDA, NAKON PREBACIVANJA U BRZI" << endl
                                    << "==============================================" << endl;
                               ispis_ime(Q);
                               cout << "U brzom redu ih je: " << brojac - brojac_ostali << endl;
                               cout << "U glavnom redu ih je: " << brojac_ostali << endl;
                          }
                          break;
                     case 8:
                          if(!generirano) cout << "Odaberi 1 i generiraj N cetvorki!" << endl;
                          else ispis_ime(Q);
                          break;
       }
    }while(izbor!=9);
    return 0;
}
