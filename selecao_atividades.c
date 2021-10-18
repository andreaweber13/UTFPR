#include <stdio.h>
#include <stdlib.h>
int main(){
    int qtde_atividades;
    int i,j;
    //quantidade de atividades
    scanf("%d",&qtde_atividades);
    int inicio[qtde_atividades];
    int fim[qtde_atividades];
    //leitura do inicio e término das atividades
    for(i=0;i<qtde_atividades;i++){
        scanf("%d %d",&inicio[i],&fim[i]);
    }
    int aux;
    //ordenar as atividades
    for(i=0;i<qtde_atividades;i++){
        for(j=i+1;j<qtde_atividades;j++){
            if(fim[j]<fim[i]){
                aux = fim[i];
                fim[i] = fim[j];
                fim[j] = aux;
                aux = inicio[i];
                inicio[i] = inicio[j];
                inicio[j] = aux;
            }
        }
    }
    j=0;
    printf("Aulas alocadas: ");
    printf("%d ",j);
    for(i=0;i<qtde_atividades;i++){
        if(inicio[i]>fim[j]){
            j=i;
            printf("%d ",i);
        }
    }
}