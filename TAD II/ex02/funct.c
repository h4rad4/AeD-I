#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Complexo *criarComplexo(int real, int img)
{
    Complexo *complexo = (Complexo *)malloc(sizeof(Complexo));
    complexo->real = real;
    complexo->img = img;

    return complexo;
}

void destruirComplexo(Complexo *complexo)
{
    free(complexo);
}

Complexo *somarComplexos(Complexo *z1, Complexo *z2)
{
    int real = z1->real + z2->real;
    int img = z1->img + z2->img;
    return criarComplexo(real, img);
}

Complexo *subtrairComplexos(Complexo *z1, Complexo *z2)
{
    int real = z1->real - z2->real;
    int img = z1->img - z2->img;
    return criarComplexo(real, img);
}

Complexo *multiplicarComplexos(Complexo *z1, Complexo *z2)
{
    int real = (z1->real * z2->real) - (z1->img * z2->img);
    int img = (z1->real * z2->img) + (z1->img * z2->real);
    return criarComplexo(real, img);
}

Complexo *dividirComplexos(Complexo *z1, Complexo *z2)
{
    int divisor = (z2->real * z2->real) + (z2->img * z2->img);
    int real = ((z1->real * z2->real) + (z1->img * z2->img)) / divisor;
    int img = ((z1->img * z2->real) - (z1->real * z2->img)) / divisor;
    return criarComplexo(real, img);
}
