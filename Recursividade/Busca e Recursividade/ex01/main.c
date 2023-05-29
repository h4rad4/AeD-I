#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    lista *v1, *v2;
    int cont;
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

    printf("\n-> Busca sequencial: Encontrado na posicao %d. \n Total de laços: %d", buscaSequencial(v2, value, &cont), cont);
    printf("\n-> Busca sequencial ordenada: Encontrado na posicao %d \n Total de laços: %d", buscaSequencialOrdenada(v2, value, &cont), cont);
    printf("\n-> Busca binaria iterativa: Encontrado na posicao %d \n Total de laços: %d", buscaBinariaIterativa(v2, value, &cont), cont);
    printf("\n-> Busca binaria recursiva: Encontrado na posicao %d", buscaBinariaRecursiva(v2, value, 0, 30-1));
    
    return 0;
}
