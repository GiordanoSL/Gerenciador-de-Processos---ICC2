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

void quick_sort(processo * lista, int inicio, int fim){
    if(fim <= inicio)
        return;

    int pivo = lista[(inicio + fim)/2], i, j;

    // movendo o pivo para o final da lista.
    swap(&lista[(inicio + fim)/2], &lista[fim]);

    // particionamento do array (metodo de Lomuto).
    for (i = inicio, j = inicio; i < fim; i++){
        if(lista[i] < pivo)
            swap(&lista[i], &lista[j++]);
    }
    swap(&lista[j], &lista[fim]); // j = posicao correta do elemento pivo.

    //recursão
    quick_sort(lista, inicio, j - 1);
    quick_sort(lista, j + 1, fim);
    
}

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
