#ifndef ABR_H_INCLUDED
#define ABR_H_INCLUDED

#include <vector>

#include "Nodo.h"

class ABR {

    protected:

       Nodo* root;
       Nodo* NIL; //NODO SENTINELLA

       int size;

       Nodo* add (Nodo* x);
       Nodo* del (Nodo* a);
       Nodo* cerca (Nodo* a, const int i);


    public:
       void stampa ( Nodo* a);
       ABR () {NIL = new Nodo(); root = NIL; size = 0;}
       ABR (int x) { NIL = new Nodo(); root = new Nodo(x,NIL,NIL,NIL); size=1; }
       void liberaABR (Nodo* a);
       virtual ~ABR() {liberaABR(root);}
       Nodo* GetRoot() {return root;}
       Nodo* GetNIL() {return NIL;}
       Nodo* GetMin (Nodo* a);
       Nodo* GetMax (Nodo* a);
       int GetSize() {return size;}
       virtual Nodo* ins (Nodo* &a) { return add (a);}
       virtual Nodo* canc (Nodo* &a) {  return del (a);}


       bool esiste (const int i) { bool value = ((cerca (root, i) == NIL) ? 0 : 1); return value; }
       void Print () {stampa(root);}

};


#endif // ABR_H_INCLUDED
