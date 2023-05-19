/*
-----------------------------------------------------------------------------------------------------------
Desenvolva um TAD que represente um número complexo z = x + iy, em que i² = –1, sendo x a sua parte real
e y a parte imaginária. O TAD deverá conter as seguintes funções:

1- criar um número complexo;
2- destruir um número complexo;
3- soma de dois números complexos;
4- subtração de dois números complexos;
5- multiplicação de dois números complexos;
6- divisão de dois números complexos.
-----------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    int real;
    int img;

    printf("Insira a parte real: ");
    scanf("%i", &real);

    printf("Insira a parte imaginaria: ");
    scanf("%i", &img);

    Complexo *z1 = criarComplexo(real, img);
    Complexo *z2 = criarComplexo(real, img);

    Complexo *soma = somarComplexos(z1, z2);
    printf("Soma: %i + %ii\n", soma->real, soma->img);
    destruirComplexo(soma);

    Complexo *subtracao = subtrairComplexos(z1, z2);
    printf("Subtracao: %i + %ii\n", subtracao->real, subtracao->img);
    destruirComplexo(subtracao);

    Complexo *multiplicacao = multiplicarComplexos(z1, z2);
    printf("Multiplicacao: %i + %ii\n", multiplicacao->real, multiplicacao->img);
    destruirComplexo(multiplicacao);

    Complexo *divisao = dividirComplexos(z1, z2);
    printf("Divisao: %i + %ii\n", divisao->real, divisao->img);
    destruirComplexo(divisao);

    destruirComplexo(z1);
    destruirComplexo(z2);

    return 0;
}