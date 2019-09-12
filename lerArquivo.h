#ifndef  LERARQUIVO_H
#define  LERARQUIVO_H

//método para construir a extrutura de leitura do arquivo a ser compilado
//recebe como parâmetro o nome do arquivo
//retorna 1 caso o arquivo exista e foi aberto corretamente e 0 caso contrário
int construtor (unsigned char nomeArquivo[]);

//método para liberar a memória utilizada pela leitura de arquivos após sua utilização
void destrutor ();

//método para retornar o próximo caractere a ser processado
//retorna \0 em caso de EOF
unsigned char pegarCaractere();

#endif /*LERARQUIVO_H*/