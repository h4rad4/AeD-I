#include <stdio.h>
#include <stdlib.h>
#include "main.h"

lista *criaVetor(int n)
{
    lista *p; // ponteiro para a lista

    p = malloc(n* sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Insira o elemento %i do vetor.");
        scanf("%d", *(p + i));
    }
    
    return p;
}
