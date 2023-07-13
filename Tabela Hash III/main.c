#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    printf("[Sondagem Linear]:\n\n");

    TB_HASH Tabela1;
    inicializaHash(Tabela1);

    Hash e1[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < 6; i++)
    {
        sLinear(Tabela1, e1[i]);
    }
    imprimirTabela(Tabela1);

    printf("\n[Sondagem Quadratica 1]:\n\n");

    TB_HASH Tabela2;
    inicializaHash(Tabela2);

    Hash e2[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < 6; i++)
    {
        sQuadratica1(Tabela2, e2[i]);
    }
    imprimirTabela(Tabela2);

    printf("\n[Sondagem Quadratica 2]:\n\n");

    TB_HASH Tabela3;
    inicializaHash(Tabela3);

    Hash e3[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < 6; i++)
    {
        sQuadratica2(Tabela3, e3[i]);
    }
    imprimirTabela(Tabela3);

    printf("\n[Hash Duplo]:\n\n");

    TB_HASH Tabela4;
    inicializaHash(Tabela4);

    Hash e4[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < 6; i++)
    {
        hashDuplo(Tabela4, e4[i]);
    }
    imprimirTabela(Tabela4);

    return 0;
}
