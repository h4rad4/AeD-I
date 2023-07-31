#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void inicializarArvore(Arvore *arvore)
{
    arvore->raiz = NULL;
}

Node *criarNo(Paciente paciente)
{
    Node *novoNo = malloc(sizeof(Node));
    if (novoNo != NULL)
    {
        novoNo->paciente = paciente;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

Node *inserirNo(Node *raiz, Node *no)
{
    if (raiz == NULL)
        return no;

    if (raiz->paciente.codigo > no->paciente.codigo)
        raiz->esquerda = inserirNo(raiz->esquerda, no);
    else
        raiz->direita = inserirNo(raiz->direita, no);

    return raiz;
}

int adiciona(Arvore *arvore, Node *novo)
{
    arvore->raiz = inserirNo(arvore->raiz, novo);
    return 1;
}

int adiciona2(Arvore *arvore, Paciente p)
{
    Node *novoNo = criarNo(p);
    if (novoNo == NULL)
        return 0;

    adiciona(arvore, novoNo);
    return 1;
}

void listarNos(Node *raiz)
{
    if (raiz != NULL)
    {
        printf("Endereco: %p\n", raiz);
        printf("No esquerdo: %p\n", raiz->esquerda);
        printf("No direito: %p\n", raiz->direita);
        printf("Codigo: %d\n", raiz->paciente.codigo);
        printf("Nome: %s\n", raiz->paciente.nome);
        printf("\n");
        listarNos(raiz->esquerda);
        listarNos(raiz->direita);
    }
}

void listarArvore(Arvore *arvore)
{
    listarNos(arvore->raiz);
}

// Função para liberar a memória dos nós na árvore
void liberarArvore(Node *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

// Função para liberar a memória da estrutura de árvore completa
void destruirArvore(Arvore *arvore)
{
    liberarArvore(arvore->raiz);
    arvore->raiz = NULL; // Definir raiz como NULL após liberar a memória
}

int numeroNos(Node *raiz)
{
    if (!raiz)
        return 0;
    return (1 + numeroNos(raiz->esquerda) + numeroNos(raiz->direita));
}

Node *contem(Node *raiz, int codigo)
{
    if (raiz == NULL)
        return (NULL);
    if (raiz->paciente.codigo == codigo)
        return raiz;

    if (raiz->paciente.codigo > codigo)
        return contem(raiz->esquerda, codigo);
    else
        return contem(raiz->direita, codigo);
}

Node *buscar(Arvore *arvore, int codigo)
{
    return contem(arvore->raiz, codigo);
}

void percorrer_pre_ordem(Node *raiz)
{
    if (!raiz) return; // Se a raiz for nula

    printf("%d \n", raiz->paciente.codigo);
    percorrer_pre_ordem(raiz->esquerda);
    percorrer_pre_ordem(raiz->direita);
}

void percorrer_in_ordem(Node *raiz)
{
    if (!raiz) return; 
    
    percorrer_in_ordem(raiz->esquerda);
    printf("%d \n", raiz->paciente.codigo);
    percorrer_in_ordem(raiz->direita);
}

void percorrer_pos_ordem(Node *raiz)
{
    if (!raiz)
        return;

    percorrer_pos_ordem(raiz->esquerda);
    percorrer_pos_ordem(raiz->direita);
    printf("%d \n", raiz->paciente.codigo);
}
