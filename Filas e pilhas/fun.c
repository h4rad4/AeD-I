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
    Node->aviao = novo_aviao;
    Node->proximo = NULL;

    if (Node = NULL)
    {
        printf("Nao foi possivel alocar memoria.");
        return 0;
    }

    if (fila->inicio = NULL)
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

    return 1;
}

void imprimirAviao(FILA *fila)
{
    NODE node;

    NODE *i = node.proximo;

    if (fila->inicio == NULL)
    {
        printf("nao ha avioes em espera");
    }

    while (i->proximo != NULL)
    {
        printf("\nAviao '%s' \nCodigo: %d", i->aviao.nome, i->aviao.codigo);
        i = i->proximo;
    }
}

// INCOMPLETO