#include "lerArquivo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO_BUFFER 512
#define TAMANHO_MAX_NOME_ARQUIVO 100

FILE * arquivo;
char * buffer;
int posBuffer;

int construtor (char nomeArquivo[]){
        corrigeNomeArquivo(nomeArquivo);
        arquivo = fopen(nomeArquivo,"r");
        if(arquivo!=NULL){
                buffer = (char *) malloc(TAMANHO_BUFFER+1);
                posBuffer=TAMANHO_BUFFER;
                return 1;
        }
        return 0;
}

void destrutor (){
        free(buffer);
        fclose(arquivo);
}

//método interno para corrigir o nome do arquivo caso o usuario passe ele sem extensão
//recebe como parâmetro o nome do arquivo passado pelo usuário
void corrigeNomeArquivo(char nomeArquivo[]){
        int contemPonto = 0;
        for(int i=0;nomeArquivo[i]!='\0';i++){
                if(nomeArquivo[i]=='.'){
                        contemPonto = 1;
                        break;
                }
        }
        if(!contemPonto){
                strcat(nomeArquivo, ".cmm");
        }
}

//metodo interno para encher o buffer toda vez que ele for consumido por inteiro
//retorna a qtd de byts lidos;
int preencheBuffer(){
        int qtdLido = fread(buffer,1,TAMANHO_BUFFER,arquivo);
        buffer[qtdLido]='\0';
        posBuffer=0;
        return qtdLido;
}

char pegarCaractere(){
        if(buffer[posBuffer]!='\0'){
                posBuffer++;
                return buffer[posBuffer-1];
        }else{
                if(preencheBuffer()>0){
                        posBuffer++;
                        return buffer[posBuffer-1];
                }else{
                        return '\0';
                }
        }
}

//main feita para testes... so nao foi apagada pq provavelmente vai ser reaproveitada na main verdadeira
/*
int main(int argc, char *argv[]){
        char nomeArquivo[TAMANHO_MAX_NOME_ARQUIVO+3], c;
        if(argc>1){
                strcpy(nomeArquivo,argv[1]);
        }else{
                scanf("%s",nomeArquivo);
        }
        if(construtor(nomeArquivo)){
                while((c=pegarCaractere())!='\0'){
                        printf("%c",c);
                }
                destrutor();
        }else{
                printf("\nArquivo não encontrado\n");
        }
}
*/