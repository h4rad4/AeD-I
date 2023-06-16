#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct {
    Node* primeiro;
    int tamanho;
} Lista;

void criarLista(Lista* lista);
void inserirElemento(Lista* lista, int valor);
int obterQuantidadeElementos(Lista* lista);
int buscarElemento(Lista* lista, int valor);
void excluirElemento(Lista* lista, int valor);
void imprimirLista(Lista* lista);

#endif