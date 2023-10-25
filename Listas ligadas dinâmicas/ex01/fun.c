#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Node *inserirInicioLista(Node *head, int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = head;
    novoNo->anterior = NULL;

    if (head != NULL)
        head->anterior = novoNo;

    return novoNo;
}

void imprimirLista(Node *node)
{
    printf("Lista: ");
    while (node != NULL)
    {
        printf("%d ", node->valor);
        node = node->proximo;
    }
}

void criarListaOrdenada(Node *listaL, Node **listaK)
{
    while (listaL != NULL)
    {
        Node *maior = listaL;
        Node *atual = listaL->proximo;

        // Encontrando o maior elemento
        while (atual != NULL)
        {
            if (atual->valor > maior->valor)
                maior = atual;
            atual = atual->proximo;
        }
        // Apagando o elemento da lista
        if (maior->anterior != NULL)
            maior->anterior->proximo = maior->proximo; 
        else
            listaL = maior->proximo;

        if (maior->proximo != NULL)
            maior->proximo->anterior = maior->anterior;

        // Inserindo elemento na lista
        maior->proximo = *listaK;
        if (*listaK != NULL)
            (*listaK)->anterior = maior;

        *listaK = maior;
        maior->anterior = NULL;
    }
}
