#include "header.h"
#include <math.h>
#include <stdio.h>

void dadosCubo(Cubo *cubo)
{
    printf("Insira valor do lado do cubo. ");
    scanf("%f", &(cubo -> lado));
}

float cuboLado(Cubo *cubo)
{
    return cubo -> lado;
}

float cuboArea(Cubo *cubo)
{
    return 6*pow(cubo -> lado, 2);
}

float cuboVolume(Cubo *cubo)
{
    return pow(cubo -> lado, 3);
}
