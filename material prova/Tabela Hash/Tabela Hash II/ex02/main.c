#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    TB_HASH Tabela;

    Paciente Pacientes[N] =
        {{"Leonardo da Vinci", "209.478.341-42", rand() % 10, 134201},
         {"Michelangelo", "754.912.563-29", rand() % 10, 258902},
         {"Donatello", "621.830.957-10", rand() % 10, 405603},
         {"Sanzio", "485.739.620-83", rand() % 10, 708904},
         {"Van Gogh", "162.074.839-57", rand() % 10, 126705}};

    inicializarHash(Tabela);

    for (int i = 0; i < N; i++)
        inserirHash(Tabela, Pacientes[i]);

    imprimirHash(Tabela);

    return 0;
}
