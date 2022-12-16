#include <stdio.h>
int troco;
int qtde_moedas,i, retorno=0;
int main(){
    scanf("%d",&troco);
    scanf("%d",&qtde_moedas);
    int vet[qtde_moedas];
    for(i=0;i<qtde_moedas;i++){
        scanf("%d",&vet[i]);
    }
    i=0;
    while((troco-retorno) > 0){
        while(i<qtde_moedas){
            if((troco-retorno)>=vet[i]){
                retorno += vet[i];
                printf("%d\n",vet[i]);
            }
            else{
                i++;
            }
        }
    }
}
