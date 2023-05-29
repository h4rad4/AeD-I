#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    lista *v1, *v2;
    int n, value;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%i", &n);

    v1 = criaVetor(n);
    preencherVetor(v1);

    printf("\n");
    printVetor(v1);

    printf("\n");
    imprimirMaiorElemento(v1);
    imprimirMenorElemento(v1);
    imprimirSomaElementos(v1);
    imprimirProdutoElementos(v1);

    printf("\n\nGerando vetor ordenado de 30 elementos... \n");

    v2 = criaVetor(30);
    preencherVetorOrdenado(v2);
    printVetor(v2);

    printf("\n\n- Qual valor deseja procurar na lista? ");
    scanf("%d", &value);

    int cont = 0;
    int result = buscaSequencial(v2, value, &cont);
    printf("\n-> Busca sequencial: Encontrado na posicao %d. \n Total de lacos: %d", result, cont);

    cont = 0;
    result = buscaSequencialOrdenada(v2, value, &cont);
    printf("\n-> Busca sequencial ordenada: Encontrado na posicao %d. \n Total de lacos: %d", result, cont);

    cont = 0;
    result = buscaBinariaIterativa(v2, value, &cont);
    printf("\n-> Busca binaria iterativa: Encontrado na posicao %d. \n Total de lacos: %d", result, cont);

    cont = 0;
    result = buscaBinariaRecursiva(v2, value, 0, 30 - 1, &cont);
    printf("\n-> Busca binaria recursiva: Encontrado na posicao %d. \nTotal de lacos: %d", result, cont);

    return 0;
}
