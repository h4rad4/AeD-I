#include "main.h"

int main()
{
    Lista lista;
    criarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 10);
    if (posicao != -1)
    {
        printf("Elemento encontrado na posicao %d\n", posicao);
    }
    else
    {
        printf("Elemento nao encontrado na lista\n");
    }

    excluirElemento(&lista, 10);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}
