#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
    struct Node *proximo;
} Node;

typedef struct
{
    Node *inicio;
    int tamanho;
} Lista;

void criarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirElemento(Lista *lista, int elemento)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = elemento;
    novoNo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
    }
    else
    {
        Node *atual = lista->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }

        atual->proximo = novoNo;
    }

    lista->tamanho++;
}

void inserirElementoOrdenado(Lista *lista, int elemento)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = elemento;
    novoNo->proximo = NULL;

    if (lista->inicio == NULL || elemento < lista->inicio->valor)
    {
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho++;
        return;
    }

    Node *anterior = lista->inicio;
    Node *atual = lista->inicio->proximo;

    while (atual != NULL && atual->valor < elemento)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novoNo;
    novoNo->proximo = atual;
    lista->tamanho++;
}

int obterQuantidadeElementos(Lista *lista)
{
    return lista->tamanho;
}

int buscarElemento(Lista *lista, int elemento)
{
    Node *atual = lista->inicio;
    int posicao = 0;

    while (atual != NULL)
    {
        if (atual->valor == elemento)
        {
            return posicao;
        }

        atual = atual->proximo;
        posicao++;
    }

    return -1;
}

void excluirElementoPorPosicao(Lista *lista, int posicao)
{
    if (posicao < 0 || posicao >= lista->tamanho)
    {
        return;
    }

    Node *atual = lista->inicio;
    Node *anterior = NULL;

    for (int i = 0; i < posicao; i++)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL)
    {
        lista->inicio = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->tamanho--;
}

void excluirElemento(Lista *lista, int elemento)
{
    Node *atual = lista->inicio;
    Node *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->valor == elemento)
        {
            if (anterior == NULL)
            {
                lista->inicio = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            lista->tamanho--;
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }
}

void imprimirLista(Lista *lista)
{
    Node *atual = lista->inicio;

    printf("Elementos da lista:");

    while (atual != NULL)
    {
        printf(" %d", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void liberarLista(Lista *lista)
{
    Node *atual = lista->inicio;

    while (atual != NULL)
    {
        Node *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main()
{
    Lista lista;
    criarLista(&lista);

    // Inserir elementos sem importar a ordem
    inserirElemento(&lista, 30);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 50);
    inserirElemento(&lista, 20);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    printf("Elementos da lista: ");
    imprimirLista(&lista);

    // Inserir elemento de forma ordenada
    inserirElementoOrdenado(&lista, 40);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    printf("Elementos da lista: ");
    imprimirLista(&lista);

    // Buscar elemento sequencialmente
    int posicao = buscarElemento(&lista, 30);
    if (posicao != -1)
    {
        printf("Elemento 30 encontrado na posicao %d\n", posicao);
    }
    else
    {
        printf("Elemento 30 nao encontrado na lista\n");
    }

    // Excluir elemento por valor
    excluirElemento(&lista, 20);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    printf("Elementos da lista: ");
    imprimirLista(&lista);

    liberarLista(&lista);

    return 0;
}
