#include "Huffman.h"


Huffman::~Huffman(){
            map_freq.clear();
            map_coding.clear();
            Treefile.clear();
            txt.clear();
            free_HuffmanTree(root_huff);
            }

bool Huffman::VerifyExt(const char* name, const char* x){
string  str = name;

size_t pos = str.rfind('.');
    if(pos != std::string::npos)
    { std::string ext = str.substr(++pos);
        if(ext != x){
            cout << "ERRORE, IL NOME "<<name<<" NON E' NEL FORMATO CORRETTO.\nINSERIRE NOME CON ESTENSIONE ."<<x<<endl; return 0;}

    } else { cout << "ERRORE, IL NOME "<<name<<" NON E' NEL FORMATO CORRETTO.\nINSERIRE NOME CON ESTENSIONE ."<<x<<endl; return 0;}

    return 1;
}

void Huffman::free_HuffmanTree (Nodo* a){
         if (a == NULL)
            delete a;
         else {
          if (a->GetSx() != NULL)
           free_HuffmanTree(a->GetSx());
          if (a->GetDx() != NULL)
           free_HuffmanTree(a->GetDx());
           delete a;
            a = NULL;
                   }
    }

bool Huffman::Encode(const char* name, const char* out){

if( VerifyExt(name,"txt") && VerifyExt(out,"huff") ) {
        ifstream file(name);
            if (file) {
                char ch = file.get();

                cout<<"LETTURA FILE..."<<endl;
                while(!file.eof()){
                    txt.push_back(ch);
                    map_freq[ch]++;
                    file.get(ch);
                }

                file.close();

            cout<<"\nCOSTRUZIONE ALBERO DI HUFFMAN"<<endl;
            root_huff = CreateHuffmanTree();

            string codd;
            cout<<"\nCOSTRUZIONE MAPPA CODIFICHE"<<endl;
            CreateMapCoding(root_huff,codd);

            cout<<"\nINIZIO SCRITTURA CODIFICA"<<endl;
            Write_Encoding(out);

            cout<<"\nSCRITTURA ESEGUITA CON SUCCESSO"<<endl;

            return 1;}

            else {cout<<"FILE NOT FOUND"<<endl; return 0;}

     } else return 0;
}

bool Huffman::Decode(const char* name, const char* out){

if( VerifyExt(name,"huff") && VerifyExt(out,"txt") ){

return Write_Decoding(name,out); } else {return 0;}

}

Nodo* Huffman::CreateHuffmanTree() {
QueuePriority* coda = new QueuePriority(map_freq);
vector <Nodo*> vet;
vector <Nodo*>::iterator i;
Nodo* parent = new Nodo();
int s,d;
   while (coda->Getsize()>1) {


        s = coda->Extract_MIN();
        d = coda->Extract_MIN();
        Nodo* sx = new Nodo();
        Nodo* dx = new Nodo();

        //CONTROLLO SE ESISTE GIA IL MINIMO TRA I NODI REINSERITI
        i=vet.begin();
        while(i != vet.end()) {
              if  ((*i)->GetKey() == s ) { sx = *i; vet.erase(i); break;}
            i++;
        }

        i=vet.begin();
        while(i != vet.end()) {

            if  ((*i)->GetKey() == d ) {  dx = *i; vet.erase(i); break; }
            i++;
        }

        //SE IL MINIMO NON VIENE TROVATO VUOL DIRE CHE E' UN CARATTERE
        //QUINDI UNA FOGLIA, DI CONSEGUENZA GLI IMPOSTO LA FREQUENZA
        if (sx->GetKey()==-1) { sx->SetKey(s);  }
        if (dx->GetKey()==-1) { dx->SetKey(d);  }

        //CREO LA FREQUENZA DEL PADRE E LO ALLOCO
        int freq = sx->GetKey()+dx->GetKey();
        parent = new Nodo(freq,NULL,sx,dx,NULLO);
        //LO INSERISCO NEL VETTORE DEI NODI PADRI
        vet.push_back(parent);

        //INSERISCO LA FREQUENZA DEL PADRE NELLA CODA
        coda->Insert(freq);
       }
delete coda;
return parent;
}

void Huffman::CreateMapCoding(Nodo* x, string cod) {

        map<char, int>::iterator i;

    if ( x->GetSx() == NULL && x->GetDx() == NULL) {

        //CERCA FREQUENZA SU MAPPA
          i = map_freq.begin();
       while( i!=map_freq.end()) {
       if(i->second == x->GetKey())
       {
        map_coding[i->first] = cod;

        Treefile.push_back(1);
        Treefile.push_back((int)i->first);

        map_freq.erase(i);

        break;
       }
       i++; }

        //ASSEGNA PUNTATORE A CHAR

    } else
        {
            if(x->GetSx() != NULL){
                        cod.append("0");
                        Treefile.push_back(0);
                        CreateMapCoding(x->GetSx(),cod); }

            cod.erase(cod.end()-1);
            if(x->GetDx() != NULL){
                        cod.append("1");
                        Treefile.push_back(0);
                        CreateMapCoding(x->GetDx(),cod); }
            cod.erase(cod.end()-1);
        }


}

