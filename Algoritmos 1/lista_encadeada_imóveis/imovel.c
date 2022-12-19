#include <stdio.h>
#include <stdlib.h>
#include "imovel.h"
#include <string.h>

struct imovel{
    int chave;
    char descricao[31];
    char endereco[31];
    float valor;
};

struct lista{
    Imovel imovel[MAX];
    int qtde;
    int ultimo;
};

Lista *criaListaVazia(){
    Lista *l = malloc(sizeof(Lista));
    l->ultimo = -1;
    return l;
}
int verificaListaCheia(Lista *l){
    return l->ultimo == MAX - 1;
}
void adicionaImovelFimLista(Lista *l, int chave, char descricao[], char endereco[], float valor){
    if(verificaListaCheia(l)){
        printf("Erro! Lista cheia.\n");
        return;
    }
    Imovel novoImovel;
    novoImovel.chave = chave;
    strcpy(novoImovel.descricao, descricao);
    strcpy(novoImovel.endereco, endereco);
    novoImovel.valor = valor;
    l->ultimo++;
    l->imovel[l->ultimo] = novoImovel;
    printf("Adicionado com sucesso! \n");
}
void imprimeLista(Lista*l){
    int tam = l->ultimo + 1;
    int i;
    for (i = 0; i < tam; i++) {
        printf("Chave: %d\n", l->imovel[i].chave);
        printf("Descricao: %s\n",l->imovel[i].descricao);
        printf("Endereco: %s\n",l->imovel[i].endereco);
        printf("Valor: %f\n",l->imovel[i].valor);
    }
}
int buscaImovelPorChave(Lista *l, int chave) {
    int i = 0;
    while((i <= l->ultimo) && (l->imovel[i].chave != chave)){
        i++;
    }
    if(i <= l->ultimo){
        return i;
    }
    else{
        return -1;
    }
}
void removeImovel (Lista *l, int chave){
    int posicao, i, tam;
    posicao = buscaImovelPorChave(l, chave);
    if(posicao == -1){
        printf("Erro! Lista vazia ou imovel inexistente. \n");
        return;
    }
    tam = l->ultimo + 1;
    for(i = posicao; i < tam-1; i++){
        l->imovel[i] = l->imovel[i+1];
    }
    l->ultimo--;
}
int verificaListaVazia(Lista *l){
    return l->ultimo == -1;
}
void liberaLista(Lista *l){
    free(l);
}