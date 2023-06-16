#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
    struct Node *next;

} Node;

typedef struct
{
    Node *inicio;
    int tamanho;

} Lista;

void inicializarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirElemento(Lista *lista, int elemento)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->valor = elemento;
    novoNo->next = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
    }
    else
    {
        Node *atual = lista->inicio;
        while (atual->next != NULL)
        {
            atual = atual->next;
        }

        atual->next = novoNo;
    }

    lista->tamanho++;
}

void removerElemento(Lista *lista, int elemento)
{
    if (lista->inicio == NULL)
    {
        return;
    }

    Node *anterior = NULL;
    Node *atual = lista->inicio;

    while (atual != NULL)
    {
        if (atual->valor == elemento)
        {
            if (anterior == NULL)
            {
                lista->inicio = atual->next;
            }
            else
            {
                anterior->next = atual->next;
            }

            free(atual);
            lista->tamanho--;
            
            return;
        }

        anterior = atual;
        atual = atual->next;
    }
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

        atual = atual->next;
        posicao++;
    }

    return -1;
}

int main()
{
    Lista lista;
    inicializarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    printf("Lista: ");
    Node *atual = lista.inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\n");

    removerElemento(&lista, 10);

    printf("Lista apos a remocao: ");
    atual = lista.inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\n");

    int posicao = buscarElemento(&lista, 5);
    if (posicao != -1)
    {
        printf("Elemento 5 encontrado na posicao %d\n", posicao);
    }
    else
    {
        printf("Elemento 5 não encontrado na lista\n");
    }

    return 0;
}
