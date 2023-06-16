#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTOS 100

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    int numFilhos;
    int proximo;
} Aluno;

typedef struct {
    Aluno elementos[MAX_ELEMENTOS];
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

void inserirElemento(Lista* lista, Aluno aluno) {
    if (lista->livre != -1) {
        int posicaoInserir = lista->livre;
        lista->livre = lista->elementos[posicaoInserir].proximo;
        lista->elementos[posicaoInserir] = aluno;

        if (lista->primeiro == -1) {
            lista->primeiro = posicaoInserir;
            lista->elementos[posicaoInserir].proximo = -1;
        } else {
            int posicaoAtual = lista->primeiro;
            int posicaoAnterior = -1;

            while (posicaoAtual != -1 && strcmp(lista->elementos[posicaoAtual].nome, aluno.nome) < 0) {
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

int buscarElemento(Lista* lista, int codigo) {
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1) {
        if (lista->elementos[posicaoAtual].codigo == codigo) {
            return posicaoAtual;
        }
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    return -1;
}

void excluirElemento(Lista* lista, int codigo) {
    int posicaoAtual = lista->primeiro;
    int posicaoAnterior = -1;

    while (posicaoAtual != -1 && lista->elementos[posicaoAtual].codigo != codigo) {
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

        printf("Aluno com código %d excluído da lista.\n", codigo);
    } else {
        printf("Aluno não encontrado.\n");
    }
}

void imprimirLista(Lista* lista) {
    printf("Lista de Alunos:\n");
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1) {
        Aluno aluno = lista->elementos[posicaoAtual];
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               aluno.codigo, aluno.nome, aluno.idade, aluno.numFilhos);
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    printf("\n");
}

int main() {
    Lista lista;
    criarLista(&lista);

    Aluno aluno1 = {1, "João Silva", 20, 0};
    Aluno aluno2 = {2, "Maria Santos", 22, 1};

    inserirElemento(&lista, aluno1);
    inserirElemento(&lista, aluno2);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 2);
    if (posicao != -1) {
        printf("Aluno com código 2 encontrado na posição %d\n", posicao);
    } else {
        printf("Aluno com código 2 não encontrado na lista\n");
    }

    excluirElemento(&lista, 2);

    imprimirLista(&lista);

    printf("Quantidade de alunos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}
