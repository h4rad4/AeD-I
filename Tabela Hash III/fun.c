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
    int col = 0;

    for (int i = 0; i < M; i++)
    {
        h = (elemento.key + i) % M;

        if (i != 0)
            col++;
        if (tabela[h] == NULL)
            break;
    }

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
    // tabela[h]->disp = 1;

    printf("\nColisoes (para %d): %d", elemento.key, col++);
}

int sQuadratica1(TB_HASH tabela, Hash elemento)
{
    int h;
    int col = 0;

    for (int i = 0; i < M; i++)
    {
        h = (elemento.key + (int)pow(i, 2)) % M;

        if (i != 0)
            col++;
        if (tabela[h] == NULL)
            break;
    }

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;

    printf("Colisoes (para %d): %d\n", elemento.key, col++);
}

int sQuadratica2(TB_HASH tabela, Hash elemento)
{
    int h;
    int col = 0;

    for (int i = 0; i < M; i++)
    {
        h = fmod((elemento.key + 2 * i + pow(i, 2)), M);

        if (i != 0)
            col++;
        if (tabela[h] == NULL)
            break;
    }

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;

    printf("Colisoes (para %d): %d\n", elemento.key, col++);
}

int hashDuplo(TB_HASH tabela, Hash elemento)
{
    int h1 = elemento.key % M;
    int h2 = 7 - (elemento.key % 7);
    int h;
    int col = 0;

    for (int i = 0; i < M; i++)
    {
        h = (h1 + i * h2) % M;
        if (i != 0)
            col++;
        if (tabela[h] == NULL)
            break;
    }

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;

    printf("Colisoes (para %d): %d\n", elemento.key, col);
}

void imprimirTabela(TB_HASH tabela)
{
    printf("\n-> Tabela: ");
    for (int i = 0; i < M; i++)
    {
        printf("\t");
        if (tabela[i] == NULL)
            printf("NULL");
        else
            printf("%d", tabela[i]->key);
    }
    printf("\n");
}
