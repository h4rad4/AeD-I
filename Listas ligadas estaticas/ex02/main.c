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

    printf("\n");
    printf("Lista Original: ");
    imprimirLista(lista.inicio);

    ListaLigada *copia;
    inicializarLista(copia);

    printf("Lista Copiada: ");
    copia = copiarListaLigada(&lista);
    imprimirLista(copia->inicio);

    No *Op1 = A_OperatorL1(lista.inicio);
    printf("Lista operada (A): ");
    imprimirLista(Op1);

    No *Op2 = B_OperatorL1(copia->inicio);
    printf("Lista operada (B): ");
    imprimirLista(Op2);

    liberarLista(Op1);
    liberarLista(Op2);

    return 0;
}
