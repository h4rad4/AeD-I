#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[50];
    int idade;
    int numFilhos;
} Aluno;

typedef struct Node
{
    Aluno aluno;
    struct Node *proximo;
} Node;

typedef struct
{
    Node *primeiro;
    int tamanho;
} Lista;

void criarLista(Lista *lista)
{
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

void inserirElemento(Lista *lista, Aluno aluno)
{
    Node *novoElemento = (Node *)malloc(sizeof(Node));
    novoElemento->aluno = aluno;
    novoElemento->proximo = NULL;

    if (lista->primeiro == NULL)
    {
        lista->primeiro = novoElemento;
    }
    else
    {
        Node *atual = lista->primeiro;

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }

        atual->proximo = novoElemento;
    }

    lista->tamanho++;
}

int obterQuantidadeElementos(Lista *lista)
{
    return lista->tamanho;
}

int buscarElemento(Lista *lista, int codigo)
{
    Node *atual = lista->primeiro;
    int posicaoAtual = 0;

    while (atual != NULL)
    {
        if (atual->aluno.codigo == codigo)
        {
            return posicaoAtual;
        }

        atual = atual->proximo;
        posicaoAtual++;
    }

    return -1;
}

void excluirElemento(Lista *lista, int codigo)
{
    if (lista->primeiro == NULL)
    {
        printf("Lista esta vazia. Não e possivel excluir o elemento.\n");
        return;
    }

    Node *atual = lista->primeiro;
    Node *elementoAnterior = NULL;

    while (atual != NULL && atual->aluno.codigo != codigo)
    {
        elementoAnterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (elementoAnterior == NULL)
        {
            lista->primeiro = atual->proximo;
        }
        else
        {
            elementoAnterior->proximo = atual->proximo;
        }

        free(atual);
        lista->tamanho--;

        printf("Aluno com codigo %d excluido da lista.\n", codigo);
    }
    else
    {
        printf("Aluno não encontrado.\n");
    }
}

void imprimirLista(Lista *lista)
{
    printf("Lista de Alunos:\n");
    Node *atual = lista->primeiro;

    while (atual != NULL)
    {
        Aluno aluno = atual->aluno;
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               aluno.codigo, aluno.nome, aluno.idade, aluno.numFilhos);

        atual = atual->proximo;
    }

    printf("\n");
}

int main()
{
    Lista lista;
    criarLista(&lista);

    Aluno aluno1 = {1, "João Silva", 20, 0};
    Aluno aluno2 = {2, "Maria Santos", 22, 1};

    inserirElemento(&lista, aluno1);
    inserirElemento(&lista, aluno2);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 2);
    if (posicao != -1)
    {
        printf("Aluno com código 2 encontrado na posição %d\n", posicao);
    }
    else
    {
        printf("Aluno com código 2 não encontrado na lista\n");
    }

    excluirElemento(&lista, 2);

    imprimirLista(&lista);

    printf("Quantidade de alunos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}