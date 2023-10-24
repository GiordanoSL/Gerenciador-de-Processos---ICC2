#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define MAX_DESCR 50 //maximo de caracteres de uma descricao
#define TAM_MAX 100 //numero maximo de processos de uma lista
#define ERRO -1412412 //Erro que representado por um inteiro

//struct que guarda um horario no formato horas:minutos:segundos
typedef struct horario_{
    int hh; //hora
    int mm; //minuto
    int ss; //segundo
}horario;

//struct que guarda um process com prioridade, horario de chegada e descricao
typedef struct processo_{
    int prior; //prioridade do processo
    horario chegada; //horario de chegada
    char descricao[MAX_DESCR];// descricao do processo
}processo;

int prior_tempo = -1, //indica se está ordenado por prioridade(0) ou horario de chegada(1) ou se está desordenado -após inserção(-1)
    tamanho = 0; //numero de processos na lista
processo lista[TAM_MAX];//lista de processos

//faz a leitura e retorna um horario
horario ler_horario(){
    horario t; // horario que será lido
    char aux; // variável auxiliar para ler os ':'

    //lendo horas, minutos e segundos:
    scanf(" %d %c", &t.hh, &aux);
    scanf(" %d %c", &t.mm, &aux);
    scanf(" %d", &t.ss);

    return t;    
}

// troca a e b de "lugar"
void swap(processo * a, processo *b){
    processo aux = *a;
    *a = *b;
    *b = aux;
}

void quick_sort_prior(processo * lista, int inicio, int fim){
    if(fim <= inicio)
        return;

    int pivo = lista[(inicio + fim)/2].prior, i, j;

    // movendo o pivo para o final da lista.
    swap(&lista[(inicio + fim)/2], &lista[fim]);

    // particionamento do array (metodo de Lomuto).
    for (i = inicio, j = inicio; i < fim; i++){
        if(lista[i].prior < pivo)
            swap(&lista[i], &lista[j++]);
    }
    swap(&lista[j], &lista[fim]); // j = posicao correta do elemento pivo.

    //recursão
    quick_sort_prior(lista, inicio, j - 1);
    quick_sort_prior(lista, j + 1, fim);
    
}

int busca_elementos_prioridade(int prioridade){
        for(int i = tamanho-1; i>=0; i--){
            if(lista[i].prior == prioridade){
                return i;
            }
        }
        return ERRO;
}

int busca_elementos_horario(horario time){
        for(int i = tamanho-1; i>=0; i--){
            if((lista[i].chegada.hh == time.hh) && (lista[i].chegada.mm == time.mm) && (lista[i].chegada.ss == time.ss)){
                return i;
            }
        }
        return ERRO;
}

int lista_busca_binária_prioridade(int x) {
    int j, k; //J é o valor que tem na primeira posicao do meu vetor, k é o valor que tem na ultima posicao do meu vetor
    int inicio_temp = 0; //Limite Inferior da busca binaria
    int fim_temp = tamanho-1; //Limite Superior da busca binaria
    while(inicio_temp<=fim_temp){
        k = (inicio_temp+fim_temp) / 2; //k representa o meio da lista
        j = lista[k].prior; //j é quem está nessa posicao(meio da lista);
        if(j==x){ //Aqui é o proprio x
            return (k);
        }else if(j<x){ //Já que x é maior, ele está desse meio para frente
            inicio_temp=k+1;
        }else{ 
            fim_temp=k; ///Se x for menor, ele está desse meio para tras
        }
    }
    return(ERRO);
} 

int lista_busca_binária_tempo(horario x) {
    int k;
    horario j;
    int inicio_temp = tamanho-1; //Limite Inferior da busca binaria
    int fim_temp = 0; //Limite Superior da busca binaria
    while(inicio_temp>=fim_temp){
        k = (inicio_temp+fim_temp) / 2; //k representa o meio da lista
        j = lista[k].chegada; //j é quem está nessa posicao(meio da lista);
        if((j.hh==x.hh) && (j.mm==x.mm) && (j.ss==x.ss)){ //Aqui é o proprio x
            return (k);
        }else if(j.hh < x.hh){ //Já que x é maior, ele está desse meio para tras
            inicio_temp=k;
        }else if(j.hh == x.hh){
            if(j.mm < x.mm){
                inicio_temp=k;
            }else if(j.mm == x.mm){
                if(j.ss < x.ss){
                inicio_temp=k;
                }
            }
        }else{ 
            fim_temp=k; ///Se x for menor, ele está desse meio para frente
        }
    }
    return(ERRO);
}


