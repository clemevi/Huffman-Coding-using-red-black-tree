#ifndef COLORE_H_INCLUDED
#define COLORE_H_INCLUDED

#include <iostream>

using namespace std;

enum hide_color
  { RED, BLACK, NULLO } ;

class Colore
{
    private:
        hide_color value;

    public:
        Colore(hide_color c = NULLO) { value=c; }

        hide_color get() { return value; }
        void change() { if (value!=NULLO) { value = ((value == RED) ? BLACK : RED); } else { cout<<"COLORE NULLO"<<endl; }}
        void set(hide_color x) { value = x;}
        void set(Colore x) { value = x.get();}


        bool operator ==( hide_color x ) { return( value == x ) ; }
        bool operator !=( hide_color x ) { return( value != x ) ; }



};
#endif
