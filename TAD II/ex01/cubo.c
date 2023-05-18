/*
---------------------------------------------------------------------------------------------
Desenvolva um TAD que represente um cubo. Inclua as funções de inicializações necessárias e
as operações que retornem os tamanhos de cada lado, a sua área e o seu volume
---------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "header.h"

int main(int argc, char const *argv[])
{
    Cubo cubo;

    dadosCubo(&cubo);

    double lado = cuboLado(&cubo);
    double area = cuboArea(&cubo);
    double volume = cuboVolume(&cubo);

    printf("\nLado = %.2lf \n", lado);
    printf("Area = %.2lf \n", area);
    printf("Volume = %.2lf \n", volume);

    return 0;
}