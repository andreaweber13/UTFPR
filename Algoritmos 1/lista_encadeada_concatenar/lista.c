#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct item{
    int chave;
};
struct celula{
    Item item;
    Celula *prox;
};
struct lista{
    Celula *primeira;
};
Lista *cria_lista(){
    Lista *l = malloc(sizeof(Lista));
    l->primeira = NULL;
    return l;
}
int verifica_vazia(Lista *l){
    return l->primeira == NULL;
}
void insere_inicio(Lista *l, int chave){
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = l->primeira;
    l->primeira = nova;
}
void insere_fim(Lista *l, int chave){
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;
    if(verifica_vazia(l)){
        l->primeira = nova;
    }
    else{
        Celula *ultima;
        ultima = l->primeira;
        while(ultima->prox != NULL){
            ultima = ultima->prox;
        }
        ultima->prox = nova;
    }
}
void insere_meio(Lista *l, int chave, int x){
    Celula *aux = busca_chave(l,x);
    if(aux != NULL){
        Item novo;
        novo.chave = chave;
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        nova->prox = aux->prox;
        aux->prox = nova;
    }
    else{
        printf("O item informado nao existe!");
    }
}
void imprime(Lista *l){
    Celula *aux;
    for(aux = l->primeira; aux != NULL; aux = aux->prox){
        printf("Chave: %d\n", aux->item.chave);
    }
}
Celula *busca_chave(Lista *l, int chave){
    Celula *aux = l->primeira;
    while(aux != NULL && aux->item.chave != chave){
        aux = aux->prox;
    }
    return aux;
}
void remove_item(Lista *l, int x){
    Celula *aux = l->primeira;
    Celula *anterior;
    while(aux != NULL && aux->item.chave != x){
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Erro! Item nao encontrado.\n");
        return;
    }
    if(aux == l->primeira){
        l->primeira = aux->prox;
    }
    else{
        anterior->prox = aux->prox;
    }
    free(aux);
}
void concatena(Lista *l1, Lista*l2){
    if(verifica_vazia(l1) || verifica_vazia(l2)){
        printf("Erro! Uma das listas esta vazia.\n");
        return;
    }
    Celula *aux = l2->primeira;
    while(aux != NULL){
        insere_fim(l1,aux->item.chave);
        aux = aux->prox;
    }
}

Celula *transfere(Lista *l1, Lista *l2){
     Celula *ant = NULL;
     Celula *auxL2;
     Celula *auxL1 = l1->primeira;
     int x;
     while(auxL1 != NULL){
         auxL2 = l2->primeira;
         x = auxL1->item.chave;
         if ((auxL2 == NULL || auxL2->item.chave > x)) {
             insere_inicio(l2, x);
         }
         else {
             ant == l2->primeira;
             while (auxL2 != NULL && auxL2->item.chave <= x){
                 ant = auxL2;
                 auxL2 = auxL2->prox;
             }

             if (auxL2 == NULL) {
                 insere_fim(l2, x);
             } else {
                 insere_meio(l2, x, ant->item.chave);
             }
         }
         auxL1 = auxL1->prox;
     }
     return l2;
}

void libera(Lista *l){
    Celula *aux = l->primeira;
    Celula *liberar;
    while(aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(l);
}