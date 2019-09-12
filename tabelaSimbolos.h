#ifndef  TABELASIMBOLOS_H
#define  TABELASIMBOLOS_H

#define TAM_TABELA 500
#define TAM_STRING 1000
#define TAM_CRESCIMENTO 500

using namespace std;

//estrutura utilizada na hash para que se salve o proximo elemento da lista e a posicao no vetor de unsigned char na qual a string atual esta salva
typedef struct entrada{
    int pos;
    entrada * prox;
} entrada;

class tabelaSimbolos{
    private:
        int posString;
        int tamStringAtual;
        unsigned char * strings;
        entrada * tabelaHash[TAM_TABELA];
        int funcaoHash(unsigned char * str);
        int contemString(int pos, unsigned char * str);
    public:
        tabelaSimbolos();
        virtual ~tabelaSimbolos();
        int contem(unsigned char * strConsulta);
        int insere(unsigned char * strInserir);
};

#endif /*TABELASIMBOLOS_H*/