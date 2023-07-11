#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

#define N 5

void inicializaHash(TB_HASH tabela)
{
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

int indiceHash(int codigo)
{
    return codigo % N;
}

