#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No
{
    char dado[50];
    struct No *esquerda;
    struct No *direita;
    int altura;
} No;

int altura(No *no)
{
    if (no == NULL)
        return 0;

    return no->altura;
}

int fatorBalanceamento(No *no)
{
    if (no == NULL)
        return 0;

    return altura(no->esquerda) - altura(no->direita);
}

void atualizarAltura(No *no)
{
    if (no == NULL)
        return;

    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    no->altura = (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

No *rotacaoDireita(No *y)
{
    No *x = y->esquerda;
    No *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

No *rotacaoEsquerda(No *x)
{
    No *y = x->direita;
    No *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

No *criarNo(const char *dado)
{
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->dado, dado);
    novoNo->esquerda = novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

No *inserirNo(No *raiz, const char *dado)
{
    if (raiz == NULL)
        return criarNo(dado);

    int resultadoComparacao = strcmp(dado, raiz->dado);

    if (resultadoComparacao < 0)
        raiz->esquerda = inserirNo(raiz->esquerda, dado);
    else if (resultadoComparacao > 0)
        raiz->direita = inserirNo(raiz->direita, dado);
    else
        return raiz;

    atualizarAltura(raiz);

    int balanco = fatorBalanceamento(raiz);

    if (balanco > 1 && resultadoComparacao < 0)
        return rotacaoDireita(raiz);

    if (balanco < -1 && resultadoComparacao > 0)
        return rotacaoEsquerda(raiz);

    if (balanco > 1 && resultadoComparacao > 0)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balanco < -1 && resultadoComparacao < 0)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

bool buscarNo(No *raiz, const char *alvo, char *caminho, int *passos)
{
    if (raiz == NULL)
        return false;

    (*passos)++;

    int resultadoComparacao = strcmp(alvo, raiz->dado);
    if (resultadoComparacao == 0)
    {
        strcat(caminho, raiz->dado);
        return true;
    }
    else if (resultadoComparacao < 0)
    {
        strcat(caminho, raiz->dado);
        strcat(caminho, " -> ");
        return buscarNo(raiz->esquerda, alvo, caminho, passos);
    }
    else
    {
        strcat(caminho, raiz->dado);
        strcat(caminho, " -> ");
        return buscarNo(raiz->direita, alvo, caminho, passos);
    }
}

int main(int argc, char const *argv[])
{
    No *raiz = NULL;
    raiz = inserirNo(raiz, "apple");
    raiz = inserirNo(raiz, "banana");
    raiz = inserirNo(raiz, "cherry");
    raiz = inserirNo(raiz, "date");
    raiz = inserirNo(raiz, "grape");
    raiz = inserirNo(raiz, "fig");

    const char *alvo = "cherry";
    char caminho[1000] = "";
    int passos = 0;

    if (buscarNo(raiz, alvo, caminho, &passos))
    {
        printf("String '%s' encontrada na arvore AVL.\n", alvo);
        printf("Caminho ate a string: %s\n", caminho);
        printf("Numero de passos necessarios: %d\n", passos);
    }
    else
        printf("String '%s' nao encontrada na arvore AVL.\n", alvo);

    return 0;
}
