#ifndef QueuePriority_H_INCLUDED
#define QueuePriority_H_INCLUDED

#include <map>

#include "ARB.h"

class QueuePriority
{
    private:
        ARB* Albero;
    public:
        QueuePriority(const int i){ Albero = new ARB(i); }
        QueuePriority(map<char,int> x);
        QueuePriority(){ Albero = new ARB(); }
        ~QueuePriority(){ delete Albero;};


        bool Insert(const int i);

        int Getsize() { return Albero->GetSize(); }

        int Extract_MIN();
        int Extract_MAX();

        void Printcoda() { Albero->Print(); }


};

#endif // QueuePriority_H_INCLUDED

