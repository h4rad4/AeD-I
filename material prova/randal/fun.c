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

void imprimeLista(Lista *p)
{
    Lista *q; // Variáve auxiliar para percorrer a lista

    for (q = p; q != NULL; q->inicio->proximo)
    {
        printf("%d ", q->inicio->proximo->valor);
    }
}

int estadoLista(Lista *p)
{
    return (p == NULL); // Se o resultado da comparação de 'p' com NULL for verdadeiro então retorna 1 (lista vazia), se não retorna 0
}

void buscaLista(Lista *p, int value)
{
    Lista *l;
    for (l = p; l != NULL; l = l->inicio->proximo)
    {
        if (l->inicio->proximo->valor == value)
            return l; // Retorna o ponteiro do nó onde o elemento foi encontrado
    }

    return NULL; // Não achou o elemento
}

Lista *removeLista(Lista *p)
{
    Lista *q = p;
    Lista *anterior = NULL;


}
