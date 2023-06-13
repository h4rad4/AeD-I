#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define size 10

int main(int argc, char const *argv[])
{
    Node *head = NULL;

    for (int i = 0; i < size; i++)
    {
        // Preenchando a lista com valores randômicos
        inserirInicioLista(&head, rand() % 100);
    }

    imprimirLista(head);

    return 0;
}