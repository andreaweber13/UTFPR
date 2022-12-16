#include <stdio.h>
#include <stdlib.h>
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
void nos_folhas(Node* tree){
    if(tree != NULL){
        nos_folhas(tree->esq);
        if(tree->dir == NULL && tree->esq == NULL){
            printf(" %d",tree->item);
        }
        nos_folhas(tree->dir);
    }
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
    nos_folhas(no);
}



