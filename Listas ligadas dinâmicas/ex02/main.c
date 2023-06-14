#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    Lista *P1 = (Lista *)malloc(sizeof(Lista));
    P1->inicio = NULL;

    Lista *P2 = (Lista *)malloc(sizeof(Lista));
    P2->inicio = NULL;

    P1 = criarPolinomio(P1, 3, 5);
    P1 = criarPolinomio(P1, 2, 1);
    P1 = criarPolinomio(P1, -1, 0);

    P2 = criarPolinomio(P2, 6, 1);
    P2 = criarPolinomio(P2, 12, 0);
    //P2 = criarPolinomio(P2, 4, 0);



    Lista *result = somaPolinomio(P1, P2);
    
    imprimirPolinomio(result);

    return 0;
}
