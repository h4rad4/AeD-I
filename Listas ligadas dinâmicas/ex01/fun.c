#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inserirLista(Node **head, int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = *head;
    novoNo->anterior = NULL;

    // Atualizando a referência para o nó anterior
    if (*head != NULL)
    {
        (*head)->anterior = novoNo;
    }

    *head = novoNo;
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

void criarListaOrdenada(Node **headL, Node **headK)
{
    Node *maior;
    Node *head;

    while (headL != NULL)
    {
        Node *maior = headL;
        Node *head = (*headL)->proximo;

        // Encontra o nó com o maior valor na lista L

        while (head != NULL)
        {
            if (head->proximo > maior->valor)
            {
                maior = head;
            }
            head = head->proximo;
        }

        // Remove o nó da lista L

        if (head->anterior != NULL)
        {
            maior->anterior->proximo = maior->proximo;
        }
        else
        {
            headL = maior->proximo;
        }

        if (maior->proximo != NULL)
        {
            maior->proximo->anterior = maior->anterior;
        }

        // Insere o nó no início da lista K

        maior->proximo = *headK;
        if (*headK != NULL)
            (*headK)->anterior = maior;

        *headK = maior;
        maior->anterior = NULL;
    }
}
