#include <stdio.h>
#include <limits.h>
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int preco_max(int precos[], int tam_haste){
    int i,j,q;
    int r[tam_haste+1];
    r[0] = 0;
    for(i=1;i<=tam_haste;i++){
        q = INT_MIN;
        
        for(j=0;j<i;j++){
            q = max(q,precos[j] + r[i-j-1]);
        }
        r[i] = q;
    }
    return r[tam_haste];
}
int main()
{
   int tam_haste, tam_vet;
   scanf("%d",&tam_haste);
   scanf("%d",&tam_vet);
   int precos[tam_vet];
   for(int i=0;i<tam_vet;i++){
       scanf("%d", &precos[i]);
   }
   printf("%d",preco_max(precos,tam_haste));
}

