#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    HANGAR Hangar;
    inicializarHangar(&Hangar);

    AVIAO Avioes[9] =
        {
            {"LILY", 1},
            {"TULIP", 2},
            {"ROSE", 3},
            {"DANDELION", 4},
            {"GARDENIA", 5},
            {"ORCHID", 6},
            {"LAVENDER", 7},
            {"DAISY", 8},
            {"POPPY", 9}};

    for (int i = 0; i < 9; i++)
        inserirAviao(&Hangar, Avioes[i]);

    imprimirAviao(&Hangar);

    return 0;
}
