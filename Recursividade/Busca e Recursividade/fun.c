#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

lista *criaVetor(lista *p)
{
    int n;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%i", &n);

    p -> n = n;
    p = malloc(sizeof(lista));
    p -> vetor = (int *)malloc(n * sizeof(int));
    p -> vetor2 = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    if (p == NULL)
        return 0;
    else
    {
        printf("Preenchendo o vetor [1] com valores aleatorios... \n");

        for (int i = 0; i < n; i++) 
            p->vetor[i] = rand() % 100; // ATRIBUINDO VALORES ALEATÓRIOS AO VETOR

        for (int i = 0; i < n - 1; i++) // ORDENANDO O VETOR
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (p->vetor[j] > p->vetor[j + 1])
                {
                    int temp = p->vetor[j];
                    p->vetor[j] = p->vetor[j + 1];
                    p->vetor[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) // IMPRIMINDO O VETOR
            printf("%d\t", p->vetor[i]);


        printf("\nPreenchendo o vetor [2] com valores aleatorios... \n");

        for (int i = 0; i < 30; i++)
            p -> vetor2[i] = rand() % 100; // ATRIBUINDO VALORES ALEATÓRIOS AO VETOR

        for (int i = 0; i < n - 1; i++) // ORDENANDO O VETOR
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if(p -> vetor2[j] > p -> vetor2[j+1])
                {
                    int temp = p -> vetor[j];
                    p -> vetor2[j] = p -> vetor2[j+1];
                    p -> vetor2[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) // IMPRIMINDO O VETOR
            printf("%d\t", p->vetor2[i]);
    }

    return p;
}


int buscaSequencial(lista *p, int size)
{
    int n;

    printf("\nQual valor deseja buscar no vetor? ");
    scanf("%d", &n);

    for (int i = 0; i < size; i++)
    {
        if (p->vetor[i] == n)
        {
            printf("Localizado na posicao [%i] do 'vetor 1'.\n", i);
            return 1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (p->vetor2[i] == n)
        {
            printf("Localizado na posicao [%i] do 'vetor 2'.\n", i);
            return 1;
        }
    }

    return 0;
}
