#ifndef TABELASIMBOLOS_H
#define TABELASIMBOLOS_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <list>
#define TAMANHOTABELA 3

using namespace std;

class info
{
    public:
        void setString(string str){i = str;};
        string getString(){return i;};
    private:
        string i;
};

class entrada
{
    private:
        int chave;
        info *i;
        //entrada *proximo;
    public:
        void construtor(int c, info *d)
        {
            chave = c;
            i = d;
            //proximo = NULL;
        };
        void setChave(int x){chave = x;};
        int getChave(){return chave;};
        void setInfo(string str){i->setString(str);};
        string getInfo(){return i->getString();};
        info *getI(){return i;};
        //void setProx(entrada *ent){proximo = ent;};
};

class tabelaSimbolos
{
    public:
        vector< vector<entrada> > tabelaHash;
        vector<string> vetorInfo;

        tabelaSimbolos();
        virtual ~tabelaSimbolos();
        int hashFunction(entrada x);
        void insercao(entrada x);
        void mostraTabela();
};

#endif // TABELASIMBOLOS_H
