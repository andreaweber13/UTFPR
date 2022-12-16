#include <stdio.h>
int soma_max(int *vet, int ini, int fim){
    int m;
    if(ini == fim){
        if(vet[ini] >= 0){
            return vet[ini];
        }
        else{
            return 0;
        }
    }
    else if(ini < 0 || ini > fim){
        return 0;
    }
    else{
        m = (int)(ini+fim)/2;
        if(vet[m] >= 0){
            return vet[m] + soma_max(vet,ini, m-1) + soma_max(vet,m+1,fim);
        }
        else{
            return soma_max(vet,ini, m-1) + soma_max(vet,m+1,fim);
        }
    }
}
int main(){
    int tam;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }
    printf("%d",soma_max(vet,0,tam-1));
}


