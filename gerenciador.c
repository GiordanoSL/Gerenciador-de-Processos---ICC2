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

int prior_tempo, //indica se está ordenado por prioridade(0) ou horario de chegada(1) ou se está desordenado -após inserção(-1)
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

//adiciona um item no final da lista
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

void exec(){
    printf("Exec!!!\n");
}
void change(){
    printf("Change!!!\n");
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
}
