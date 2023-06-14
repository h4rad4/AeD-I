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
    Lista *resultado = (Lista *)malloc(sizeof(Lista));
    resultado->inicio = NULL;

    Node *poli1 = p1->inicio;
    Node *poli2 = p2->inicio;

    while (poli1 != NULL && poli2 != NULL)
    {
        if (poli1->exp < poli2->exp)
        {
            criarPolinomio(resultado, poli1->base, poli1->exp);
            poli1 = poli1->proximo;
        }
        else if (poli2->exp < poli1->exp)
        {
            criarPolinomio(resultado, poli2->base, poli2->exp);
            poli2 = poli2->proximo;
        }
        else
        {
            int somaBase = poli1->base + poli2->base;
            if (somaBase != 0)
            {
                criarPolinomio(resultado, somaBase, poli1->exp);
            }
            poli1 = poli1->proximo;
            poli2 = poli2->proximo;
        }
    }

    while (poli1 != NULL)
    {
        criarPolinomio(resultado, poli1->base, poli1->exp);
        poli1 = poli1->proximo;
    }

    while (poli2 != NULL)
    {
        criarPolinomio(resultado, poli2->base, poli2->exp);
        poli2 = poli2->proximo;
    }

    return resultado;
}
