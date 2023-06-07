#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MAX 100 // Tamanho máximo da lista

void inicializarLista(Lista *lista)
{
    lista->cabeca = -1;
    lista->cauda = -1;
    lista->tamanho = 0;
}

void inserirElemento(Lista *lista, int valor)
{
    if (lista->tamanho == MAX)
    {
        printf("lista cheia. \n");
        return;
    }

    No novo;
    novo.dado = valor;
    novo.proximo = -1;

    if (lista->tamanho == 0)
    {
        lista->nos[0] = novo;
        lista->cabeca = 0;
        lista->cauda = 0;
    }
    else
    {
        lista->nos[lista->cauda].proximo = lista->tamanho;
        lista->nos[lista->tamanho] = novo;
        lista->cauda = lista->tamanho;
    }

    lista->tamanho++;
}

Lista percorrerListaA(Lista lista)
{
    Lista novaLista;
    inicializarLista(&novaLista);

    int atual = lista.cabeca;
    while (atual != -1)
    {
        inserirElemento(&novaLista, lista.nos[atual].dado);
        atual = lista.nos[atual].proximo;
    }

    if (novaLista.tamanho > 1)
    {
        // Move o primeiro p/ final da nova lista
        int primeiro = novaLista.cabeca;
        novaLista.cabeca = novaLista.nos[primeiro].proximo;
        novaLista.nos[primeiro].proximo = -1;
        novaLista.nos[novaLista.cauda].proximo = primeiro;
        novaLista.cauda = primeiro;
    }

    return novaLista;
}

Lista percorrerListaB(Lista lista)
{
    Lista novaLista;
    inicializarLista(&novaLista);

    for (int i = lista.tamanho - 1; i >= 0; i--)
    {
        inserirElemento(&novaLista, lista.nos[i].dado);
    }

    return novaLista;
}

void exibirLista(Lista lista)
{
    int atual = lista.cabeca;
    while (atual != -1)
    {
        printf("%d ", lista.nos[atual].dado);
        atual = lista.nos[atual].proximo;
    }
    printf("\n");
}

void copiarLista(Lista *l1, Lista *l2)
{
    inicializarLista(l2);

    int atual = l1->cabeca;
    while (atual != -1)
    {
        inserirElemento(l2, l1->nos[atual].dado);
        atual = l1->nos[atual].proximo;
    }
}

void concatenarListas(Lista *l1, Lista *l2)
{
    if (l2->tamanho == 0)
    {
        return;
    }

    if (l1->tamanho == 0)
    {
        *l1 = *l2;
        return;
    }

    l1->nos[l1->cauda].proximo = l1->tamanho;

    int atual = l2->cabeca;
    while (atual != -1)
    {
        inserirElemento(l1, l2->nos[atual].dado);
        atual = l2->nos[atual].proximo;
    }
}

// Intercala os elementos das listas l1 e l2
Lista intercalarListas(Lista *l1, Lista *l2)
{
    Lista listaIntercalada;
    inicializarLista(&listaIntercalada);

    int atualL1 = l1->cabeca;
    int atualL2 = l2->cabeca;

    while (atualL1 != -1 && atualL2 != -1)
    {
        inserirElemento(&listaIntercalada, l1->nos[atualL1].dado);
        inserirElemento(&listaIntercalada, l2->nos[atualL2].dado);

        atualL1 = l1->nos[atualL1].proximo;
        atualL2 = l2->nos[atualL2].proximo;
    }

    // Caso uma lista tenha mais elementos que a outra
    while (atualL1 != -1)
    {
        inserirElemento(&listaIntercalada, l1->nos[atualL1].dado);
        atualL1 = l1->nos[atualL1].proximo;
    }

    while (atualL2 != -1)
    {
        inserirElemento(&listaIntercalada, l2->nos[atualL2].dado);
        atualL2 = l2->nos[atualL2].proximo;
    }

    return listaIntercalada;
}
