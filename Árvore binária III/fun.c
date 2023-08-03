#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Node *criarNo(Paciente p)
{
    Node *novoNo = malloc(sizeof(Node));
    novoNo->pac = p;
    novoNo->h = 0;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

void inicializarArvore(Arvore *a)
{
    a->raiz = NULL;
}

Node *rot_direita(Node *no_desb)
{
    Node *aux;
    aux = no_desb->esquerda;
    no_desb->esquerda = aux->direita;
    aux->direita = no_desb;

    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;
    aux->h = maximo(altura(aux->esquerda), altura(no_desb)) + 1;

    return aux;
}

int altura(Node *raiz)
{
    if (!raiz)
        return -1;
    else
        return raiz->h;
}

int maximo(int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}