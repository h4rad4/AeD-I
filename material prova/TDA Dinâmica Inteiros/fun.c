#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirElemento(Lista *lista, int elemento)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = elemento;
    novoNo->next = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
    }
    else
    {
        Node *atual = lista->inicio;
        while (atual->next != NULL)
        {
            atual = atual->next;
        }

        atual->next = novoNo;
    }

    lista->tamanho++;
}

void removerElemento(Lista *lista, int elemento)
{
    if (lista->inicio == NULL)
    {
        return;
    }

    Node *anterior = NULL;
    Node *atual = lista->inicio;

    while (atual != NULL)
    {
        if (atual->valor == elemento)
        {
            if (anterior == NULL)
            {
                lista->inicio = atual->next;
            }
            else
            {
                anterior->next = atual->next;
            }

            free(atual);
            lista->tamanho--;

            return;
        }

        anterior = atual;
        atual = atual->next;
    }
}

int buscarElemento(Lista *lista, int elemento)
{
    Node *atual = lista->inicio;
    int posicao = 0;

    while (atual != NULL)
    {
        if (atual->valor == elemento)
        {
            return posicao;
        }

        atual = atual->next;
        posicao++;
    }

    return -1;
}

int buscaBinaria(Lista *lista, int elemento)
{
    int esquerda = 0;
    int direita = lista->tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;

        Node *atual = lista->inicio;
        for (int i = 0; i < meio; i++)
        {
            atual = atual->next;
        }

        if (atual->valor == elemento)
        {
            return meio;
        }
        else if (atual->valor < elemento)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1;
}

int buscaBinariaRecursiva(Node *inicio, int elemento, int esquerda, int direita)
{
    if (esquerda > direita)
    {
        return -1;
    }

    int meio = (esquerda + direita) / 2;

    Node *atual = inicio;
    for (int i = 0; i < meio; i++)
    {
        atual = atual->next;
    }

    if (atual->valor == elemento)
    {
        return meio;
    }
    else if (atual->valor < elemento)
    {
        return buscaBinariaRecursiva(inicio, elemento, meio + 1, direita);
    }
    else
    {
        return buscaBinariaRecursiva(inicio, elemento, esquerda, meio - 1);
    }
}

void inserirElementoOrdenado(Lista *lista, int elemento)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = elemento;
    novoNo->next = NULL;

    if (lista->inicio == NULL)
    {
        // Caso a lista esteja vazia, o novo nó se torna o primeiro nó da lista
        lista->inicio = novoNo;
        lista->tamanho++;
        return;
    }

    if (elemento < lista->inicio->valor)
    {
        // Caso o elemento seja menor que o valor do primeiro nó, o novo nó se torna o novo primeiro nó da lista
        novoNo->next = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho++;
        return;
    }

    Node *anterior = lista->inicio;
    Node *atual = lista->inicio->next;

    while (atual != NULL)
    {
        if (elemento < atual->valor)
        {
            // O novo nó deve ser inserido entre o nó anterior e o nó atual
            anterior->next = novoNo;
            novoNo->next = atual;
            lista->tamanho++;
            return;
        }

        anterior = atual;
        atual = atual->next;
    }

    // Caso o elemento seja maior que todos os valores na lista, ele é inserido no final da lista
    anterior->next = novoNo;
    lista->tamanho++;
}

int obterQuantidadeElementos(Lista *lista)
{
    return lista->tamanho;
}

void imprimirLista(Lista *lista)
{
    Node *atual = lista->inicio;

    printf("Elementos da lista:");

    while (atual != NULL)
    {
        printf(" %d", atual->valor);
        atual = atual->next;
    }

    printf("\n");
}
