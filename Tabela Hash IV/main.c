#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    TB_HASH tabelaHash;
    inicializarHash(tabelaHash);

    int valores[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    for (int i = 0; i < N; i++)
        inserir(tabelaHash, valores[i]);

    exibirTabelaHash(tabelaHash);

    return 0;
}
