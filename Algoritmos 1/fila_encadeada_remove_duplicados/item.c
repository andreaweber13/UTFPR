#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define MAXTAM 20

struct item{
    char chave;
};
struct fila{
    Item item[MAXTAM];
    int primeiro;
    int ultimo;
    int tam;
};
Fila *cria_fila(){
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tam = 0;
    return f;
}
int verifica_fila_vazia(Fila *f){
    return f->tam == 0;
}
int verifica_fila_cheia(Fila *f){
    return f->tam == MAXTAM;
}
void enfileira(Fila *f, char chave){
    if(verifica_fila_cheia(f)){
        printf("Erro! fila cheia\n");
        return;
    }
    Item novoitem;
    novoitem.chave = chave;
    f->item[f->ultimo] = novoitem;
    f->ultimo = (f->ultimo + 1) % MAXTAM;
    f->tam++;
}
void imprime(Fila *f){
    int t;
    int i = f->primeiro;
    for(t=0;t<f->tam; t++){
        printf("Chave: %c\n",f->item[i].chave);
        i = (i+1)%MAXTAM;
    }
}
void desenfileira(Fila *f){
    if(verifica_fila_vazia(f)){
        printf("Erro! fila vazia\n");
    }
    f->primeiro = (f->primeiro + 1) % MAXTAM;
    f->tam--;
}
char espia(Fila*f){
    return f->item[f->primeiro].chave;
}
int buscaChaveFila(Fila *f, char chave) {
     int i = f->primeiro;
     for (int t = 0; t < f->tamanho; t++) {
         if (chave == f->item[i].chave) {
             return 1;
         }
         i = (i+1) % MAXTAM;
     }
     return 0;
}

Fila *removeDuplicados(Fila *f) {
     Fila *f2 = criaFilaVazia();
     int i = f->primeiro;
     for (int t = 0; t < f->tamanho; t++) {
         if (buscaChaveFila(f2, f->item[i].chave) == 0) {//se nao existe
na fila2, insere
             enfileira(f2, f->item[i].chave);
         }
         i = (i+1) % MAXTAM;
     }
     return f2;
}