#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializar(ARVORE *a)
{
    a->raiz = NULL;
}

int altura(NO *raiz)
{
    if (raiz == NULL)
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

NO *rot_direita(NO *raiz)
{
    NO *aux;
    aux = raiz->esquerda;
    raiz->esquerda = aux->direita;
    aux->direita = raiz;
    raiz->h = maximo(altura(raiz->direita), altura(raiz->esquerda)) + 1;
    aux->h = maximo(altura(aux->esquerda), altura(raiz)) + 1;
    return aux;
}

NO *rot_esquerda(NO *raiz)
{
    NO *aux;
    aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;
    raiz->h = maximo(altura(raiz->direita), altura(raiz->esquerda)) + 1;
    aux->h = maximo(altura(aux->direita), altura(raiz)) + 1;
    return aux;
}

NO *rot_esq_direita(NO *raiz)
{
    raiz->esquerda = rot_esquerda(raiz->esquerda);
    return rot_direita(raiz);
}

NO *rot_dir_esquerda(NO *raiz)
{
    raiz->direita = rot_direita(raiz->direita);
    return rot_esquerda(raiz);
}

NO *inserir_no(NO *raiz, NO *novo)
{
    if (raiz == NULL)
        return novo;
    if (raiz->num > novo->num)
    {
        raiz->esquerda = inserir_no(raiz->esquerda, novo);
        if (abs(altura(raiz->direita) - altura(raiz->esquerda)) > 1)
        {
            if (novo->num < raiz->esquerda->num)
                raiz = rot_direita(raiz);
            else
                raiz = rot_esq_direita(raiz);
        }
    }
    else if (raiz->num < novo->num)
    {
        raiz->direita = inserir_no(raiz->direita, novo);
        if (abs(altura(raiz->esquerda) - altura(raiz->direita)) > 1)
        {
            if (novo->num > raiz->direita->num)
                raiz = rot_esquerda(raiz);
            else
                raiz = rot_dir_esquerda(raiz);
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita)) + 1;
    return raiz;
}

void adiciona_no(ARVORE *a, NO *novo)
{
    a->raiz = inserir_no(a->raiz, novo);
}

void cria_no(ARVORE *a, int numero)
{
    NO *novo = malloc(sizeof(NO));
    novo->num = numero;
    novo->h = 0;
    novo->direita = NULL;
    novo->esquerda = NULL;
    adiciona_no(a, novo);
}

void print_pre_ordem(NO *raiz)
{
    if (raiz == NULL)
        return;
    printf("%d ", raiz->num);
    print_pre_ordem(raiz->esquerda);
    print_pre_ordem(raiz->direita);
}

void print_in_ordem(NO *raiz)
{
    if (raiz == NULL)
        return;
    print_pre_ordem(raiz->esquerda);
    printf("%d ", raiz->num);
    print_pre_ordem(raiz->direita);
}

void print_pos_ordem(NO *raiz)
{
    if (raiz == NULL)
        return;
    print_pre_ordem(raiz->esquerda);
    print_pre_ordem(raiz->direita);
    printf("%d ", raiz->num);
}
