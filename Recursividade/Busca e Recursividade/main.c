#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    lista Lista;

    int n;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%i", &n);

    lista *v = criaVetor(&Lista, n, 30);

    return 0;
}
