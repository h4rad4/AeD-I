#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define MAX 100

void inicializarLista(ListaAlunos *lista)
{
    lista->inicio = NULL;
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos *lista)
{
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->quantidade = 0;
}

int tamanhoLista(ListaAlunos *lista)
{
    int tam = 0;
    No *i = lista->inicio;

    while (i != NULL)
    {
        tam++;
        i = i->proximo;
    }

    return tam;
}

void verificarLista(ListaAlunos *lista)
{
    No *i = lista->inicio;

    if (i == NULL)
    {
        printf("\nA lista esta vazia.");
        return;
    }

    int cont = 0;
    while (i != NULL)
    {
        cont++;
        i = i->proximo;
    }

    if (cont >= lista->quantidade)
        printf("\nA lista esta cheia.");
    else
        printf("\nA lista não esta cheia.\n ");
}

void inserirAluno(ListaAlunos *lista, Aluno aluno)
{
    No *novo = (No *)malloc(MAX * sizeof(No));

    /* Inicializando novo nó */
    novo->aluno = aluno;
    novo->proximo = NULL;

    /* Se o elemento do primeiro nó for maior que o elemento do segundo nó,
    então o segundo nó deve ocupar o lugar do primeiro (ordem ascendente)*/
    if (lista->inicio == NULL || lista->inicio->aluno.matricula > aluno.matricula)
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    else
    /* Caso contrário, se a lista não estiver vazia e a matrícula do aluno a ser inserido
    for maior do que a matrícula do primeiro aluno da lista, é necessário percorrer a lista
    para encontrar a posição correta de inserção do novo nó. */
    {
        No *atual = lista->inicio;

        /* Percorre a lista até encontrar o nó cuja matrícula seja maior ou igual à matrícula do aluno a ser inserido. */
        while (atual->proximo != NULL && atual->aluno.matricula < aluno.matricula)
            atual = atual->proximo;

        /* Colocando o novo nó na posição em que o nó anterior estava apontando,
        e fazendo o nó anterior apontar para o novo nó. */
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

void imprimirLista(ListaAlunos *lista)
{
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", atual->aluno.matricula, atual->aluno.nome, atual->aluno.idade);
        atual = atual->proximo;
    }
}

void excluirAluno(ListaAlunos *lista, int mat)
{
    No *atual = lista->inicio;
    No *anterior = NULL;

    /* Percorrendo a lista até achar a posição correta */
    while (atual != NULL && atual->aluno.matricula < mat)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->aluno.matricula == mat)
    {
        if (anterior == NULL)
            lista->inicio = atual->proximo;
        else
            /* Excluindo o elemento intermediário, e atribuindo seu 'próximo' ao nó anterior */
            anterior->proximo = atual->proximo;

        free(atual);
        lista->quantidade--;
    }
}

void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula)
{
    /* Percorrendo a lista até encontrar a matrícula antiga */
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->aluno.matricula != matriculaAntiga)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    /* -------------------- Remover da lista o nó com a matrícula antiga -------------------- */
    if (atual != NULL && atual->aluno.matricula == matriculaAntiga)
    {
        if (anterior == NULL)
        {
            /* Se ele for o primeiro nó, apenas alterar o ponteiro inicial para o nó posterior */
            lista->inicio = atual->proximo;
        }

        else
        {
            /* Se não for o primeiro, remover o elemento intermediário e atribuir ao nó anterior
            o ponteiro para o nó posterior. */
            anterior->proximo = atual->proximo;
        }

        /* -------------------- Criando novo nó -------------------- */
        No *novo = (No *)malloc(sizeof(No));

        novo->aluno.matricula = novaMatricula;
        strcpy(novo->aluno.nome, atual->aluno.nome);
        novo->aluno.idade = atual->aluno.idade;

        /* -------------------- Inserindo novo nó --------------------
        (procurando pelo último valor menor que o novo nó, p/ manter a ordem) */
        atual = lista->inicio;
        anterior = NULL;

        while (atual != NULL && atual->aluno.matricula < novaMatricula)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL)
        {
            /*  Então é o primeiro da lista, portanto:
                1. Inserir o nó antes do elemento inicial
                2. Redefinir o início da lista como sendo o novo nó  */
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }

        else
        {
            /* Anterior -> Atual
               Anterior -> Novo -> Atual (inserindo o novo elemento entre os dois extremos) */
            novo->proximo = atual;
            anterior->proximo = novo;
        }
    }
}