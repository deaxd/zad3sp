#include <iostream>
using namespace std;

struct klijent{
       string ime, prezime, spol, prioritet, vrsta;
       int ai,bi,ci,di;
       int dan, mj, god, s;
};

struct nj{
       klijent osoba;
       nj *next;
};

struct qu{
       nj *front,*rear;
};

klijent FrontQ(qu &Q){
         return Q.front->next->osoba;  
}

void EnQueueQ(klijent x, qu &Q){
     Q.rear->next = new nj; 
     Q.rear = Q.rear->next;
     Q.rear->next = NULL;
     Q.rear->osoba = x;
}

void DeQueueQ(qu &Q){
     nj *pom = Q.front;
     Q.front = Q.front->next;
     delete pom;
}

void InitQ(qu &Q){
     Q.front = new nj;
     Q.rear = Q.front;
}

bool IsEmptyQ(qu &Q){
     return (Q.rear == Q.front) ? 1: 0;
}
