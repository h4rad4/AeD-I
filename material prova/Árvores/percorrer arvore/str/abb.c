#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[20];
    struct Node *esquerda;
    struct Node *direita;
};

typedef struct Node Node;

Node *criarNo(char *dados)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    strcpy(novoNo->data, dados);
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserir(Node **raiz, char *dados)
{
    if (*raiz == NULL)
    {
        *raiz = criarNo(dados);
        return;
    }

    int comparacao = strcmp(dados, (*raiz)->data);

    if (comparacao < 0)
    {
        inserir(&((*raiz)->esquerda), dados);
    }
    else
    {
        inserir(&((*raiz)->direita), dados);
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

int main(int argc, char const *argv[])
{
    Node *raiz = NULL;

    inserir(&raiz, "apple");
    inserir(&raiz, "banana");
    inserir(&raiz, "cherry");
    inserir(&raiz, "date");
    inserir(&raiz, "grape");
    inserir(&raiz, "fig");

    printf("Percurso em Ordem (Arvore ABB): ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Percurso Pre-Ordem (Arvore ABB): ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("Percurso Pos-Ordem (Arvore ABB): ");
    percorrerPosOrdem(raiz);
    printf("\n");

    return 0;
}
