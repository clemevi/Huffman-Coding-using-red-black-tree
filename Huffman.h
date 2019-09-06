#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include <vector>
#include <stdlib.h>
#include <fstream>

#include "QueuePriority.h"

class Huffman
{
    private:

        Huffman(){};
        ~Huffman();

        map<char, string> map_coding; //MAPPA CHE CONTIENE LA CODIFICA DI OGNI CARATTERE
        map<char, int> map_freq; //MAPPA CHE CONTIENE LA FREQUENZA DI OGNI CARATTERE
        Nodo* root_huff; //NODO RADICE DELL'ALBERO DI HUFFMAN

        string Treefile; //STRINGA CHE CONTIENE LA SERIALIZZAZIONE DELL'ALBERO
        string txt; //STRINGA CHE CONTIENE IL TESTO DEL FILE
        int comp; //TASSO DI COMPRESSIONE

        //METODI

        //STAMPA UNA COPPIA DI VALORI DI UNA MAPPA
        void PrintCouple(const pair<const char,string>& r) {cout<<" char = "<<r.first<<"  cod = "<<r.second<<endl;}

        Nodo* CreateHuffmanTree();//CREA ALBERO DI HUFFMAN
        void CreateMapCoding(Nodo* x, string cod);//CREA MAPPA DELLE CODIFICHE

        bool Write_Encoding(const char* name);//SCRIVE IL FILE CODIFICATO
        bool Write_Decoding(const char * ReadFile, const char* WriteFile);//SCRIVE IL FILE DECODIFICATO

        Nodo* RebuildTree (string tree, long &i);//RICOSTRUISCE L'ALBERO A PARTIRE DALLA SUA STRINGA CODIFICATA

        bool VerifyExt(const char* name, const char* x);//VERIFICA L'ESTENSIONE DEI NOMI DEI FILE PASSATI IN INPUT

        Nodo* GetRoot() { return root_huff;}//RESTITUISCE LA RADICE DELL'ALBERO DI HUFFMAN

        void free_HuffmanTree(Nodo* x);



    public:

        //CREA UN ISTANZA STATICA DELLA CLASSE AL SUO PRIMO RICHIAMO. SARA' LA STESSA PER TUTTA LA DURATA DEL PROGRAMMA
        static Huffman& get_instance() { static Huffman instance;  return instance;  }

        //STAMPA MAPPA DELLE CODIFICHE
        void printMAP() { map<char, string>::const_iterator i; for(i=map_coding.begin(); i!=map_coding.end(); i++) PrintCouple(*i); }

        bool Encode(const char* name, const char* out);
        bool Decode(const char* name, const char* out);


};


#endif // HUFFMAN_H_INCLUDED
