#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    Arvore *raiz = NULL;

    int valor[] = {55, 12, 99, 42, 87, 63, 28, 19, 76, 200, 15};
    int quantidade = sizeof(valor) / sizeof(int);

    for (int i = 0; i < quantidade; i++)
        inserir(&raiz, valor[i]);

    printf("[Arvore]: ");
    imprimirArvore(raiz);

    int excluido = 20;
    excluir(&raiz, excluido);

    printf("\n[Arvore apos exclusao]: ");
    imprimirArvore(raiz);

    printf("\n\nFolhas da arvore: \n");
    imprimirFolhas(raiz);
    printf("\n\n");

    int busca = 10;
    printf("\nBuscando elemento %d...\n", busca);

    if (buscar(raiz, busca))
        printf("O elemento %d foi encontrado na arvore.", busca);
    else
        printf("O elemento %d nao foi encontrado na arvore.", busca);

    busca = 12;
    printf("\nBuscando elemento %d...\n", busca);

    if (buscar(raiz, busca))
        printf("O elemento %d foi encontrado na arvore.\n", busca);
    else
        printf("O elemento %d nao encontrada na arvore.\n", busca);

    return 0;
}
