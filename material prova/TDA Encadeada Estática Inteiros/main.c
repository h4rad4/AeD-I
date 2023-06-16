#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 100

typedef struct {
    int valor;
    int proximo;
} Node;

typedef struct {
    Node elementos[MAX_ELEMENTOS];
    int primeiro;
    int livre;
    int tamanho;
} Lista;

void criarLista(Lista* lista) {
    lista->primeiro = -1;
    lista->livre = 0;
    lista->tamanho = 0;

    for (int i = 0; i < MAX_ELEMENTOS - 1; i++) {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_ELEMENTOS - 1].proximo = -1;
}

void inserirElemento(Lista* lista, int valor) {
    if (lista->livre != -1) {
        int posicaoInserir = lista->livre;
        lista->livre = lista->elementos[posicaoInserir].proximo;
        lista->elementos[posicaoInserir].valor = valor;

        if (lista->primeiro == -1) {
            lista->primeiro = posicaoInserir;
            lista->elementos[posicaoInserir].proximo = -1;
        } else {
            int posicaoAtual = lista->primeiro;
            int posicaoAnterior = -1;

            while (posicaoAtual != -1 && lista->elementos[posicaoAtual].valor < valor) {
                posicaoAnterior = posicaoAtual;
                posicaoAtual = lista->elementos[posicaoAtual].proximo;
            }

            if (posicaoAnterior == -1) {
                lista->elementos[posicaoInserir].proximo = lista->primeiro;
                lista->primeiro = posicaoInserir;
            } else {
                lista->elementos[posicaoInserir].proximo = lista->elementos[posicaoAnterior].proximo;
                lista->elementos[posicaoAnterior].proximo = posicaoInserir;
            }
        }

        lista->tamanho++;
    } else {
        printf("Lista está cheia. Não é possível inserir o elemento.\n");
    }
}

int obterQuantidadeElementos(Lista* lista) {
    return lista->tamanho;
}

int buscarElemento(Lista* lista, int valor) {
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1) {
        if (lista->elementos[posicaoAtual].valor == valor) {
            return posicaoAtual;
        }
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    return -1;
}

void excluirElemento(Lista* lista, int valor) {
    int posicaoAtual = lista->primeiro;
    int posicaoAnterior = -1;

    while (posicaoAtual != -1 && lista->elementos[posicaoAtual].valor != valor) {
        posicaoAnterior = posicaoAtual;
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    if (posicaoAtual != -1) {
        if (posicaoAnterior == -1) {
            lista->primeiro = lista->elementos[posicaoAtual].proximo;
        } else {
            lista->elementos[posicaoAnterior].proximo = lista->elementos[posicaoAtual].proximo;
        }

        lista->elementos[posicaoAtual].proximo = lista->livre;
        lista->livre = posicaoAtual;
        lista->tamanho--;

        printf("Elemento %d excluído da lista.\n", valor);
    } else {
        printf("Elemento não encontrado.\n");
    }
}

void imprimirLista(Lista* lista) {
    printf("Lista: ");
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1) {
        printf("%d ", lista->elementos[posicaoAtual].valor);
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    printf("\n");
}

int main() {
    Lista lista;
    criarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 10);
    if (posicao != -1) {
        printf("Elemento 10 encontrado na posição %d\n", posicao);
    } else {
        printf("Elemento 10 não encontrado na lista\n");
    }

    excluirElemento(&lista, 10);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}
