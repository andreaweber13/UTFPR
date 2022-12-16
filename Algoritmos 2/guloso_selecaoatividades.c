#include <stdio.h>
int qtde_atividades;
int i, j;
void selecao_atividades(){
    scanf("%d",&qtde_atividades);
    int id[qtde_atividades], ini[qtde_atividades], fim[qtde_atividades];
    for(i=0;i<qtde_atividades;i++){
        scanf("%d %d %d",&id[i],&ini[i],&fim[i]);
    }
    int aux;
    for(i=0;i<qtde_atividades;i++){
        for(j=i+1;j<qtde_atividades;j++){
            if(fim[i]>fim[j]){
                aux = fim[j];
                fim[j] = fim [i];
                fim[i] = aux;
                aux = ini[j];
                ini[j] = ini[i];
                ini[i] = aux;
                aux = id[j];
                id[j] = id[i];
                id[i] = aux;
            }
        }
    }
    int menor = fim[0];
    printf("Aulas alocadas: %d", id[0]);
    for(i=0;i<qtde_atividades;i++){
        if(ini[i]>menor){
            printf(" %d",id[i]);
            menor = fim[i];
        }
    }
}
int main()
{
    selecao_atividades();
}

