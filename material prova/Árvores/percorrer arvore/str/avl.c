#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[20];
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

Node *criarNo(char *dados)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    strcpy(novoNo->data, dados);
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

Node *inserir(Node *raiz, char *dados)
{
    if (raiz == NULL)
        return criarNo(dados);

    if (strcmp(dados, raiz->data) < 0)
        raiz->esquerda = inserir(raiz->esquerda, dados);
    else if (strcmp(dados, raiz->data) > 0)
        raiz->direita = inserir(raiz->direita, dados);
    else
        return raiz; // Duplicatas não são permitidas

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    int balanceamento = obterBalanceamento(raiz);

    // Caso Pesado à Esquerda
    if (balanceamento > 1 && strcmp(dados, raiz->esquerda->data) < 0)
        return rotacaoDireita(raiz);

    // Caso Pesado à Direita
    if (balanceamento < -1 && strcmp(dados, raiz->direita->data) > 0)
        return rotacaoEsquerda(raiz);

    // Caso Esquerda Direita
    if (balanceamento > 1 && strcmp(dados, raiz->esquerda->data) > 0)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Caso Direita Esquerda
    if (balanceamento < -1 && strcmp(dados, raiz->direita->data) < 0)
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
        printf("%s ", no->data);
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
        printf("%s ", no->data);
    }
}

void percorrerEmOrdem(Node *no)
{
    if (no != NULL)
    {
        percorrerEmOrdem(no->esquerda);
        printf("%s ", no->data);
        percorrerEmOrdem(no->direita);
    }
}

int main(int argc, char const *argv[])
{
    Node *raiz = NULL;

    raiz = inserir(raiz, "apple");
    raiz = inserir(raiz, "banana");
    raiz = inserir(raiz, "cherry");
    raiz = inserir(raiz, "date");
    raiz = inserir(raiz, "grape");
    raiz = inserir(raiz, "fig");

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
