#include <stdio.h>
int sequenciamax(int tam, int vet[]){
    int max = vet[0];
    int i,j;
    int soma;
    for(i=0;i<tam;i++){
        soma = 0;
        j=i;
        while(j>0){
            soma = soma + vet[j];
            if(soma>max){
                max = soma;
            }
            j--;
        }
    }
    return max;
}
int main()
{
    int tam;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }
    printf("%d",sequenciamax(tam, vet));
}


