#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;
typedef struct FilaE FilaE;
typedef struct GrafoMA GrafoMA;

struct GrafoMA{
   int V, A;
   int **mat;
};

static int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) calloc(n, sizeof(int));

    return mat;
}


static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}


GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}


int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
}


void inserir_aresta(GrafoMA* G, int v1, int v2){
    if (!aresta_existe(G, v1, v2)){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA* G, int v1, int v2){
    if (aresta_existe(G, v1, v2)){
        G->mat[v2][v1] = G->mat[v1][v2] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA* G){
    int i, j;

    for (i = 1; i < G->V; i++)
        for (j = 0; j < i; j++)
            if (G->mat[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}


void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}
struct Cell{
    int key;
    Cell *next;
};

struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->key = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = -INT_MAX;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->key;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->key);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

struct Lista{
    Cell *head;
};

struct GrafoLA{
   int V;
   int A;
   int *cor;
   int *pai;
   int *d;
   int *f;
   int *nafila;
   int *key;
   Lista **adj;
};
/***************************************************************/
// Lista encadeada

Lista* criar_lista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    l->head = NULL;

    return l;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->head == NULL);
}


int procurar(int key, Lista *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while ((aux != NULL) && (key < aux->key))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->key))
        return 1;
    else
        return 0;
}


void inserir_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;
    Cell* c;

    if (lista_vazia(l)){
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key);
    }else{
        c = criar_celula(key);

        if (l->head->key >= key){
           c->next = l->head;


           l->head = c;
        }else{
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->key < key)){
                auxA = auxP;
                auxP = auxP->next;
            }

            auxA->next = c;
            c->next = auxP;
        }
    }
}


int remover_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;

    if (!lista_vazia(l)){
        auxA = l->head;

        if(auxA->key == key)
            l->head = l->head->next;
        else{
            auxP = auxA;

            while((auxA != NULL) && (key < auxA->key)){
                auxP = auxA;
                auxA = auxA->next;
            }

            if (auxA->key == key)
                auxP->next = auxA->next;
            else
                auxA = NULL;
        }

        if (auxA != NULL)
            free(auxA);

        return 1;
    }

        return 0;
}


void imprimir(Lista *l){
    Cell *aux;

    if (!lista_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d\n", aux->key);

            aux = aux->next;
        }
    }
}


