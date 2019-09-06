#ifndef ARB_H_INCLUDED
#define ARB_H_INCLUDED

#include "ABR.h"

class ARB : public ABR
{   private:
      void rotate_sx(Nodo* x);
      void rotate_dx(Nodo* x);
      void InsertFixUP(Nodo* x);
      Nodo* del(Nodo* &a);
      void DeleteFixUP(Nodo* &x);

    public:
       ARB():ABR() {root->SetColor(BLACK); NIL->SetColor(NULLO); }
       ARB(int x):ABR(x) { root->SetColor(BLACK); NIL->SetColor(NULLO);}
       Nodo* ins(Nodo* &a);
       Nodo* canc (Nodo* &a);
};

#endif // ARB_H_INCLUDED
