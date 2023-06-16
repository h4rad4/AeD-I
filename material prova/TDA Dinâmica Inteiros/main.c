#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* cabeca;
    int tamanho;
} Lista;

void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

void inserirElemento(Lista* lista, int elemento) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = elemento;
    novoNo->next = NULL;

    if (lista->cabeca == NULL) {
        lista->cabeca = novoNo;
    } else {
        Node* atual = lista->cabeca;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo;
    }

    lista->tamanho++;
}

void removerElemento(Lista* lista, int elemento) {
    if (lista->cabeca == NULL) {
        return;
    }

    Node* anterior = NULL;
    Node* atual = lista->cabeca;

    while (atual != NULL) {
        if (atual->data == elemento) {
            if (anterior == NULL) {
                lista->cabeca = atual->next;
            } else {
                anterior->next = atual->next;
            }

            free(atual);
            lista->tamanho--;
            return;
        }

        anterior = atual;
        atual = atual->next;
    }
}

int buscarElemento(Lista* lista, int elemento) {
    Node* atual = lista->cabeca;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->data == elemento) {
            return posicao;
        }

        atual = atual->next;
        posicao++;
    }

    return -1;
}

int main() {
    Lista lista;
    inicializarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    printf("Lista: ");
    Node* atual = lista.cabeca;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");

    removerElemento(&lista, 10);

    printf("Lista após a remoção: ");
    atual = lista.cabeca;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");

    int posicao = buscarElemento(&lista, 5);
    if (posicao != -1) {
        printf("Elemento 5 encontrado na posição %d\n", posicao);
    } else {
        printf("Elemento 5 não encontrado na lista\n");
    }

    return 0;
}
