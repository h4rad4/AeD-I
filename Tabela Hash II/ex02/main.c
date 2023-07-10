#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    PACIENTE p, *pr;

    TB_HASH Tabela;
    PACIENTE p1, p2, p3, p4, p5;

    PACIENTE Pacientes[N] =
        {{"Socrates", "209.478.341-42", 2470, 134201},
         {"Platao", "754.912.563-29", 2448, 258902},
         {"Aristoteles", "621.830.957-10", 2407, 405603},
         {"Tales de Mileto", "485.739.620-83", 2600, 708904},
         {"Pitagoras", "162.074.839-57", 2590, 126705}};

    inicializahash(Tabela);

    for (int i = 0; i < N; i++)
        inserir(Tabela, Pacientes[i]);

    mostrarhash(Tabela);

    pr = busca(Tabela, 1089);
    if (pr != NULL)
    {
        printf("\n    Achou nome: %s\n", pr->nome);
    }
    else
    {
        printf("\n    Nao encontrou o paciente.\n");
    }

    return 0;
}
