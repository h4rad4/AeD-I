#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTOS 100

typedef struct
{
    int codigo;
    char nome[50];
    int idade;
    int numFilhos;
    int proximo;
} Aluno;

typedef struct
{
    Aluno elementos[MAX_ELEMENTOS];
    int primeiro;
    int proximo;
    int tamanho;
} Lista;

void criarLista(Lista *lista)
{
    lista->primeiro = -1;
    lista->proximo = 0;
    lista->tamanho = 0;

    for (int i = 0; i < MAX_ELEMENTOS - 1; i++)
    {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_ELEMENTOS - 1].proximo = -1;
}

void inserirAluno_Nao_Ordenado(Lista *lista, Aluno novo_aluno)
{
    if (lista->proximo != -1)
    {
        int atual = lista->proximo;
        lista->proximo = lista->elementos[atual].proximo;
        lista->elementos[atual] = novo_aluno;

        if (lista->primeiro == -1)
        {
            lista->primeiro = atual;
            lista->elementos[atual].proximo = -1;
        }
        else
        {
            int posicaoAtual = lista->primeiro;
            int posicaoAnterior = -1;

            while (posicaoAtual != -1)
            {
                posicaoAnterior = posicaoAtual;
                posicaoAtual = lista->elementos[posicaoAtual].proximo;
            }

            lista->elementos[posicaoAnterior].proximo = atual;
            lista->elementos[atual].proximo = -1;
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

int buscarElemento(Lista *lista, int codigo)
{
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1)
    {
        if (lista->elementos[posicaoAtual].codigo == codigo)
        {
            return posicaoAtual;
        }
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    return -1;
}

void excluirElemento(Lista *lista, int codigo)
{
    int posicaoAtual = lista->primeiro;
    int posicaoAnterior = -1;

    while (posicaoAtual != -1 && lista->elementos[posicaoAtual].codigo != codigo)
    {
        posicaoAnterior = posicaoAtual;
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    if (posicaoAtual != -1)
    {
        if (posicaoAnterior == -1)
        {
            lista->primeiro = lista->elementos[posicaoAtual].proximo;
        }
        else
        {
            lista->elementos[posicaoAnterior].proximo = lista->elementos[posicaoAtual].proximo;
        }

        lista->elementos[posicaoAtual].proximo = lista->proximo;
        lista->proximo = posicaoAtual;
        lista->tamanho--;

        printf("Aluno com código %d excluído da lista.\n", codigo);
    }
    else
    {
        printf("Aluno não encontrado.\n");
    }
}

void imprimirLista(Lista *lista)
{
    printf("Lista de Alunos:\n");
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1)
    {
        Aluno aluno = lista->elementos[posicaoAtual];
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               aluno.codigo, aluno.nome, aluno.idade, aluno.numFilhos);
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    printf("\n");
}

int main()
{
    Lista lista;
    criarLista(&lista);

    Aluno aluno1 = {1, "Joao Silva", 20, 0, -1};
    Aluno aluno2 = {2, "Maria Santos", 22, 1, -1};

    inserirAluno_Nao_Ordenado(&lista, aluno1);
    inserirAluno_Nao_Ordenado(&lista, aluno2);

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
