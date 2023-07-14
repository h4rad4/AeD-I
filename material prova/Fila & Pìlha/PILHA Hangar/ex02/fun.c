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
        printf("Aviao: '%s' \nCodigo: %d\n", i->aviao.nome, i->aviao.codigo);
        printf("\n");

        i = i->proximo;
    }
}

void liberaAviao(HANGAR *hangar, int pos)
{
    if (hangar->inicio == NULL)
        printf("Nao ha avioes para liberar");

    /* Percorrendo a pilha principal até a posição desejada, eliminando todos os elementos anteriores a essa posição */
    HANGAR temp;
    inicializarHangar(&temp);

    for (int j = 0; j < pos; j++)
    {
        /* Salvando os elementos desnecessários em uma pilha temporária */
        inserirAviao(&temp, hangar->inicio->aviao);

        pop(hangar);
    }

    /* O elemento que se deseja remover acaba sendo salvo na pilha temporária, portanto deve-se fazer um 'pop' nele */
    pop(&temp);

    /* Recolocando os elementos da pilha temporária na pilha principal */

    for (int k = 0; k < pos - 1; k++)
    {
        inserirAviao(hangar, temp.inicio->aviao);

        pop(&temp);
    }
}

void pop(HANGAR *hangar)
{
    free(hangar->inicio);
    // printf("nome: %s \n codigo: %d\n", hangar->inicio->aviao.nome, hangar->inicio->aviao.codigo);

    hangar->inicio = hangar->inicio->proximo;
    hangar->tamanho--;

    // printf("nome: %s \n codigo: %d\n", hangar->inicio->aviao.nome, hangar->inicio->aviao.codigo);
}
