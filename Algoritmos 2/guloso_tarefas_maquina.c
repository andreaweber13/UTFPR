#include <stdio.h>
typedef struct{
    int id;
    int e;
    int d;
}Tarefa;
void tarefas(){
    int qtde,i,j;
    scanf("%d",&qtde);
    Tarefa tarefas[qtde];
    for(i=0;i<qtde;i++){
        scanf("%d %d",&tarefas[i].e, &tarefas[i].d);
        tarefas[i].id = i;
    }
    int deadline=0;
    for(i=0;i<qtde;i++){
        deadline += (tarefas[i].d - tarefas[i].e);
    }
    int aux;
    for(i=0;i<qtde;i++){
        for(j=i+1;j<qtde;j++){
            if((tarefas[i].d - tarefas[i].e)<=(tarefas[j].d - tarefas[j].e)){
                aux = tarefas[j].id;
                tarefas[j].id = tarefas[i].id;
                tarefas[i].id = aux;
                aux = tarefas[j].e;
                tarefas[j].e = tarefas[i].e;
                tarefas[i].e = aux;
                aux = tarefas[j].d;
                tarefas[j].d = tarefas[i].d;
                tarefas[i].d = aux;
            }
        }
    }
    for(i=0;i<qtde;i++){
        for(j=i+1;j<qtde;j++){
            if((tarefas[i].d - tarefas[i].e)==(tarefas[j].d - tarefas[j].e)){
                if(tarefas[i].id > tarefas[j].id){
                    aux = tarefas[j].id;
                    tarefas[j].id = tarefas[i].id;
                    tarefas[i].id = aux;
                }
            }
        }
    }
    for(i=0;i<qtde;i++){
        printf("%d\t",tarefas[i].id);
    }
    if(deadline>=0){
        deadline = 0;
    }
    else{
        deadline = deadline * (-1);
    }
    printf("\n%d",deadline);
}
int main(){
    tarefas();
}
