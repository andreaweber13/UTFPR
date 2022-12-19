#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main()
{
    Lista *l;
    Lista *l2;
    l = cria_lista();
    l2 = cria_lista();
    insere_inicio(l, 5);
    insere_inicio(l, 2);
    insere_inicio(l,3);
    insere_inicio(l, 8);
    imprime(l);
    l2 = transfere(l, l2);
    printf("\nOrdenadas: \n");
    imprime(l2);
    return 0;
}