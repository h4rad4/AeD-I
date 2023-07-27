#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializarArvore(Arvore arvore)
{
    arvore.raiz = NULL;
}

Node *criarNo(Paciente paciente)
{
    Node *novoNo = malloc(sizeof(Paciente));
    novoNo->paciente = paciente;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
}

Node *inserirNo(Node *raiz, Node *No)
{
    if (raiz == NULL)
        return No;

    if (raiz->paciente.codigo > No->paciente.codigo)
        raiz->esquerda = inserirNo(raiz->esquerda, No);
    else
        raiz->direita = inserirNo(raiz->direita, No);

    return raiz;
}

int adiciona(Node *raiz, Node *novo)
{
    raiz = inserirNo(raiz, novo);

    return 1;
}

int adiciona2(Arvore *arvore, Paciente p)
{
    Node *novoNo = malloc(sizeof(Paciente));
    novoNo->paciente = p;
    arvore->raiz->esquerda = NULL;
    arvore->raiz->direita = NULL;

    adiciona(arvore->raiz, novoNo);

    return 1;
}

void listarNOS(Node *raiz)
{
    printf("a");
    if (raiz != NULL)
    {
        printf("Endereco: %x\n");
        printf("No esquerdo: %x\n");
        printf("No direito: %x\n");
        printf("Codigo: %d\n");
        printf("Nome: %s\n");

        printf("\n");
    }

    listarNOS(raiz->esquerda);
    listarNOS(raiz->direita);
}

void listarARVORE(Arvore *arvore)
{
    listarNOS(arvore->raiz);
}
