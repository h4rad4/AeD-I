#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

No *criarNo(int dado)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = novoNo->direita = NULL;
    
    return novoNo;
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

    return raiz;
}

bool buscarNo(No *raiz, int alvo, char *caminho, int *passos)
{
    if (raiz == NULL)
    {
        return false;
    }

    (*passos)++; // Incrementa o contador de passos

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

int main(int argc, char const *argv[])
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
        printf("Numero %d encontrado na arvore ABB.\n", alvo);
        printf("Caminho ate o numero: %s\n", caminho);
        printf("Numero de passos necessarios: %d\n", passos);
    }
    else
    {
        printf("Numero %d nao encontrado na arvore ABB.\n", alvo);
    }

    return 0;
}
