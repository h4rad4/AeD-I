#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *elementos;
    int tamanho;
    int capacidade;
} Lista;

void criarLista(Lista *lista, int capacidade)
{
    lista->elementos = (int *)malloc(capacidade * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void inserirElementoSemOrdem(Lista *lista, int elemento)
{
    if (lista->tamanho < lista->capacidade)
    {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
    }
    else
    {
        printf("Lista está cheia. Não é possível inserir o elemento.\n");
    }
}

void inserirElementoOrdenado(Lista *lista, int elemento)
{
    if (lista->tamanho < lista->capacidade)
    {
        int indice = lista->tamanho - 1;
        while (indice >= 0 && lista->elementos[indice] > elemento)
        {
            lista->elementos[indice + 1] = lista->elementos[indice];
            indice--;
        }
        lista->elementos[indice + 1] = elemento;
        lista->tamanho++;
    }
    else
    {
        printf("Lista está cheia. Não é possível inserir o elemento.\n");
    }

    // 10, 20, 30, 40 (inserir 25):
    // 10, 20, 30, 40, 40
    // 10, 20, 30, 30, 40
    // 10, 20, 25, 30, 40 
}

int obterQuantidadeElementos(Lista *lista)
{
    return lista->tamanho;
}

int buscarElementoSequencial(Lista *lista, int elemento)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->elementos[i] == elemento)
        {
            return i;
        }
    }
    return -1;
}

int buscarElementoBinario(Lista *lista, int elemento)
{
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == elemento)
        {
            return meio;
        }
        else if (lista->elementos[meio] < elemento)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
}

void excluirElementoPorPosicao(Lista *lista, int posicao)
{
    if (posicao >= 0 && posicao < lista->tamanho)
    {
        for (int i = posicao; i < lista->tamanho - 1; i++)
        {
            lista->elementos[i] = lista->elementos[i + 1];
        }
        lista->tamanho--;
    }
    else
    {
        printf("Posição inválida.\n");
    }
}

void excluirElementoPorValor(Lista *lista, int elemento)
{
    int posicao = buscarElementoSequencial(lista, elemento);
    if (posicao != -1)
    {
        excluirElementoPorPosicao(lista, posicao);
    }
    else
    {
        printf("Elemento não encontrado.\n");
    }
}

void imprimirLista(Lista *lista)
{
    printf("Lista: ");
    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int main()
{
    Lista lista;
    criarLista(&lista, 10);

    inserirElementoSemOrdem(&lista, 5);
    inserirElementoSemOrdem(&lista, 10);
    inserirElementoSemOrdem(&lista, 15);
    inserirElementoOrdenado(&lista, 12);
    inserirElementoOrdenado(&lista, 13);

    imprimirLista(&lista);

    int posicao = buscarElementoSequencial(&lista, 10);
    if (posicao != -1)
    {
        printf("Elemento 10 encontrado na posição %d\n", posicao);
    }
    else
    {
        printf("Elemento 10 não encontrado na lista\n");
    }

    excluirElementoPorValor(&lista, 10);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}
