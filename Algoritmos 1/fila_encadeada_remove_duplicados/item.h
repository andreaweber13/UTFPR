#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#define MAXTAM 20
typedef struct item Item;
typedef struct fila Fila;

Fila *cria_fila();
int verifica_fila_vazia(Fila *f);
int verifica_fila_cheia(Fila *f);
void enfileira(Fila *f, char chave);
void imprime(Fila *f);
void desenfileira(Fila *f);
char espia(Fila*f);
Fila *removeDuplicados(Fila *f);
int buscaChaveFila(Fila *f, char chave);
#endif 