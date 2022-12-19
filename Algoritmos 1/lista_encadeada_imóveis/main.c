#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imovel.h"

int main (void)
{
    Lista *l;
    int vazia, cheia, chave, i;
    char descricao[50], endereco[50];
    float valor;
    l = criaListaVazia();
    vazia = verificaListaVazia(l);
    printf("Lista vazia? %d\n", vazia);
    cheia = verificaListaCheia(l);
    printf("Lista cheia? %d\n", cheia);
    printf("Insira o codigo: \n");
    scanf("%d",&chave);
    fflush(stdin);
    printf("Insira a descricao: (ex: casa, apartamento, kitnet)\n");
    scanf("%s",descricao);
    fflush(stdin);
    printf("Insira o endereco: \n");
    scanf("%s",endereco);
    fflush(stdin);
    printf("Insira o valor: \n");
    scanf("%f",&valor);
    adicionaImovelFimLista(l, chave, descricao, endereco, valor);
    
    imprimeLista(l);
    liberaLista(l);
    return(0);
}
