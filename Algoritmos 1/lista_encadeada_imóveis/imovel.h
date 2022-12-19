#ifndef IMOVEL_H_INCLUDED
#define IMOVEL_H_INCLUDED
#define MAX 100

typedef struct imovel Imovel;
typedef struct lista Lista;

Lista *criaListaVazia();
int verificaListaCheia(Lista *l);
void adicionaImovelFimLista(Lista *l, int chave, char descricao[], char endereco[], float valor[]);
void imprimeLista(Lista *l);
int buscaImovelPorChave(Lista *l, int chave);
void removeImovel(Lista *l, int chave);
int verificaListaVazia(Lista *l);
void liberaLista(Lista *l);

#endif // IMOVEL_H_INCLUDED
