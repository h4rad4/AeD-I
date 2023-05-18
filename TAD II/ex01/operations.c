#include "header.h"
#include <math.h>
#include <stdio.h>

void dadosCubo(Cubo *cubo)
{
    printf("Insira valor do lado do cubo. ");
    scanf("%lf", &(cubo -> lado));
}

double cuboLado(Cubo *cubo)
{
    return cubo -> lado;
}

double cuboArea(Cubo *cubo)
{
    return 6*pow(cubo -> lado, 2);
}

double cuboVolume(Cubo *cubo)
{
    return pow(cubo -> lado, 3);
}
