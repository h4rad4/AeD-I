#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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

void inicializaHash(TB_HASH tabela)
{
    for (int i = 0; i < M; i++)
        tabela[i] = NULL;
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

int main(int argc, char const *argv[])
{
    printf("[Sondagem Linear]:\n\n");

    TB_HASH Tabela1;
    inicializaHash(Tabela1);

    Hash e1[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < 5; i++)
    {
        sLinear(Tabela1, e1[i]);
    }
    imprimirTabela(Tabela1);

    return 0;
}
