#include <stdlib.h>
#include "item.h"
#include <string.h>
#include <stdio.h>

int main(void){
    Fila *f;
    Fila *f2;
    f = cria_fila();
    enfileira(f, 'a');
    enfileira(f, 'd');
    enfileira(f, 'd');
    enfileira(f, 'd');
    enfileira(f, 'c');
    enfileira(f, 'f');
    enfileira(f, 'b');
    enfileira(f, 'h');
    imprime(f);
    printf("Removendo duplicatas: \n");
    f2 = remove_duplicados(f);
    imprime(f2);
}