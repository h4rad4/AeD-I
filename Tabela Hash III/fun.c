#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void inicializaHash(TB_HASH tabela)
{
    for (int i = 0; i < M; i++)
        tabela[i] = NULL;
}

int sLinear(TB_HASH tabela, Hash elemento)
{
    /* Dispersão */
    int h;

    for (int i = 0; i < M; i++)
    {
        h = (tabela[i]->key + i) % M;
        printf("[%d]", h);
    }

    /* Inserção */
    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
}

int sQuadratica1(TB_HASH tabela, Hash elemento)
{
    int h;

    for (int i = 0; i < M; i++)
        h = fmod((tabela[i]->key + pow(i, 2)), M);

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
}

int sQuadratica2(TB_HASH tabela, Hash elemento)
{
    int h;

    for (int i = 0; i < M; i++)
        h = fmod((tabela[i]->key + 2 * i + pow(i, 2)), M);

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
}

int hash01(TB_HASH tabela, Hash elemento)
{
    int h;

    for (int i = 0; i < M; i++)
        h = tabela[i]->key % M;

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
}

int hash02(TB_HASH tabela, Hash elemento)
{
    int h;

    for (int i = 0; i < M; i++)
        h = 7 - (tabela[i]->key % 7);

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
}

void imprimirTabela(TB_HASH tabela)
{
    for (int i = 0; i < M; i++)
    {
        if (tabela[i] != NULL)
        {
            printf("\n");
            printf("%d\t", tabela[i]->key);
        }
        else
            printf("NULL\t", i + 1);
    }
}
