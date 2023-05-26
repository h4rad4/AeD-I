#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    lista Lista;
    int n;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%i", &n);

    criaVetor(&Lista, n);
    criaVetor2(&Lista, n);

    return 0;
}
