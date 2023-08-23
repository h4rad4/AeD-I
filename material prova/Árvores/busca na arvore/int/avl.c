#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int dado;
    struct No *esquerda;
    struct No *direita;
    int altura;
} No;

int max(int a, int b)
{
    return (a > b) ? a : b; // Se a>b, retorna A; se nao, retorna B
}

int altura(No *no)
{
    if (no == NULL)
    {
        return 0;
    }
    return no->altura;
}

No *criarNo(int dado)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

int fatorBalanceamento(No *no)
{
    if (no == NULL)
    {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

No *rotacaoDireita(No *y)
{
    No *x = y->esquerda;
    No *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

No *rotacaoEsquerda(No *x)
{
    No *y = x->direita;
    No *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

No *inserirNo(No *raiz, int dado)
{
    if (raiz == NULL)
    {
        return criarNo(dado);
    }

    if (dado < raiz->dado)
    {
        raiz->esquerda = inserirNo(raiz->esquerda, dado);
    }
    else if (dado > raiz->dado)
    {
        raiz->direita = inserirNo(raiz->direita, dado);
    }
    else
    {
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    int balanceamento = fatorBalanceamento(raiz);

    if (balanceamento > 1 && dado < raiz->esquerda->dado)
    {
        return rotacaoDireita(raiz);
    }
    if (balanceamento < -1 && dado > raiz->direita->dado)
    {
        return rotacaoEsquerda(raiz);
    }
    if (balanceamento > 1 && dado > raiz->esquerda->dado)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (balanceamento < -1 && dado < raiz->direita->dado)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

bool buscarNo(No *raiz, int alvo, char *caminho, int *passos)
{
    if (raiz == NULL)
    {
        return false;
    }

    (*passos)++;

    if (alvo == raiz->dado)
    {
        sprintf(caminho, "%d", raiz->dado);
        return true;
    }
    else if (alvo < raiz->dado)
    {
        sprintf(caminho, "%s%d -> ", caminho, raiz->dado);
        return buscarNo(raiz->esquerda, alvo, caminho, passos);
    }
    else
    {
        sprintf(caminho, "%s%d -> ", caminho, raiz->dado);
        return buscarNo(raiz->direita, alvo, caminho, passos);
    }
}

void imprimirCaminho(const char *caminho)
{
    printf("Caminho: %s\n", caminho);
}

int main()
{
    No *raiz = NULL;
    raiz = inserirNo(raiz, 30);
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 25);
    raiz = inserirNo(raiz, 35);

    int alvo = 25;
    char caminho[100] = "";
    int passos = 0;

    if (buscarNo(raiz, alvo, caminho, &passos))
    {
        printf("Numero %d encontrado na arvore AVL.\n", alvo);
        imprimirCaminho(caminho);
        printf("Passos necessarios: %d\n", passos);
    }
    else
    {
        printf("Numero %d nao encontrado na arvore AVL.\n", alvo);
    }

    return 0;
}
