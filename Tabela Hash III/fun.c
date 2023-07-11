#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void inicializaHash(Hash TB_HASH)
{
    for (int i = 0; i < M; i++)
        TB_HASH[i] = NULL;
}

int sLinear(Hash TB_HASH)
{
    /* Dispersão */
    int h;

    for (int i = 0; i < M; i++)
        h = (TB_HASH.key + i) % M;

    /* Inserção */
    for (h; h != NULL; h++)
    {
        TB_HASH[h];
    }
}

int sQuadratica1(Hash TB_HASH)
{
    int h;

    for (int i = 0; i < M; i++)
        h = fmod((TB_HASH.key + pow(i, 2)), M);

    return h;
}

int sQuadratica2(Hash TB_HASH)
{
    int h;

    for (int i = 0; i < M; i++)
        h = fmod((TB_HASH.key + 2 * i + pow(i, 2)), M);
}

int hash01(Hash TB_HASH)
{
    return TB_HASH.key % M;
}

int hash02(Hash TB_HASH)
{
    return 7 - (TB_HASH.key % 7);
}

void inserirHash(Hash TB_HASH, int key);
