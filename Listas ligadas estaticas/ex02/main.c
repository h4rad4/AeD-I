#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define N 10

int main(int argc, char const *argv[])
{
    ListaLigada lista;
    inicializarLista(&lista);

    int L;

    for (int i = 0; i < N; i++)
    {
        printf("Insira o elemento L%d. ", i + 1);
        scanf("%d", &L);

        inserirFimLista(&lista, L);
    }

    No *L1a = A_OperatorL1(lista.inicio);
    No *L1b = B_OperatorL1(lista.inicio);

    printf("Lista L1a: ");
    imprimirLista(L1a);

    printf("Lista L1b: ");
    imprimirLista(L1b);

    liberarLista(L1a);
    liberarLista(L1b);
    
    return 0;
}
