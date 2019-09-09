#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO_BUFFER 512

FILE * arquivo;
char * buffer;
int posBuffer;

int construtor (char nomeArquivo[]){
        arquivo = fopen(nomeArquivo,"r");//tem q tratar o nome do arquivo
        if(arquivo!=NULL){
                buffer = (char *) malloc(TAMANHO_BUFFER+1);
                buffer[0]='\0';
                posBuffer=TAMANHO_BUFFER;
                return 1;
        }
        return 0;
}

void destrutor (){
        free(buffer);
        fclose(arquivo);
}

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

void ungetCaractere(){
        posBuffer--;
}

int main(){
        char nome[50];
        char car;
        strcpy(nome,"teste.txt");
        if(construtor(nome)){
                while((car=pegarCaractere())!='\0'){
                        printf("%c",car);
                }
                destrutor();
        }else{
                printf("\nArquivo não encontrado\n");
        }
}