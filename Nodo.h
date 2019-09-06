#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

using namespace std;


#include "Colore.h"

class Nodo {
    private:

       int key;
       Nodo* parent;
       Nodo* sx;
       Nodo* dx;
       Colore color;


    public:

       Nodo (int k = -1, Nodo* p = NULL, Nodo* s = NULL, Nodo* d = NULL, Colore c=NULLO): key (k), parent(p), sx (s), dx (d), color(c) {}
       Nodo (Nodo* copia): key(copia->key), parent(copia->parent), sx(copia->sx), dx(copia->dx){color=copia->GetColor().get();}

        //METODI GET
        Nodo* GetParent() const {return parent;}
        Nodo* GetSx() const {return sx;}
        Nodo* GetDx() const {return dx;}
        int   GetKey() const {return key;}
        Colore GetColor() const {return color;}
        void SetColor(hide_color x) {color = x;}
        void SetColor(Colore x) {color = x;}
        //METODI SET
        Nodo* SetParent(Nodo* p) {return parent=p;}
        Nodo* SetSx(Nodo* s) {return sx=s;}
        Nodo* SetDx(Nodo* d) {return dx=d;}
        int   SetKey(int k) {return key=k;}


             };


#endif // NODO_H_INCLUDED
