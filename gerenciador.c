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

int prior_tempo, //indica se está ordenado por prioridade(0) ou horario de chegada(1)
    tamanho = 0; //numero de processos na lista
processo lista[TAM_MAX];//lista de processos

/* funções do Victor e do Giordano
-ler_comando();
-ordenar();
-add();
*/

/* funções do Maicon e do Karl
-exec();
-change();
*/

/* funções do Paulo e do Catuzzi
-print();
-next();
*/

int main(void){

}
