#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializarFila(FILA *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int inserirAviao(FILA *fila, AVIAO novo_aviao)
{
    NODE *Node = malloc(sizeof(NODE));
    if (Node == NULL)
    {
        printf("Nao foi possivel alocar memoria.");
        return 0;
    }

    Node->aviao = novo_aviao;
    Node->proximo = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = Node;
    }
    else
    {
        fila->fim->proximo = Node;
    }

    fila->fim = Node;
    fila->tamanho++;

    return 1;
}

void imprimirAviao(FILA *fila)
{
    printf("\nFila atual: \n");

    if (fila->inicio == NULL)
    {
        printf("Nao ha avioes em espera.");
        return;
    }

    NODE *i = fila->inicio;

    while (i != NULL)
    {
        printf("\nAviao '%s'\nCodigo: %d", i->aviao.nome, i->aviao.codigo);
        printf("\n");
        i = i->proximo;
    }
}

void liberarAviao(FILA *fila)
{
    if (fila->inicio == NULL)
        printf("Nao ha avioes a liberar");

    NODE *i = fila->inicio;

    printf("\n-> O aviao %s, de codigo %d, decolou!\n", i->aviao.nome, i->aviao.codigo);

    free(i);

    fila->inicio = fila->inicio->proximo;
}
