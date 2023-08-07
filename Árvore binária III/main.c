#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    ARVORE a;
    int numeros[15] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};
    inicializar(&a);
    for (int i = 0; i < 15; i++)
        cria_no(&a, numeros[i]);

    printf("percorrendo a arvore em in-ordem:\n");
    print_in_ordem(a.raiz);

    printf("\na raiz dessa arvore eh: %d", a.raiz->num);
}