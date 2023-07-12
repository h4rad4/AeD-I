#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    TB_HASH Tabela;
    inicializaHash(Tabela);

    Hash e1[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    printf("[Sondagem Linear]:\n");

    for (int i = 0; i < 5; i++)
    {
        sLinear(Tabela, e1[i]);
    }
    imprimirTabela(Tabela);

    printf("\n[Sondagem Quadratica 1]:\n");

    TB_HASH Tabela2;
    inicializaHash(Tabela2);

    Hash e2[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < 5; i++)
    {
        sQuadratica1(Tabela2, e2[i]);
    }
    imprimirTabela(Tabela2);

    return 0;
}
