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
        h = elemento.key % M;

    /* Inserção */
    for (h; tabela[h] != NULL && tabela[h]->disp != 0; h++)
    {
        col++;
        if (tabela[h]->key == elemento.key % M)
            return 0;
    }

    tabela[h] = malloc(sizeof(Hash));
    *(tabela[h]) = elemento;
    tabela[h]->disp = 1;

    printf("\nColisoes (para %d): %d", elemento.key, col);
}

int sQuadratica1(TB_HASH tabela, Hash elemento)
{
    int h;

    for (int i = 0; i < M; i++)
        h = (elemento.key + (int)pow(i, 2)) % M;

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
