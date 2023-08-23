#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int altura;
    struct Node *esquerda;
    struct Node *direita;
};

typedef struct Node Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int altura(Node *no)
{
    if (no == NULL)
        return -1;
    return no->altura;
}

int obterBalanceamento(Node *no)
{
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

Node *criarNo(int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->data = valor;
    novoNo->altura = 0;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

Node *rotacaoDireita(Node *y)
{
    Node *x = y->esquerda;
    Node *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

Node *rotacaoEsquerda(Node *x)
{
    Node *y = x->direita;
    Node *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

Node *inserir(Node *raiz, int valor)
{
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->data)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->data)
        raiz->direita = inserir(raiz->direita, valor);
    else
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    int balanceamento = obterBalanceamento(raiz);

    if (balanceamento > 1 && valor < raiz->esquerda->data)
        return rotacaoDireita(raiz);

    if (balanceamento < -1 && valor > raiz->direita->data)
        return rotacaoEsquerda(raiz);

    if (balanceamento > 1 && valor > raiz->esquerda->data)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && valor < raiz->direita->data)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void percorrerPreOrdem(Node *no)
{
    if (no != NULL)
    {
        printf("%d ", no->data);
        percorrerPreOrdem(no->esquerda);
        percorrerPreOrdem(no->direita);
    }
}

void percorrerPosOrdem(Node *no)
{
    if (no != NULL)
    {
        percorrerPosOrdem(no->esquerda);
        percorrerPosOrdem(no->direita);
        printf("%d ", no->data);
    }
}

void percorrerEmOrdem(Node *no)
{
    if (no != NULL)
    {
        percorrerEmOrdem(no->esquerda);
        printf("%d ", no->data);
        percorrerEmOrdem(no->direita);
    }
}

int main(int argc, char const *argv[])
{
    Node *raiz = NULL;

    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 35);

    printf("Percorrendo Pre-Ordem (Arvore AVL): ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("Percorrendo Em Ordem (Arvore AVL): ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Percorrendo Pos-Ordem (Arvore AVL): ");
    percorrerPosOrdem(raiz);
    printf("\n");

    return 0;
}
