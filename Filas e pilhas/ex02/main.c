#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define n 10

int main(int argc, char const *argv[])
{
    HANGAR Hangar;
    inicializarHangar(&Hangar);

    /* Preenchendo a pilha */
    AVIAO Avioes[n] =
        {{"LILY", 1},
         {"TULIP", 2},
         {"ROSE", 3},
         {"DANDELION", 4},
         {"GARDENIA", 5},
         {"ORCHID", 6},
         {"LAVENDER", 7},
         {"DAISY", 8},
         {"POPPY", 9},
         {"LOTUS", 10}};

    for (int i = 0; i < n; i++)
        inserirAviao(&Hangar, Avioes[i]);

    imprimirAviao(&Hangar);

    /* Liberando um elemento da pilha */
    int pos;

    printf("Deseja liberar o aviao de qual posicao? ");
    scanf("%d", &pos);
    liberaAviao(&Hangar, Hangar.tamanho - (pos - 1));

    imprimirAviao(&Hangar);

    return 0;
}
