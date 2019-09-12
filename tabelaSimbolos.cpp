#include "tabelaSimbolos.h"
#include <iostream>
#include <string.h>

tabelaSimbolos::tabelaSimbolos(){
    strings = (unsigned char *) malloc(TAM_STRING);
    for(int i=0;i<TAM_TABELA;i++){
        tabelaHash[i]=NULL;
    }
    posString=0;
    tamStringAtual=TAM_STRING;
}

tabelaSimbolos::~tabelaSimbolos(){
    entrada * ent, * aux;
    for(int i=0;i<TAM_TABELA;i++){
        ent = tabelaHash[i];
        while(ent!=NULL){
            aux=ent;
            ent=ent->prox;
            free(aux);
        }
    }
    free(strings);
}

int tabelaSimbolos::contemString(int pos, unsigned char * str){
    int i;
    for(i=0;strings[i+pos]!='\0' && str[i]!='\0';i++){
        if(strings[i+pos]!=str[i]){
            return false;
        }
    }
    if(strings[i+pos]=='\0' && str[i]=='\0'){
        return true;
    }else{
        return false;
    }
}

int tabelaSimbolos::funcaoHash(unsigned char * str){
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return (int)(hash % TAM_TABELA);
}

int tabelaSimbolos::contem(unsigned char * strConsulta){
    int hash = funcaoHash(strConsulta);
    entrada * atual = tabelaHash[hash];
    while(atual!=NULL){
        if(tabelaSimbolos::contemString(atual->pos,strConsulta)){
            return true;
        }
        atual=atual->prox;
    }
    return false;
}

int tabelaSimbolos::insere(unsigned char * strInserir){
    if(!contem(strInserir)){
        int hash = funcaoHash(strInserir);
        int i=-1;
        entrada * inserir = (entrada *) malloc(sizeof(entrada));
        inserir->pos = posString;
        do{
            i++;
            if(posString < TAM_STRING){
                strings[posString]=strInserir[i];
            }else{
                tamStringAtual=tamStringAtual+TAM_CRESCIMENTO;
                strings = (unsigned char *) realloc(strings,tamStringAtual);
                strings[posString]=strInserir[i];
            }
            posString++;
        }while(strInserir[i]!='\0');
        inserir->prox = tabelaHash[hash];
        tabelaHash[hash]=inserir;
    }
}