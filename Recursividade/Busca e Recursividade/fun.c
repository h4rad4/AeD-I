#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

lista *criaVetor(lista *p, int n)
{
    lista Lista;

    srand(time(NULL));
    p->n = n;
    p = malloc(sizeof(lista));
    p->vetor = (int *)malloc(n * sizeof(int));

    if (p == NULL)
        return 0;
    else
    {

        printf("Preenchendo o vetor com valores aleatorios... \n");

            for (int i = 0; i < n; i++)
            {
                p->vetor[i] = rand() % 100;
            }

            for (int i = 0; i < n; i++)
            {
                printf("\t%d\t", p->vetor[i]);
            }

        buscaVetor(p, n);

        return p;
    }
}

void buscaVetor(lista *p, int size)
{
    int n, i =0;

    printf("\nQual valor deseja buscar no vetor? ");
    scanf("%d", &n);

    for (int i = 0; i < size; i++)
    {
        
    }
        
}
