#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No
{
    char dado[50];
    struct No *esquerda;
    struct No *direita;
} No;

No *criarNo(const char *dado)
{
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->dado, dado);
    novoNo->esquerda = novoNo->direita = NULL;
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

    return raiz;
}

bool buscarNo(No *raiz, const char *alvo, char *caminho, int *indice, int *passos)
{
    if (raiz == NULL)
        return false;

    (*passos)++; // Incrementa o contador de passos

    int resultadoComparacao = strcmp(alvo, raiz->dado);
    if (resultadoComparacao == 0)
    {
        strcat(caminho, raiz->dado);
        *indice += strlen(raiz->dado);
        return true;
    }
    else if (resultadoComparacao < 0)
    {
        strcat(caminho, raiz->dado);
        *indice += strlen(raiz->dado);
        strcat(caminho, " -> ");
        *indice += 4;
        return buscarNo(raiz->esquerda, alvo, caminho, indice, passos);
    }
    else
    {
        strcat(caminho, raiz->dado);
        *indice += strlen(raiz->dado);
        strcat(caminho, " -> ");
        *indice += 4;
        return buscarNo(raiz->direita, alvo, caminho, indice, passos);
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
    int indice = 0;
    int passos = 0;

    if (buscarNo(raiz, alvo, caminho, &indice, &passos))
    {
        printf("String '%s' encontrada na arvore ABB.\n", alvo);
        printf("Caminho ate a string: %s\n", caminho);
        printf("Numero de passos necessarios: %d\n", passos);
    }
    else
    {
        printf("String '%s' nao encontrada na arvore ABB.\n", alvo);
    }

    return 0;
}
