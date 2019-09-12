#ifndef  TABELASIMBOLOS_H
#define  TABELASIMBOLOS_H

#define TAM_TABELA 50
#define TAM_STRING 30
#define TAM_CRESCIMENTO 30

using namespace std;

//estrutura utilizada na hash para que se salve o proximo elemento da lista e a posicao no vetor de char na qual a string atual esta salva
typedef struct entrada{
    int pos;
    entrada * prox;
} entrada;

class tabelaSimbolos{
    private:
        int posString;
        int tamStringAtual;
        char * strings;
        entrada * tabelaHash[TAM_TABELA];
        int funcaoHash(char * str);
        int contemString(int pos, char * str);
    public:
        tabelaSimbolos();
        virtual ~tabelaSimbolos();
        int contem(char * strConsulta);
        int insere(char * strInserir);
};

#endif /*TABELASIMBOLOS_H*/