#ifndef LISTA1_H_INCLUDED
#define LISTA1_H_INCLUDED

typedef struct item Item;
typedef struct lista Lista;
typedef struct celula Celula;

Lista *cria_lista();
void insere_inicio(Lista *l, int chave);
void insere_fim(Lista *l, int chave);
void insere_meio(Lista *l, int chave, int x);
void imprime(Lista *l);
Celula *busca_chave(Lista *l, int chave);
Celula *transfere(Lista *l1, Lista *l2);
void remove_item(Lista *l, int x);
int verifica_vazia(Lista *l);
void concatena(Lista *l1, Lista *l2);
void libera(Lista *l);

#endif 