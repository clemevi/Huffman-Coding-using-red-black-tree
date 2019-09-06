#include "Huffman.h"
#include "string.h"

using namespace std;

int main(int argc, char* argv[])

{
    if (argc != 4) {
                                cout<<"\n\nINSERIRE UN NUMERO DI ARGOMENTI PARI A 4\nSintassi: "<< argv[0]<<" operazione nomefileinput nomefileoutput\nOperazioni disponibili: -c per compressione\t-d per decompressione\n"<<endl;
                                exit(-1); }

    if ( strcmp(argv[1],"-c") == 0 ){
                cout<<"\n\ncodifica in corso del file "<<argv[2]<<"...\n"<<endl;
                Huffman::get_instance().Encode(argv[2],argv[3]);
            }
    else if ( strcmp(argv[1], "-d") == 0) {
                cout<<"\n\ndecodifica in corso del file "<<argv[2]<<"...\n"<<endl;
                Huffman::get_instance().Decode(argv[2],argv[3]);
            }
    else {
            cout<<"\n\nERRORE! IL PRIMO ARGOMENTO DEVE ESSERE:\n-c per la compressione\t-d per la decompressione\n"<<endl;
            exit(-1);
            }


 return 0;

}
