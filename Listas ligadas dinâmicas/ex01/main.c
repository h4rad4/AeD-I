#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define size 10

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *listaK;

    for (int i = 0; i < size; i++)
    {
        // Preenchendo a lista com valores randômicos
        head = inserirInicioLista(head, rand() % 100);
    }

    imprimirLista(head);

    printf("\nOrdenando lista...\n");
    criarListaOrdenada(head, &listaK);

    imprimirLista(listaK);

    return 0;
}