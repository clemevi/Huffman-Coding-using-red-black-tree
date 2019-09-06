#include "ARB.h"

void ARB::rotate_sx(Nodo* x) {

    Nodo* y = x->GetDx();
    x->SetDx(y->GetSx());
    if (y->GetSx() != NIL )
            y->GetSx()->SetParent(x);

    y->SetParent(x->GetParent());


	if( x->GetParent() == NIL )
            root = y;
	else
    {
		if( x == x->GetParent()->GetSx())
			x->GetParent()->SetSx(y);
		else
			x->GetParent()->SetDx(y);
	}


	y->SetSx(x);
	x->SetParent(y);
}

void ARB::rotate_dx(Nodo* x) {
    Nodo* y = x->GetSx();
    x->SetSx(y->GetDx());

    if (y->GetDx() != NIL )
        y->GetDx()->SetParent(x);

    y->SetParent(x->GetParent());


	if( x->GetParent() == NIL )
		root = y;
	else
    {
        if( x == x->GetParent()->GetDx())
			x->GetParent()->SetDx(y);
		else
			x->GetParent()->SetSx(y);
	}


	y->SetDx(x);
	x->SetParent(y);
}


Nodo* ARB::ins(Nodo* &x){
//RESETTO NODO DA INSERIRE
x->SetColor(RED);
x->SetSx(NIL);
x->SetDx(NIL);
x->SetParent(NIL);

add(x);

InsertFixUP(x);

return x;
}


void ARB::InsertFixUP(Nodo* x) {

while ( x->GetParent()->GetColor() == RED) {

        if(x->GetParent() == x->GetParent()->GetParent()->GetSx()) {

        Nodo* y = x->GetParent()->GetParent()->GetDx();

            if(y->GetColor() == RED) {

                x->GetParent()->SetColor(BLACK);
                y->SetColor(BLACK);
                x->GetParent()->GetParent()->SetColor(RED);
                x=x->GetParent()->GetParent();
                }
            else
            {
                if(x==x->GetParent()->GetDx()){
                        x=x->GetParent();
                        rotate_sx(x);
                }

                x->GetParent()->SetColor(BLACK);
                x->GetParent()->GetParent()->SetColor(RED);
                x->GetParent()->GetDx()->SetColor(BLACK);
                rotate_dx(x->GetParent()->GetParent());
            }
        }

        else

        {

           Nodo* y=x->GetParent()->GetParent()->GetSx();

            if( y->GetColor()== RED){
                x->GetParent()->SetColor(BLACK);
                y->SetColor(BLACK);
                x->GetParent()->GetParent()->SetColor(RED);
                x=x->GetParent()->GetParent();
                }
            else{
                if(x==x->GetParent()->GetSx()){
                    x=x->GetParent();
                    rotate_dx(x);}
                    x->GetParent()->SetColor(BLACK);
                    x->GetParent()->GetParent()->SetColor(RED);
                    x->GetParent()->GetSx()->SetColor(BLACK);
                    rotate_sx(x->GetParent()->GetParent());
                }
        }
    }
root->SetColor(BLACK);

}

Nodo* ARB::canc (Nodo* &a) {

if (a != NIL)
    { return del(a);}
else
    {cout<<"IL NODO CON CHIAVE "<< a->GetKey() <<" NON ESISTE"<<endl; return NIL;}
}

void ARB::DeleteFixUP(Nodo* &x) {

{
    while(x != root && x->GetColor() == BLACK )
    {

        Nodo* n;
		if( x->GetParent()->GetSx() == x )
		{
			n = x->GetParent()->GetDx();


			if( n->GetColor() == RED)
			{
				n->SetColor(BLACK);
				x->GetParent()->SetColor(RED);
				rotate_sx(x->GetParent());
				n = x->GetParent()->GetDx();
			}


			if(n->GetSx()->GetColor() == BLACK && n->GetDx()->GetColor() == BLACK )
			{
				n->SetColor(RED);
				x = x->GetParent();
			}
			else
			{
				if( n->GetDx()->GetColor() == BLACK )
				{
					n->GetSx()->SetColor(BLACK);
					n->SetColor(RED);
					rotate_dx(n);
					n = x->GetParent()->GetDx();

				}

				n->SetColor(x->GetParent()->GetColor());
				x->GetParent()->SetColor(BLACK);
				n->GetDx()->SetColor(BLACK);
				rotate_sx(x->GetParent());
				x = root;
			}
		}

		else
        {	n = x->GetParent()->GetSx();

			if( n->GetColor() == RED )
			{
				n->SetColor(BLACK);
				x->GetParent()->SetColor(RED);
				rotate_dx(x->GetParent());
				n = x->GetParent()->GetSx();
			}

			if(n->GetDx()->GetColor() == BLACK && n->GetSx()->GetColor() == BLACK)
			{
				n->SetColor(RED);
				x = x->GetParent();
			}
			else
			{
				if( n->GetSx()->GetColor() == BLACK )
				{
					n->GetDx()->SetColor(BLACK);
					n->SetColor(RED);
					rotate_sx(n);
					n = x->GetParent()->GetSx();
				}
				n->SetColor(x->GetParent()->GetColor());
				x->GetParent()->SetColor(BLACK);



				n->GetSx()->SetColor(BLACK);

				rotate_dx(x->GetParent());
				x = root;
			}
		}
	}
	x->SetColor(BLACK);
}

}

Nodo* ARB::del(Nodo* &a){

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


                           //IMPOSTA IL PADRE UGUALE AL PADRE DI Y
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
                            //SE IL NODO CANCELLATO ERA NERO, CHIAMA DELETEFIXUP PER RIPRISTINARE LE PROPRIETA' DELL'ALBERO
                           if (y->GetColor()==BLACK ) { DeleteFixUP(x);}

                    return a;
    }



