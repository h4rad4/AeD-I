#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializarHangar(HANGAR *hangar)
{
    hangar->inicio = NULL;
    hangar->fim = NULL;

    hangar->tamanho = 0;
}

int inserirAviao(HANGAR *hangar, AVIAO novo_aviao)
{
    NODE *Node = malloc(sizeof(NODE));

    if (Node == NULL)
    {
        printf("Nao foi possivel alocar memoria");
        return 0;
    }

    Node->aviao = novo_aviao;
    Node->proximo = hangar->inicio;

    hangar->inicio = Node;
    hangar->tamanho++;
}

void imprimirAviao(HANGAR *hangar)
{
    printf("\nAvioes no hangar atualmente: %d\n", hangar->tamanho);

    if (hangar->inicio == NULL)
    {
        printf("Nao ha avioes no hangar. ");
    }

    NODE *i = hangar->inicio;

    while (i != NULL)
    {
        printf("Aviao '%s': \nCodigo: %d\n", i->aviao.nome, i->aviao.codigo);
        printf("\n");

        i = i->proximo;
    }
}

void liberaAviao(HANGAR *hangar)
{
    NODE *i = hangar->inicio;

    // INCOMPLETO
}
