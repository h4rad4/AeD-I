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

    float lado = cuboLado(&cubo);
    float area = cuboArea(&cubo);
    float volume = cuboVolume(&cubo);

    printf("\nLado = %.2f \n", lado);
    printf("Area = %.2f \n", area);
    printf("Volume = %.2f \n", volume);

    return 0;
}

void dadosCubo(Cubo *cubo)
{
    float size;

    printf("Insira valor do lado do cubo. ");
    scanf("%f", &size);

    cubo -> lado = size;
}

float cuboLado(Cubo *cubo)
{
    return cubo -> lado;
}

float cuboArea(Cubo *cubo)
{
    return 6 * pow(cubo -> lado, 2);
}

float cuboVolume(Cubo *cubo)
{
    return pow(cubo -> lado, 3);
}