int liberar_lista(Lista *l){
    Cell *aux;

    if ((l != NULL) && !lista_vazia(l)){

        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


/***************************************************************/
// Grafo

static Lista** iniciar_LA(int n){
    int i;
    Lista **adj = (Lista**) malloc(n * sizeof(Lista*));

    for (i = 0; i < n; i++)
        adj[i] = criar_lista();

    return adj;
}


GrafoLA* iniciar_grafoLA(int v){
    GrafoLA* G = (GrafoLA*) malloc(sizeof(GrafoLA));

    G->V = v;
    G->A = 0;
    G->cor = (int*)malloc(sizeof(int)*v);
    G->pai = (int*)malloc(sizeof(int)*v);
    G->d = (int*)malloc(sizeof(int)*v);
    G->f = (int*)malloc(sizeof(int)*v);
    G->adj = iniciar_LA(G->V);
    G->nafila = (int*)malloc(sizeof(int)*v);
    return G;
}


int aresta_existeLA(GrafoLA* G, int v1, int v2){
    if ((G!= NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);

    return 0;
}


void inserir_arestaLA(GrafoLA* G, int v1, int v2){
    if (!aresta_existeLA(G, v1, v2)){
        inserir_na_lista(v2, G->adj[v1]);
        inserir_na_lista(v1, G->adj[v2]);
        G->A++;
    }
}


void remover_arestaLA(GrafoLA* G, int v1, int v2){
    if (aresta_existeLA(G, v1, v2)){
        remover_na_lista(v2, G->adj[v1]);
        remover_na_lista(v1, G->adj[v2]);
        G->A--;

    }
}


void imprimir_arestasLA(GrafoLA* G){
    int i;
    Cell *aux;

    if (G != NULL)
        for (i = 0; i < G->V; i++){
            aux = G->adj[i]->head;

            while (aux != NULL){
                printf("(%d, %d)\n", i, aux->key);

                aux = aux->next;
            }

        }
}


void liberarGLA(GrafoLA* G){
    int i;

    if (G != NULL){
        for (i = 0; i < G->V; i++)
            liberar_lista(G->adj[i]);

        free(G);
    }
}
void visitar_vertice(GrafoLA *G, int u, int *tempo){
    int v;
    Cell *aux = G->adj[u]->head;
    G->cor[u] = 1;
    *tempo += *tempo;
    G->d[u] = *tempo;
    while(aux != NULL){
        v = aux->key;
        if(G->cor[v] == 0){
            G->pai[v] = u;
            visitar_vertice(G,v,tempo);
        }
        aux = aux->next;
    }
    G->cor[u] = 2;
    *tempo += *tempo;
    G->f[u] = *tempo;
}
void busca_profundidade(GrafoLA *G){
    int u,v, tempo=0;
    for(u=0;u<G->V;u++){
        G->cor[u] = 0;
        G->pai[u] = -1;
    }
    for(u=0;u<G->V;u++){
        if(G->cor[u] == 0){
            visitar_vertice(G,u,&tempo);
        }
    }
    printf("v d f p\n");
    for(v=0;v<G->V;v++){
        printf("%d %d %d ",v,G->d[v],G->f[v]);
        if(G->pai[v] >= 0){
            printf("%d\n",G->pai[v]);
        }
        else{
            printf("-\n");
        }
    }
}

void bfs_lista(GrafoLA *G, int s){
    int v,u;
    Cell *aux;

        if (G != NULL){
            for (v = 0; v < G->V; v++){
                G->cor[v] = 0;
                G->pai[v] = -1;
                G->d[v] = INT_MAX;
            }
            G->cor[s] = 1;
            G->d[s] = 0;
            FilaE *f = criar_filaE();
            enfileirar(s,f);
            while(!filaE_vazia(f)){
                u = desenfileirar(f);
                aux = G->adj[u]->head;
                while(aux != NULL){
                    v = aux->key;
                    if(G->cor[v] == 0){
                        G->cor[v] = 1;
                        G->d[v] = G->d[u] + 1;
                        G->pai[v] = u;
                        enfileirar(v,f);
                    }
                    aux = aux->next;
                }

            G->cor[u] = 2;
        }
    
    
        printf("v d p\n");
        for(v=0;v<G->V;v++){
            printf("%d ",v);
            if(G->d[v] < INT_MAX){
                printf("%d ",G->d[v]);
            }
            else{
                printf("- ");
            }
            if(G->pai[v] >= 0){
                printf("%d \n",G->pai[v]);
            }
            else{
                printf("- \n");
            }
        }
    }
}
void lista_matriz(GrafoLA *gLA){
    int mat[gLA->V][gLA->V];
    int i,j;
    Cell *aux;
    GrafoMA *gMA = iniciar_grafoMA(gLA->V);
    if(gLA != NULL){
         for(i=0;i<gLA->V;i++){
            for(j=0;j<gLA->V;j++){
                gMA->mat[i][j] = 0;
            }
        }
        for(i=0;i<gLA->V;i++){
            aux = gLA->adj[i]->head;
            while(aux != NULL){
                gMA->mat[i][aux->key] = 1;
                aux = aux->next;
            }
        }
        for(i=0;i<gLA->V;i++){
            for(j=0;j<gLA->V;j++){
                printf("%d ",gMA->mat[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int tam, v;
    scanf("%d", &tam);
    GrafoLA * gLA = iniciar_grafoLA(tam);

    for(int i = 0; i < tam; i++){
        do{
            scanf("%d", &v);
            if(v != -1)
                inserir_arestaLA(gLA, i, v);
        }
        while(v != -1);
    }
    lista_matriz(gLA);
} 