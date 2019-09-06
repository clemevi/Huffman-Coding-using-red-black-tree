#ifndef NODORB_H_INCLUDED
#define NODORB_H_INCLUDED

#include "Nodo.h"
#include "Colore.h"

class NodoRB : public Nodo
{
    private:
        Colore color;

    public:
        NodoRB (string c, int k = -1, Nodo* p = NULL, Nodo* s = NULL, Nodo* d = NULL):Nodo(k,p,s,d) {hide_color cc = c; color=c; }
        NodoRB (NodoRB* copia):Nodo(copia->key,copia->parent,copia->sx,copia->dx) { color = copia->GetColor(); }

        Colore GetColor() { return color;}


}

#endif // NODORB_H_INCLUDED
