#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

lista *criaVetor(int n)
{
    printf("\nAlocando memoria...");
    lista *p = malloc(sizeof(lista));
    p->vetor = malloc(n * sizeof(int));
    p->n = n;

    printf("\tAlocado!");

    return p;
}

void preencherVetor(lista *p)
{
    printf("\n");

    for (int i = 0; i < p->n; i++)
        p->vetor[i] = rand() % 100;
}

void preencherVetorOrdenado(lista *p)
{
    printf("\n");

    for (int i = 0; i < p->n; i++)
        p->vetor[i] = rand() % 100;

    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < 29 - i; j++)
        {
            if (p->vetor[j] > p->vetor[j + 1])
            {
                int temp = p->vetor[j];
                p->vetor[j] = p->vetor[j + 1];
                p->vetor[j + 1] = temp;
            }
        }
    }
}

void printVetor(lista *p)
{
    printf("Vetor = ");

    for (int i = 0; i < p->n; i++)
        printf("%d ", p->vetor[i]);

    printf("\n");
}

int liberaVetor(lista *p)
{
    free(p->vetor);
    free(p);

    return 1;
}

int buscaSequencial(lista *p, int value, int *cont)
{
    *cont = 0;

    for (int i = 0; i < p->n; i++)
    {
        (*cont)++;
        if (p->vetor[i] == value)
            return i + 1;
    }
    return -1;
}

int buscaSequencialOrdenada(lista *p, int value, int *cont)
{
    *cont = 0;

    for (int i = 0; i < p->n; i++)
    {
        (*cont)++;
        if (p->vetor[i] >= value)
        {
            if (p->vetor[i] == value)
                return i + 1;
            else
                return -1;
        }
    }
    return -1;
}

int buscaBinariaIterativa(lista *p, int value, int *cont)
{
    *cont = 0;
    int primeiro = 0;
    int ultimo = 30 - 1;
    int meio = -1;

    while (primeiro <= ultimo)
    {
        (*cont)++;
        meio = primeiro + (ultimo - primeiro) / 2;

        if (value == p->vetor[meio])
            return meio + 1;
        else if (value > p->vetor[meio])
            primeiro = meio + 1;
        else
            ultimo = meio - 1;
    }
    return -1;
}

int buscaBinariaRecursiva(lista *p, int value, int left, int right, int *cont)
{
    (*cont)++;

    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (p->vetor[mid] == value)
    {
        return mid + 1; // Valor encontrado
    }
    else if (p->vetor[mid] < value)
    {
        return buscaBinariaRecursiva(p, value, mid + 1, right, cont); // metade direita
    }
    else
    {
        return buscaBinariaRecursiva(p, value, left, mid - 1, cont); // metade esquerda
    }
}


void imprimirMaiorElemento(lista *p)
{
    int maior = p->vetor[0];

    for (int i = 1; i < p->n; i++)
    {
        if (p->vetor[i] > maior)
        {
            maior = p->vetor[i];
        }
    }

    printf("Maior elemento da lista: %d\n", maior);
}

void imprimirMenorElemento(lista *p)
{
    int menor = p->vetor[0];

    for (int i = 1; i < p->n; i++)
    {
        if (p->vetor[i] < menor)
        {
            menor = p->vetor[i];
        }
    }

    printf("Menor elemento da primeira lista: %d\n", menor);
}

void imprimirSomaElementos(lista *p)
{
    int soma = 0;

    for (int i = 0; i < p->n; i++)
    {
        soma += p->vetor[i];
    }

    printf("Soma dos elementos da primeira lista: %d\n", soma);
}

void imprimirProdutoElementos(lista *p)
{
    int produto = 1;

    for (int i = 0; i < p->n; i++)
    {
        produto *= p->vetor[i];
    }

    printf("Produto dos elementos da primeira lista: %d\n", produto);
}
