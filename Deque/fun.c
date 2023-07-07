#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializar(Deque *turma)
{
    turma->head = malloc(sizeof(Node));
    turma->head->proximo = turma->head;
    turma->head->anterior = turma->head;
    turma->tamanho = 0;
}

void inserirInicio(Deque *turma, Aluno novo)
{
    Node *temp;
    temp = malloc(sizeof(Node));
    temp->aluno = novo;
    temp->proximo = turma->head->proximo;
    temp->anterior = turma->head;
    turma->head->proximo = temp;
    temp->proximo->anterior = temp;
    turma->tamanho++;
}

void inserirFim(Deque *turma, Aluno novo)
{
    Node *temp;
    temp = malloc(sizeof(Node));
    temp->aluno = novo;
    temp->proximo = turma->head;
    temp->anterior = turma->head->anterior;
    turma->head->anterior = temp;
    temp->anterior->proximo = temp;
    turma->tamanho++;
}

void imprimir(Deque turma, char ordem, int pos)
{
    Node *atual = turma.head->proximo;

    int j = 0;

    if (ordem == 'd')
    {
        Node *atual = turma.head->proximo;
        printf("\nDeque a partir da posicao %d, em ordem DIRETA:\n", pos);
        while (atual != turma.head)
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
        Node *atual = turma.head->anterior;
        printf("\nDeque a partir da posicao %d, em ordem INVERSA: \n", pos);
        while (atual != turma.head)
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
