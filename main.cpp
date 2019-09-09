#include <iostream>
#include <stdlib.h>
#include <string>
#include "tabelaSimbolos.h"

using namespace std;

int main()
{
    cout << "a" << endl;
    entrada ent[5];
    string i[5] = {"teste0", "teste1", "teste2", "teste3", "teste4"};
    info inf[5];
    for (int j = 0; j < 5; j++)
        inf[j].setString(i[j]);
    for (int j = 0; j < 5; j++)
    {
        ent[j].construtor(j+1, &inf[j]);
        //ent[j].proximo = NULL;
    //    cout << ent[j].proximo << endl;
    }
    //cout << endl;
    tabelaSimbolos tab = tabelaSimbolos();
    for (int j = 0; j < 5; j++)
        tab.insercao(ent[j]);
    cout << "passou" << endl;

    //cout << endl;
    //cout << tab.tabelaHash->size() << endl << endl;
    for (int x = 0; x < tab.tabelaHash.size(); x++)
    {
        for(int i=0;i<tab.tabelaHash[x].size();i++){
            cout << tab.tabelaHash[x][i].getChave() << "\t";
        }
         //cout << tab.tabelaHash[x][0].getInfo().i << "\t" << endl;
         //cout << tab.tabelaHash[x][0].at(0).proximo << endl;
    }

    return 0;
}
