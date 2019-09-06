    #include "ABR.h"

    Nodo* ABR::GetMin(Nodo* a){
            if (a == NIL)
                return NULL;
            else if (a->GetSx() == NIL)
                return a;
            else
                return GetMin(a->GetSx());
                                       }
    Nodo* ABR::GetMax (Nodo* a){
            if (a == NIL)
                return NULL;
            else if (a->GetDx() == NIL)
                return a;
            else
                return GetMax(a->GetDx());
                                        }

    Nodo* ABR::add(Nodo* a){
    size ++;
    Nodo* x = root;
    Nodo* y = NIL;

    while ( x!= NIL) {

        y=x;

        if ( a->GetKey() < x->GetKey() )
           x=x->GetSx();
        else
           x=x->GetDx();
    }


     a->SetParent(y);

     if ( y == NIL )
            root = a;
     else
            if ( a->GetKey() < y->GetKey() )
                y->SetSx(a);
            else
                y->SetDx(a);

    return a;
                }

  Nodo* ABR::cerca(Nodo* a, const int i) {

          if (a == NIL)
                return NIL;
          else if (i == a->GetKey())
                return a;
          else if (i < a->GetKey())
                return cerca (a->GetSx(), i);
          else
                return cerca (a->GetDx(), i);
   }

   Nodo* ABR::del(Nodo* a){
                            size--;
                            Nodo* x = new Nodo();
                            Nodo* y = new Nodo();
                            /* UNO DEI DUE FIGLI O ENTRAMBI SONO NIL */
                            if (a->GetSx() == NIL || a->GetDx() == NIL)
                                    y = a;
                            else
                                  y = GetMin(a->GetDx());//ENTRAMBI I FIGLI ESISTONO, QUINDI TROVA SUCCESSORE

                            if (y->GetSx() != NIL)//SE IL SX ESISTE
                                    x = y->GetSx();
                            else
                                  x = y->GetDx();


                            if (x != NIL)//SE X ESISTE, IMPOSTA IL PADRE UGUALE AL PADRE DI Y
                                    x->SetParent(y->GetParent());


                            if (y->GetParent() == NIL) //SE IL PADRE DI Y E' UGUALE A NIL X E' LA RADICE
                                 root = x;

                            else {
                                    /*CASO DI UN SOLO FIGLIO A NIL*/
                                    if (y==y->GetParent()->GetSx())
                                         y->GetParent()->SetSx(x);
                                    else
                                            y->GetParent()->SetDx(x);
                            if (y!=a)
                             a->SetKey(y->GetKey());


                           }

                    return a;
    }

    void ABR::liberaABR (Nodo* a){
         if (a == NIL)
            delete a;
         else {
          if (a->GetSx() != NIL)
           liberaABR(a->GetSx());
          if (a->GetDx() != NIL)
           liberaABR(a->GetDx());
           delete a;
            a = NIL;
                   }
    }

    void ABR::stampa ( Nodo* a){

        if ( a != NIL ) {

        vector <Nodo*> coda;

        Nodo* x = new Nodo(a);

        coda.push_back(x);
        cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
        cout<<"%%%%%%%%%STAMPA ALBERO%%%%%%%%"<<endl;
        cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;

         cout<<"SIZE DELL'ALBERO: "<<size<<endl;

        while (coda.size()>0) {

        x = coda[0];
        coda.erase(coda.begin());


         string value = ((x->GetColor().get() == 0) ? "RED" : "BLACK");
        cout<<"NODO: "<<x->GetKey()<<"  "<<char(x->GetKey())<<" -- COLORE: "<<value<<endl;

        if (x->GetSx() != NULL) {cout<<"nodo sinistra = "<< x->GetSx()->GetKey()<<"  "<<char(x->GetSx()->GetKey())<<endl; coda.push_back(x->GetSx());}


        if (x->GetDx() != NULL) {cout<<"nodo destra  = "<< x->GetDx()->GetKey()<<"  "<<char(x->GetDx()->GetKey())<<endl; coda.push_back(x->GetDx());}
        cout<<"================================"<<endl;
        cout<<"================================"<<endl;
        }
        }
        else
            { cout<<"ALBERO VUOTO"<<endl;}
    }
