
#include "QueuePriority.h"

QueuePriority::QueuePriority(map < char, int > x)
{
    map<char, int>::iterator i = x.begin();
    Albero = new ARB(i->second); i++;
    while(i!=x.end()) {
    Insert(i->second);
    i++;
    }


}

bool QueuePriority::Insert(const int i)
{
Nodo* x = new Nodo(i, Albero->GetNIL(),Albero->GetNIL(),Albero->GetNIL(),RED);
if (x->GetKey()<1)
    {cout<<"IMPOSSIBILE INSERIRE ELEMENTO CON CHIAVE MINORE DI 1"<<endl; return 0;}

Albero->ins(x);

return 1;
}

int QueuePriority::Extract_MIN()
{

    Nodo* tmp = Albero->GetMin(Albero->GetRoot());
    int x = tmp->GetKey();
    Albero->canc(tmp);
    delete tmp;
    return x;
}

int QueuePriority::Extract_MAX()
{
    Nodo* tmp = Albero->GetMax(Albero->GetRoot());
    int x = tmp->GetKey();
    Albero->canc(tmp);

    return x;
}



