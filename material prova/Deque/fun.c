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

void exibirDequeFim(Deque *d)
{
    Node *fim = d->head->anterior;
    printf("Deque partindo do fim:");

    while (fim != d->head)
    {
        printf("%s \n", fim->aluno.nome);
        fim = fim->anterior;
    }
}

void exibirDequeInicio(Deque *d)
{
    Node *fim = d->head->proximo;
    printf("Deque partindo do inicio:");

    while (fim != d->head)
    {
        printf("%s \n", fim->aluno.nome);
        fim = fim->proximo;
    }
}

int inserirDequeFim(Deque *d, Aluno aluno)
{
    // Cria um novo nó e aloca memória para ele
    Node *novoNo = malloc(sizeof(Aluno));
    // Atribui o aluno ao novo nó
    novoNo->aluno = aluno;
    // O próximo nó do novo nó será o head do deque
    novoNo->proximo = d->head;
    // O nó anterior do novo nó será o nó anterior ao head do deque
    novoNo->anterior = d->head->anterior;
    // O nó anterior ao head do deque será o novo nó
    d->head->anterior = novoNo;
    // O próximo nó do nó anterior ao head do deque será o novo nó
    d->head->anterior->proximo = novoNo;

    return 1;
}

int inserirDequeInicio(Deque *d, Aluno aluno)
{
    Node *novoNo = malloc(sizeof(Aluno));
    novoNo->aluno = aluno;

    novoNo->proximo = d->head->proximo;
    novoNo->anterior = d->head;

    d->head->proximo->anterior = novoNo;
    d->head->proximo = novoNo;

    return 1;
}

int excluirDequeInicio(Deque *d, Aluno *aluno)
{
    // Verifica se o deque está vazio
    if (d->head->proximo == d->head)
        return 0;

    Node *apagar = d->head->proximo;
    *aluno = apagar->aluno; // Copia o aluno do nó a ser removido

    // Atualiza os ponteiros
    d->head->proximo = apagar->proximo;
    apagar->proximo->anterior = d->head;
    free(apagar);

    return 1;
}

int excluirDequeFim(Deque *d, Aluno *aluno)
{
    // Verifica se o deque está vazio
    if (d->head->anterior == d->head)
        return 0;

    Node *apagar = d->head->anterior;
    *aluno = apagar->aluno; // Copia o aluno do nó a ser removido

    // Atualiza os ponteiros
    d->head->anterior = apagar->anterior;
    apagar->anterior->proximo = d->head;
    free(apagar);

    return 1;
}

void reinicializarDeque(Deque *d)
{
    Node *fim = d->head->proximo;

    while (fim != d->head)
    {
        Node *apagar = fim;
        fim = fim->proximo;
        free(apagar);
    }

    d->head->proximo = d->head;
    d->head->anterior = d->head;
}