Nodo* Huffman::RebuildTree (string tree, long &ix) {

 ix++;

 unsigned char ch = tree[ix];

  Nodo* n;
  Nodo* sx= NULL;
  Nodo* dx= NULL;

    if (ch)  return n = new Nodo(tree[++ix]);

    else { sx = RebuildTree(tree, ix); ch = tree[++ix];

     dx = RebuildTree(tree, ix); }


    return n = new Nodo(ix,NULL,sx,dx);
}

bool Huffman::Write_Encoding(const char * name){
string bitcode;
long i = 0, ibit = 8, nbit = 0;
unsigned char ch = 0 , cc = 0;
//CONTINUA FINCHE L'I-ESIMO CARATTERE SARA DIVERSO DALL'ULTIMO
while (txt[i] != *txt.end()){

   ch = txt[i];//CH E' UGUALE ALL'I-ESIMO CARATTERE

   string tmp = map_coding[ch];//tmp contiene il char ch codificato sottoforma di stringa di 1 e 0

            //PER OGNI CARATTERE DI TMP
            for (unsigned int j=0; j<tmp.size(); j++) {
                unsigned char x;
                x = ((tmp[j] == '0') ? 0 : 1);
                cc = (cc | (x << --ibit));
                nbit++;
                if (ibit<=0) { ibit = 8; bitcode.push_back(cc); cc = 0;}
            }
   i++;
}

if(ibit>0) {bitcode.push_back(cc);}

comp = 100-((nbit*100)/(i*8));//nbit->numero di bit realmente scritti i->numero di byte del file di origine

ofstream SaveFile(name);
SaveFile <<nbit<<char(20)<<Treefile<<char(20)<<bitcode;
SaveFile.close();
cout<<"FILE CODIFICATO"<<endl;
cout<<"TASSO DI COMPRESSIONE -> "<<comp<<"%"<<endl;

return 1;
}

bool Huffman::Write_Decoding(const char * ReadFile, const char* WriteFile){

    ifstream Rfile(ReadFile);

if (Rfile) {


    Rfile.seekg (0, Rfile.beg);


        //RECUPERO SIZE DEI BIT SCRITTI NELLA CODIFICA
        Rfile.ignore(1024,char(20));
        long y = Rfile.tellg();
        Rfile.seekg(Rfile.beg);
        char* size_txt = new char [y];
        Rfile.get(size_txt,y); long size = atol(size_txt);
        delete size_txt;

        cout<<"IL SIZE DEI BIT CODIFICATI E = "<<size<<endl;

        Rfile.ignore(1024,char(20)); Rfile.ignore(1024,char(20));//mi posizioni alla fine della codifica dell'albero
        long x = Rfile.tellg();//mi salvo la posizione
        char* tree = new char [x];//preparo un puntatore a char per salvare l'albero
        Rfile.seekg(y);//mi posiziono all'inizio dell'albero
        Rfile.read(tree,x-y-1);
        string treeS;
        for(long tmp=0; tmp<=(x-y-2);tmp++) treeS.push_back(int(tree[tmp]));
        delete tree;


        long ii = -1;
        root_huff=RebuildTree(treeS,ii);
        cout<<"ALBERO RICOSTRUITO..."<<endl;

        Rfile.seekg(x);
        char ch;

        ////////////////////SCRIVO SU FILE///////////////////////////
        ofstream Wfile(WriteFile);

        long j = 0;
        const Nodo* nod = root_huff;

        while (!Rfile.eof()){

            Rfile.get(ch);

        /*PER OGNI BIT*/
        for (int i=7; i>=0 ; i--)

                    if (j<size) {


                        unsigned char bit = ((ch>>i) & 1);

                        if (bit) {nod = nod->GetDx();} else {nod = nod->GetSx();}

                        if (nod->GetSx() == NULL && nod->GetDx() == NULL) { Wfile<<char(nod->GetKey());
                                                                            nod = root_huff;}
                      j++;
                    }else continue;
        }
cout<<"FINE DECODIFICA"<<endl;

Rfile.close();
Wfile.close();

return 1;

  } else { cout<< "FILE NOT FOUND." <<endl; return 0; }

  }
