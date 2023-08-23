#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *esquerda;
    struct Node *direita;
};

typedef struct Node Node;

Node *criarNo(int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->data = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserir(Node **raiz, int valor)
{
    if (*raiz == NULL)
    {
        *raiz = criarNo(valor);
        return;
    }

    if (valor < (*raiz)->data)
    {
        inserir(&((*raiz)->esquerda), valor);
    }
    else
    {
        inserir(&((*raiz)->direita), valor);
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

int main(int argc, char const *argv[])
{
    Node *raiz = NULL;

    inserir(&raiz, 30);
    inserir(&raiz, 15);
    inserir(&raiz, 50);
    inserir(&raiz, 10);
    inserir(&raiz, 25);
    inserir(&raiz, 35);

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
