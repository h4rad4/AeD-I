#include <stdio.h>
#include <stdlib.h>
#include "main.h"

FILA *inserirAviao(FILA *fila, AVIAO novo_aviao)
{
    NODE *Node = malloc(sizeof(NODE));
    Node->aviao = novo_aviao;
    Node->proximo = NULL;

    if (Node == NULL)
    {
        printf("Nao foi possivel alocar memoria.");
        return -1;
    }

    if (fila->inicio == NULL)
    {
        fila->inicio = Node;
        fila->tamanho++;
    }
    else
    {
        fila->fim->proximo = Node;
        fila->inicio = Node;
        fila->tamanho++;
    }
}

void imprimirAviao(FILA *fila)
{
    for (i = fila)
}