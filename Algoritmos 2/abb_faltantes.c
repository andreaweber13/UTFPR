#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node Node;
struct Node{
    int item; 
    struct Node *esq; 
    struct Node *dir; 
};
Node* criar(int item){
    Node *tree = (Node*)malloc(sizeof(Node)); 

    tree->item = item; 
    tree->esq = NULL; 
    tree->dir = NULL; 

    return tree; 
}

Node* pesquisar(int item, Node* tree){
    if(tree != NULL){
        if(item == tree->item){
            return tree; 
        }
        else if(item < tree->item){
            return pesquisar(item, tree->esq); 
        }
        else{
            return pesquisar(item, tree->dir); 
        }
    }
    else{
        return NULL;
    }
}
int menor_item(Node* tree){
    Node* aux = tree;
    if(aux != NULL){
        while(aux->esq != NULL){ 
            aux = aux->esq; 
        }
        return aux->item; 
    }
    else{
        return -1;
    }
}
int qtde_nos(Node *tree){
    Node* aux = tree;
    if(aux == NULL){
        return 0;
    }
    else{
        return 1 + qtde_nos(aux->esq) + qtde_nos(aux->dir);
    }
}
int altura(Node* tree){
    Node *aux = tree;
    int h_esq, h_dir;
    if(aux==NULL){
        return -1;
    }
    else{
        h_esq = altura(aux->esq);
        h_dir = altura(aux->dir);
        if(h_esq > h_dir){
            return h_esq + 1;
        }
        else{
            return h_dir + 1;
        }
    }
}
int nos_faltantes(Node *tree){
    Node* aux = tree;
    int i=0;
    int h = altura(aux);
    int cheia=0;
    if(aux == NULL){
        return 0;
    }
    else{
        while(i<h){
            cheia = cheia + pow(2,i);
            i++;
        }
        return cheia - qtde_nos(aux) + 1;
    }
}
int folhas(Node *tree){
    Node* aux = tree;
    if(aux == NULL){
        return 0;
    }
    else if(aux->dir == NULL && aux->esq == NULL){
        return 1;
    }
    else{
        return folhas(aux->esq) + folhas(aux->dir);
    }
}
int maior_item(Node* tree){
    Node* aux = tree;
    if(aux != NULL){
        while(aux->dir != NULL){
            aux = aux->dir;
        }
        return aux->item;
    }
    else{
        return -1;
    }
}
Node* inserir(int item, Node* tree){
    if(tree == NULL){
        tree = criar(item);
    }
    else if(item < tree->item){
        tree->esq = inserir(item,tree->esq);
    }
    else if(item > tree->item){
        tree->dir = inserir(item,tree->dir);
    }
    return tree;
}

int main(){
    int tam, item;
    scanf("%d",&tam);
    Node *no = criar(item); 
    for(int i=0;i<tam;i++){
        scanf("%d",&item);
        inserir(item,no);
    }
    printf("%d",nos_faltantes(no));
}


