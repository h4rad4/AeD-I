#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    Lista lista;
    inicializarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    printf("Lista: ");
    Node *atual = lista.inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\n");

    removerElemento(&lista, 10);

    printf("Lista apos a remocao: ");
    atual = lista.inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\n");

    int posicao = buscarElemento(&lista, 5);
    if (posicao != -1)
    {
        printf("Elemento 5 encontrado na posicao %d\n", posicao);
    }
    else
    {
        printf("Elemento 5 não encontrado na lista\n");
    }

    return 0;
}
