#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializaLista(Lista *p)
{
    p->inicio = NULL;
}

void inserirNoFinal(Lista *p, int valor)
{
    // Cria um novo nó
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    // Verifica se a lista está vazia
    if (p->inicio == NULL)
        // O novo nó se torna o início da lista
        p->inicio = novoNo;
    else
    {
        // Percorre a lista até encontrar o último nó
        Node *temp = p->inicio;

        while (temp != NULL)
        {
            temp = temp->proximo;
        }

        // Insere o valor no final da lista
        temp->proximo = valor;
    }
}

void inserirNoComeço(Lista *p, int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    // O próximo nó será o início atual da lista
    novoNo->proximo = p->inicio;
    // O novo nó se torna o novo início da lista
    p->inicio = novoNo;
}

void inserirNoMeio(Lista *p, int valor, int posicao)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    // Percorre a lista até a posição desejada
    Node *temp = p->inicio;
    int cont = 0;

    while (temp != NULL && cont < posicao)
    {
        temp = temp->proximo;
        cont++;
    }

    // Verifica se a posição é válida
    if (temp == NULL)
    {
        printf("posicao invalida. ");
        free(novoNo);
        return;
    }
}

void removerMaiorParaMenor(Lista *p)
{
    if (p->inicio == NULL)
    {
        printf("lista vazia. ");
        return;
    }

    while (p->inicio != NULL)
    {
        // Encontra o maior valor na lista
        int maiorValor = p->inicio->valor;
        Node *maiorNo = p->inicio;
        Node *temp = p->inicio->proximo;

        while (temp != NULL)
        {
            if (temp->valor > maiorValor)
            {
                maiorValor = temp->valor;
                maiorNo = temp;
            }

            temp = temp->proximo;
        }

        // Remove o nó com o maior valor
        if (maiorNo == p->inicio)
        {
            // Caso o maior nó seja o primeiro
            p->inicio = p->inicio->proximo;
        }
        else
        {
            temp = p->inicio;

            while (temp->proximo != maiorNo)
            {
                temp = temp->proximo;
            }
            temp->proximo = maiorNo->proximo;
        }
        
        free(maiorNo);
    }
}