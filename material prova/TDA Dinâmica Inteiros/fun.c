#include "main.h"

void criarLista(Lista* lista) {
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

void inserirElemento(Lista* lista, int valor) {
    Node* novoElemento = (Node*)malloc(sizeof(Node));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (lista->primeiro == NULL) {
        lista->primeiro = novoElemento;
    } else {
        Node* ultimoElemento = lista->primeiro;

        while (ultimoElemento->proximo != NULL) {
            ultimoElemento = ultimoElemento->proximo;
        }

        ultimoElemento->proximo = novoElemento;
    }

    lista->tamanho++;
}

int obterQuantidadeElementos(Lista* lista) {
    return lista->tamanho;
}

int buscarElemento(Lista* lista, int valor) {
    Node* elementoAtual = lista->primeiro;
    int posicaoAtual = 0;

    while (elementoAtual != NULL) {
        if (elementoAtual->valor == valor) {
            return posicaoAtual;
        }

        elementoAtual = elementoAtual->proximo;
        posicaoAtual++;
    }

    return -1;
}

void excluirElemento(Lista* lista, int valor) {
    if (lista->primeiro == NULL) {
        printf("Lista está vazia. Não é possível excluir o elemento.\n");
        return;
    }

    Node* elementoAtual = lista->primeiro;
    Node* elementoAnterior = NULL;

    while (elementoAtual != NULL && elementoAtual->valor != valor) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAtual != NULL) {
        if (elementoAnterior == NULL) {
            lista->primeiro = elementoAtual->proximo;
        } else {
            elementoAnterior->proximo = elementoAtual->proximo;
        }

        free(elementoAtual);
        lista->tamanho--;

        printf("Elemento %d excluído da lista.\n", valor);
    } else {
        printf("Elemento não encontrado.\n");
    }
}

void imprimirLista(Lista* lista) {
    printf("Lista: ");
    Node* elementoAtual = lista->primeiro;

    while (elementoAtual != NULL) {
        printf("%d ", elementoAtual->valor);
        elementoAtual = elementoAtual->proximo;
    }

    printf("\n");
}
