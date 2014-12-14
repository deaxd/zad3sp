#include <iostream>
using namespace std;

struct klijent{
       string ime, prezime, spol, prioritet, vrsta;
       int ai,bi,ci,di;
       int dan, mj, god, s;
};

struct qu{
       klijent osoba[1000];
       int front, rear;
};

int AddOne(int n){
    return ((n+1)%1000);
}

klijent FrontQ(qu Q){
        return Q.osoba[Q.front];
}

void EnQueueQ(klijent x,qu &Q){
     Q.rear = AddOne(Q.rear);
     Q.osoba[Q.rear] = x;
}

void DeQueueQ(qu &Q){
     Q.front = AddOne(Q.front);
}

void InitQ(qu &Q){
     Q.front = 0;
     Q.rear = 999;
}

bool IsEmptyQ(qu &Q){
     return (AddOne(Q.rear) == Q.front)? 1 : 0;
}
