#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCR 50
#define TAM_MAX 100

typedef struct{
    int hh;
    int mm;
    int ss;
}horario;

typedef struct{
    int prior;
    horario chegada;
    char descricao[MAX_DESCR]
}processo;

int prior_tempo, indice_atual = 0;
processo lista[TAM_MAX];

void ler_comando(){
    char comando[10] = {0};
    scanf(" %s", comando);
}

int main(void){

}