void quick_sort_horario(processo * lista, int inicio, int fim){
    if(fim <= inicio)
        return;

    horario pivo = lista[(inicio + fim)/2].chegada;
    int i, j;

    // movendo o pivo para o final da lista.
    swap(&lista[(inicio + fim)/2], &lista[fim]);

    // particionamento do array (metodo de Lomuto).
    for (i = inicio, j = inicio; i < fim; i++){
        
        if(lista[i].chegada.hh > pivo.hh){ //Comparação entre as horas
            swap(&lista[i], &lista[j++]);
        } else if(lista[i].chegada.hh == pivo.hh){ //Se as horas forem iguais, compara entre os minutos
            if(lista[i].chegada.mm > pivo.mm){
                swap(&lista[i], &lista[j++]);
            }
            else if(lista[i].chegada.mm == pivo.mm){ //Se horas e minutos forem iguais, compara entre os segundos
                if(lista[i].chegada.ss > pivo.ss){
                    swap(&lista[i], &lista[j++]);
                }
            }
        }

    }
    swap(&lista[j], &lista[fim]); // j = posicao correta do elemento pivo.

    //recursão
    quick_sort_horario(lista, inicio, j - 1);
    quick_sort_horario(lista, j + 1, fim);
    
}

//adiciona um processo no final da lista
void add(){
    if(tamanho >= TAM_MAX)
        return;// lista está cheia

    processo novo_p; //processo que será adicionado no final da lista

    scanf(" %d", &novo_p.prior);// lendo a prioridade
    novo_p.chegada = ler_horario();// lendo o horario de chegada
    scanf(" %s", novo_p.descricao);// lendo a descricao

    //adicionando o elemento na lista
    lista[tamanho] = novo_p;
    tamanho ++;
    prior_tempo = -1;
}

//executa o processo de maior prioridade ou o de menor tempo 
void exec(){
    if(tamanho == 0)
        return; //lista está vazia

    char aux[3]; //string para leitura do comando (-p ou -t) que distingue entre maior prioridade ou menor tempo
    scanf(" %s", aux);

    if(strcmp(aux, "-p") == 0){ //Executa o de maior prioridade
        if(prior_tempo != 0){ //Se nao esta ordenado por prioridade
            quick_sort_prior(lista, 0, tamanho - 1); //Ordena por prioridade e faz prior_tempo = 0
            prior_tempo = 0;
        } 
    } else if(strcmp(aux, "-t") == 0) //Executa o de menor tempo
        if(prior_tempo != 1){ //Se nao esta ordenado por tempo
            quick_sort_horario(lista, 0, tamanho - 1); //Ordena por horario de chegada e faz prior_tempo = 1
            prior_tempo = 1;
        }
    
    tamanho --;//Diminui o tamanho do vetor, excluindo o último processo da lista
}

//altera um processo quando recebe seu horario de chegada ou sua prioridade.
void change(){
    char comando[3]; //le se a alteracao ocorrerá por tempo ou prioridade
    scanf(" %s", comando);
    if(strcmp(comando, "-t") == 0){
        horario anterior; //horario do processo anterior
        horario novo; //horario do processo novo
        int posicao; //posicao do vetor que ele está
        anterior = ler_horario();
        getchar(); //para nao pegar o caracter '|'
        novo = ler_horario();
        if(prior_tempo == 1){ //Se a lista já está ordenada realizo busca binária
            posicao = lista_busca_binária_tempo(anterior);
        }else{ //Se não faço uma busca convencional
            posicao = busca_elementos_horario(anterior);
        }
        lista[posicao].chegada = novo;
        prior_tempo = -1; //indica que a partir de agora a lista não está ordenada
    }
    if(strcmp(comando, "-p") == 0){
        int prioridade_anterior, prioridade_nova, posicao; //Prioridade anterior, Prioridade nova, Posicao do vetor que ele está
        scanf("%d", &prioridade_anterior);
        getchar();  //para nao pegar o caracter '|'
        scanf("%d", &prioridade_nova);
        if(prior_tempo == 0){ //Se a lista já está ordenada realizo busca binária
            posicao = lista_busca_binária_prioridade(prioridade_anterior);
        }else{ //Se não faço uma busca convencional
            posicao = busca_elementos_prioridade(prioridade_anterior);
        }
        lista[posicao].prior = prioridade_nova;
        prior_tempo = -1;  //indica que a partir de agora a lista não está ordenada
    }
}

void print(){
    printf("Print!!!\n");
}
void next(){
    printf("Next!!!\n");
}

void ler_comando(){
    char comando[7];
    scanf(" %s", comando); //leitura do comando

    if(strcmp(comando, "add") == 0)
        add(); //chama add

    else if(strcmp(comando, "exec") == 0){
        exec(); //chama exec
    }

    else if(strcmp(comando, "change") == 0)
        change(); //chama change

    else if(strcmp(comando, "print") == 0)
        print(); //chama print

    else if(strcmp(comando, "next") == 0)
        next(); //chama next

    else if(strcmp(comando, "quit") == 0)
        return;
    
    ler_comando(); // recursão - leitura de comandos continua até comando quit
}

int main(void){
    ler_comando();   
    return 0;
}
