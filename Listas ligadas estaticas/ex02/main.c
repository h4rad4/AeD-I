#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define N 10

int main(int argc, char const *argv[])
{
    Lista lista1;
    inicializarLista(&lista1);

    inserirElemento(&lista1, 1);
    inserirElemento(&lista1, 2);
    inserirElemento(&lista1, 3);

    printf("Lista 1: ");
    exibirLista(lista1);

    Lista lista2;
    inicializarLista(&lista2);

    // Copiar lista1 para lista2
    copiarLista(&lista1, &lista2);
    printf("Lista 2 (copia de lista 1): ");
    exibirLista(lista2);

    Lista lista3;
    inicializarLista(&lista3);

    inserirElemento(&lista3, 4);
    inserirElemento(&lista3, 5);
    inserirElemento(&lista3, 6);

    printf("Lista 3: ");
    exibirLista(lista3);

    Lista novaListaA = percorrerListaA(lista1);
    printf("Nova lista (a): ");
    exibirLista(novaListaA);

    Lista novaListaB = percorrerListaB(lista2);
    printf("Nova lista (b): ");
    exibirLista(novaListaB);

    // Concatenar lista1 com lista2
    concatenarListas(&lista1, &lista2);
    printf("Lista apos concatenacao: ");
    exibirLista(lista1);

    // Intercalar lista1 e lista3
    Lista listaIntercalada = intercalarListas(&lista1, &lista3);
    printf("Lista Intercalada (lista1 e lista3): ");
    exibirLista(listaIntercalada);

    return 0;
}