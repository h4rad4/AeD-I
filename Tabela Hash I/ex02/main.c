#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    TB_HASH Tabela;
    Paciente p1, p2, p3, p4, p5;

    Paciente Pacientes[N] =
        {{"Socrates", "209.478.341-42", 2470, 134201},
         {"Platao", "754.912.563-29", 2448, 258902},
         {"Aristoteles", "621.830.957-10", 2407, 405603},
         {"Tales de Mileto", "485.739.620-83", 2600, 708904},
         {"Pitagoras", "162.074.839-57", 2590, 126705}};

    inicializarHash(Tabela);

    for (int i = 0; i < N; i++)
        inserirHash(Tabela, Pacientes[i]);

    imprimirTabela(Tabela);

    return 0;
}
