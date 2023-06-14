#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Lista *criarPolinomio(Lista *p, int base, int exp)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->base = base;
    novo->exp = exp;
    novo->proximo = NULL;

    if (p->inicio == NULL)
    {
        p->inicio = novo;
    }
    else if (exp > p->inicio->exp)
    {
        novo->proximo = p->inicio;
        p->inicio = novo;
    }
    else
    {
        Node *atual = p->inicio;

        while (atual->proximo != NULL && exp < atual->proximo->exp)
        {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    return p;
}

void imprimirPolinomio(Lista *p)
{
    Node *atual = p->inicio;

    while (atual != NULL)
    {
        printf("%dx^%d ", atual->base, atual->exp);
        atual = atual->proximo;

        if (atual != NULL)
            printf(" + ");
    }
}

Lista *somaPolinomio(Lista *p1, Lista *p2)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    // Inicializando

    if (p1->inicio->exp > p2->inicio->exp)
    {
        novo->inicio = p1->inicio;
        p1->inicio = p1->inicio->proximo;

    }
    else if (p2->inicio->exp > p1->inicio->exp)
    {
        novo->inicio = p2->inicio;
        p2->inicio = p2->inicio->proximo;

    }
    else
    {
        novo->inicio->base = p1->inicio->base + p2->inicio->base;
        novo->inicio->exp = p1->inicio->exp;

        p1->inicio = p1->inicio->proximo;
        p2->inicio = p2->inicio->proximo;

    }

    while (p1->inicio != NULL || p2->inicio != NULL)
    {
        printf("oii");
        
        if (p1->inicio->exp > p2->inicio->exp)
        {
            novo->inicio->proximo = p1->inicio;
            p1->inicio = p1->inicio->proximo;
        }
        else if (p2->inicio->exp > p1->inicio->exp)
        {
            novo->inicio->proximo = p2->inicio;
            p2->inicio = p2->inicio->proximo;

        }
        else
        {
            novo->inicio->proximo->base = p1->inicio->base + p2->inicio->base;
            novo->inicio->proximo->exp = p1->inicio->exp;

            p1->inicio = p1->inicio->proximo;
            p2->inicio = p2->inicio->proximo;

        }
    }

    return novo;
}