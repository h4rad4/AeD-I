#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    char data[50];
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node *criarNo(const char *dados)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    strcpy(novoNo->data, dados);
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

// Função p inserir um nó na árvore de forma ordenada
Node *inserirNo(Node *raiz, const char *dados)
{
    if (raiz == NULL)
        return criarNo(dados);

    int resultadoComparacao = strcmp(dados, raiz->data);
    if (resultadoComparacao < 0)
        raiz->esquerda = inserirNo(raiz->esquerda, dados);
    else if (resultadoComparacao > 0)
        raiz->direita = inserirNo(raiz->direita, dados);

    return raiz;
}

int alturaArvore(Node *raiz)
{
    if (raiz == NULL)
        return 0;

    int alturaEsquerda = alturaArvore(raiz->esquerda);
    int alturaDireita = alturaArvore(raiz->direita);

    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

// Função p contar os nos em um nível específico
int contarNosNoNivel(Node *raiz, int nivelAlvo, int nivelAtual)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (nivelAtual == nivelAlvo)
    {
        return 1;
    }

    return contarNosNoNivel(raiz->esquerda, nivelAlvo, nivelAtual + 1) +
           contarNosNoNivel(raiz->direita, nivelAlvo, nivelAtual + 1);
}

bool buscarNo(Node *raiz, const char *alvo)
{
    if (raiz == NULL)
        return false;

    int resultadoComparacao = strcmp(alvo, raiz->data);

    if (resultadoComparacao == 0)
        return true;
    else if (resultadoComparacao < 0)
        return buscarNo(raiz->esquerda, alvo);
    else
        return buscarNo(raiz->direita, alvo);
}

int main(int argc, char const *argv[])
{
    Node *raiz = NULL;
    raiz = inserirNo(raiz, "apple");
    raiz = inserirNo(raiz, "banana");
    raiz = inserirNo(raiz, "cherry");
    raiz = inserirNo(raiz, "date");
    raiz = inserirNo(raiz, "grape");
    raiz = inserirNo(raiz, "fig");

    int nivelAlvo = 2;
    int quantidade = contarNosNoNivel(raiz, nivelAlvo, 1);
    int altura = alturaArvore(raiz);

    printf("Numero de nos no nivel %d: %d\n", nivelAlvo, quantidade);
    printf("Altura da arvore: %d\n", altura);

    const char *alvo = "fig";

    if (buscarNo(raiz, alvo))
        printf("String '%s' encontrada na arvore.\n", alvo);
    else
        printf("String '%s' nao encontrada na arvore.\n", alvo);

    return 0;
}
