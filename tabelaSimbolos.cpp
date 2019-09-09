#include "tabelaSimbolos.h"

tabelaSimbolos::tabelaSimbolos()
{
    tabelaHash.resize(TAMANHOTABELA);
    /*entrada ent;
    ent.construtor(0, NULL);
    vector<entrada> k;
    k.push_back(ent);
    for(int i = 0; i < TAMANHOTABELA; i++)
    {
        cout << "Deu";
        tabelaHash.push_back(k);
    }*/

}

tabelaSimbolos::~tabelaSimbolos()
{
    //dtor
}

int tabelaSimbolos::hashFunction(entrada x)
{
    return (x.getChave() % TAMANHOTABELA);
}

void tabelaSimbolos::insercao(entrada x)
{
    int index = hashFunction(x);
    cout << "inserindo " << x.getChave() << "na chave " << index << endl;
    //if (tabelaHash[index][0].getChave()==0)
    //{
       // cout << "if";
        //tabelaHash[index][0].construtor(x.getChave(), x.getI());
    //}
    //else
    //{
      //  cout << "else";
        tabelaHash[index].push_back(x);
        cout << "tabela: ";
        for(int i=0;i<tabelaHash.size();i++){
            for(int j=0;j<tabelaHash[i].size();j++){
                cout << i << "-> " <<tabelaHash[i][j].getChave() << endl;
            }
        }
    //}

}

void tabelaSimbolos::mostraTabela()
{
    for (int i = 0; i < TAMANHOTABELA; i++)
    {
        //cout << tabelaHash->at(i).chave;
        //for (auto x : tabelaHash->at(i))
        //{
        //    cout << " --> " << tabelaHash->at(i).chave;
        //}
        cout << endl;
  }
}
