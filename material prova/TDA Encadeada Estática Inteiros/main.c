#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 100

typedef struct
{
    int valor;
    int proximo;
} Node;

typedef struct
{
    Node elementos[MAX_ELEMENTOS];
    int *primeiro;
    int *proximo;
    int tamanho;
} Lista;

void criarLista(Lista *lista)
{
    lista->primeiro = NULL;
    lista->proximo = &lista->elementos[0].proximo;
    lista->tamanho = 0;

    for (int i = 0; i < MAX_ELEMENTOS - 1; i++)
    {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_ELEMENTOS - 1].proximo = NULL;
}

void inserirElemento(Lista *lista, int valor)
{
    if (lista->proximo != NULL)
    {
        int *posicaoInserir = lista->proximo;
        lista->proximo = &lista->elementos[*posicaoInserir].proximo;
        lista->elementos[*posicaoInserir].valor = valor;

        if (lista->primeiro == NULL)
        {
            lista->primeiro = posicaoInserir;
            lista->elementos[*posicaoInserir].proximo = NULL;
        }
        else
        {
            int *posicaoAtual = lista->primeiro;
            int *posicaoAnterior = NULL;

            while (posicaoAtual != NULL && lista->elementos[*posicaoAtual].valor < valor)
            {
                posicaoAnterior = posicaoAtual;
                posicaoAtual = &lista->elementos[*posicaoAtual].proximo;
            }

            if (posicaoAnterior == NULL)
            {
                lista->elementos[*posicaoInserir].proximo = lista->primeiro;
                lista->primeiro = posicaoInserir;
            }
            else
            {
                lista->elementos[*posicaoInserir].proximo = lista->elementos[*posicaoAnterior].proximo;
                lista->elementos[*posicaoAnterior].proximo = posicaoInserir;
            }
        }

        lista->tamanho++;
    }
    else
    {
        printf("Lista está cheia. Não é possível inserir o elemento.\n");
    }
}

int obterQuantidadeElementos(Lista *lista)
{
    return lista->tamanho;
}

int buscarElemento(Lista *lista, int valor)
{
    int *posicaoAtual = lista->primeiro;

    while (posicaoAtual != NULL)
    {
        if (lista->elementos[*posicaoAtual].valor == valor)
        {
            return *posicaoAtual;
        }
        posicaoAtual = &lista->elementos[*posicaoAtual].proximo;
    }

    return NULL;
}

void excluirElemento(Lista *lista, int valor)
{
    int *posicaoAtual = lista->primeiro;
    int *posicaoAnterior = NULL;

    while (posicaoAtual != NULL && lista->elementos[*posicaoAtual].valor != valor)
    {
        posicaoAnterior = posicaoAtual;
        posicaoAtual = &lista->elementos[*posicaoAtual].proximo;
    }

    if (posicaoAtual != NULL)
    {
        if (posicaoAnterior == NULL)
        {
            lista->primeiro = lista->elementos[*posicaoAtual].proximo;
        }
        else
        {
            lista->elementos[*posicaoAnterior].proximo = lista->elementos[*posicaoAtual].proximo;
        }

        lista->elementos[*posicaoAtual].proximo = lista->proximo;
        lista->proximo = posicaoAtual;
        lista->tamanho--;

        printf("Elemento %d excluído da lista.\n", valor);
    }
    else
    {
        printf("Elemento não encontrado.\n");
    }
}

void imprimirLista(Lista *lista)
{
    printf("Lista: ");
    int *posicaoAtual = lista->primeiro;

    while (posicaoAtual != NULL)
    {
        printf("%d ", lista->elementos[*posicaoAtual].valor);
        posicaoAtual = &lista->elementos[*posicaoAtual].proximo;
    }

    printf("\n");
}

int main()
{
    Lista lista;
    criarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 10);
    if (posicao != NULL)
    {
        printf("Elemento 10 encontrado na posição %d\n", posicao);
    }
    else
    {
        printf("Elemento 10 não encontrado na lista\n");
    }

    excluirElemento(&lista, 10);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}
