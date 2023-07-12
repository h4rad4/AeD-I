#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    TB_HASH Tabela;
    inicializaHash(Tabela);

    Hash Hash[M] = {{365}, {112}, {180}, {213}, {13}, {27}};

    for (int i = 0; i < M; i++)
    {
        sLinear(Tabela, Hash[i]);
    }

    imprimirTabela(Tabela);

    return 0;
}
