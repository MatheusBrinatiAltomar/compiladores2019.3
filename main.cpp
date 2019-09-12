#include <iostream>
#include "tabelaSimbolos.h"
#include <string.h>

using namespace std;

int main(){
    tabelaSimbolos * t = new tabelaSimbolos();
    t->insere((char *)"pinto");
    t->insere((char *)"Abacato");
    t->insere((char *)"Jorge");
    t->insere((char *)"pau");
    t->insere((char *)"desespero");
    t->insere((char *)"penis");
    t->insere((char *)"duas");
    t->insere((char *)"vinicius");
    t->insere((char *)"barba");
    t->insere((char *)"antes");
    t->insere((char *)"caridoso");
    t->insere((char *)"jogar");
    return 0;
}