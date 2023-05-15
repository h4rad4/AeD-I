/*
---------------------------------------------------------------------------------------------
Desenvolva um TAD que represente um cubo. Inclua as funções de inicializações necessárias e 
as operações que retornem os tamanhos de cada lado, a sua área e o seu volume
---------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "header.h"
#include "operations.c"

int main(int argc, char const *argv[])
{
    Cubo cubo;

    dadosCubo(&cubo);

    float lado = cuboLado(&cubo);
    float area = cuboArea(&cubo);
    float volume = cuboVolume(&cubo);

    printf("Lado = %.2f \n", lado);
    printf("Area = %.2f \n", area);
    printf("Volume = %.2f \n", volume);

    return 0;
}

// AINDA INCOMPLETO