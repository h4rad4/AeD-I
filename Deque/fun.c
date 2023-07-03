#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializar(DEQUE *turma)
{
    turma->cabeca = malloc(sizeof(Node));
    turma->cabeca->proximo = turma->cabeca;
    turma->cabeca->anterior = turma->cabeca;
    turma->tamanho = 0;
}

void inserirInicio(DEQUE *turma, Aluno novo)
{
    Node *temp;
    temp = malloc(sizeof(Node));
    temp->aluno = novo;
    temp->proximo = turma->cabeca->proximo;
    temp->anterior = turma->cabeca;
    turma->cabeca->proximo = temp;
    temp->proximo->anterior = temp;
    turma->tamanho++;
}

void inserirFim(DEQUE *turma, Aluno novo)
{
    Node *temp;
    temp = malloc(sizeof(Node));
    temp->aluno = novo;
    temp->proximo = turma->cabeca;
    temp->anterior = turma->cabeca->anterior;
    turma->cabeca->anterior = temp;
    temp->anterior->proximo = temp;
    turma->tamanho++;
}

void imprimir(DEQUE turma, char ordem, int pos)
{
    Node *atual = turma.cabeca->proximo;

    int j = 0;

    if (ordem == 'd')
    {
        Node *atual = turma.cabeca->proximo;
        printf("\nDeque a partir da posicao %d, em ordem DIRETA:\n", pos);
        while (atual != turma.cabeca)
        {
            if (j < pos)
                atual = atual->proximo;

            else
            {
                printf("%s\n", atual->aluno.nome);
                atual = atual->proximo;
            }
            j++;
        }
    }
    else if (ordem == 'i')
    {
        Node *atual = turma.cabeca->anterior;
        printf("\nDeque a partir da posicao %d, em ordem INVERSA: \n", pos);
        while (atual != turma.cabeca)
        {
            if (j < turma.tamanho - pos - 1)
                atual = atual->anterior;

            else
            {
                printf("%s\n", atual->aluno.nome);
                atual = atual->anterior;
            }
            j++;
        }
    }
    else
        printf("invalido.");
}
