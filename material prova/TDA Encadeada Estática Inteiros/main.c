#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 100

typedef struct
{
    int valor;
    int proximo;
} ElementoListaLigadaEstaticaInteiros;

typedef struct
{
    ElementoListaLigadaEstaticaInteiros elementos[MAX_ELEMENTOS];
    int primeiro;
    int livre;
    int tamanho;
} ListaLigadaEstaticaInteiros;

void criarLista(ListaLigadaEstaticaInteiros *lista)
{
    lista->primeiro = -1;
    lista->livre = 0;
    lista->tamanho = 0;

    for (int i = 0; i < MAX_ELEMENTOS - 1; i++)
    {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_ELEMENTOS - 1].proximo = -1;
}

void inserirElemento(ListaLigadaEstaticaInteiros *lista, int valor)
{
    if (lista->livre != -1)
    {
        int posicaoInserir = lista->livre;
        lista->livre = lista->elementos[posicaoInserir].proximo;
        lista->elementos[posicaoInserir].valor = valor;

        if (lista->primeiro == -1)
        {
            lista->primeiro = posicaoInserir;
            lista->elementos[posicaoInserir].proximo = -1;
        }
        else
        {
            int posicaoAtual = lista->primeiro;
            int posicaoAnterior = -1;

            while (posicaoAtual != -1 && lista->elementos[posicaoAtual].valor < valor)
            {
                posicaoAnterior = posicaoAtual;
                posicaoAtual = lista->elementos[posicaoAtual].proximo;
            }

            if (posicaoAnterior == -1)
            {
                lista->elementos[posicaoInserir].proximo = lista->primeiro;
                lista->primeiro = posicaoInserir;
            }
            else
            {
                lista->elementos[posicaoInserir].proximo = lista->elementos[posicaoAnterior].proximo;
                lista->elementos[posicaoAnterior].proximo = posicaoInserir;
            }
        }

        lista->tamanho++;
    }
    else
    {
        printf("Lista esta cheia. Não e possivel inserir o elemento.\n");
    }
}

int obterQuantidadeElementos(ListaLigadaEstaticaInteiros *lista)
{
    return lista->tamanho;
}

int buscarElemento(ListaLigadaEstaticaInteiros *lista, int valor)
{
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1)
    {
        if (lista->elementos[posicaoAtual].valor == valor)
        {
            return posicaoAtual;
        }
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    return -1;
}

int buscaBinariaRecursiva(ListaLigadaEstaticaInteiros *lista, int valor, int inicio, int fim)
{
    if (inicio > fim)
    {
        return -1; // Elemento não encontrado
    }

    int meio = (inicio + fim) / 2;
    int posicaoAtual = lista->primeiro;

    for (int i = 0; i < meio; i++)
    {
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    if (lista->elementos[posicaoAtual].valor == valor)
    {
        return posicaoAtual; // Elemento encontrado
    }
    else if (lista->elementos[posicaoAtual].valor < valor)
    {
        return buscaBinariaRecursiva(lista, valor, meio + 1, fim); // Busca na metade superior
    }
    else
    {
        return buscaBinariaRecursiva(lista, valor, inicio, meio - 1); // Busca na metade inferior
    }
}

void excluirElemento(ListaLigadaEstaticaInteiros *lista, int valor)
{
    int posicaoAtual = lista->primeiro;
    int posicaoAnterior = -1;

    while (posicaoAtual != -1 && lista->elementos[posicaoAtual].valor != valor)
    {
        posicaoAnterior = posicaoAtual;
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    if (posicaoAtual != -1)
    {
        if (posicaoAnterior == -1)
        {
            lista->primeiro = lista->elementos[posicaoAtual].proximo;
        }
        else
        {
            lista->elementos[posicaoAnterior].proximo = lista->elementos[posicaoAtual].proximo;
        }

        lista->elementos[posicaoAtual].proximo = lista->livre;
        lista->livre = posicaoAtual;
        lista->tamanho--;

        printf("Elemento %d excluido da lista.\n", valor);
    }
    else
    {
        printf("Elemento nao encontrado.\n");
    }
}

void imprimirLista(ListaLigadaEstaticaInteiros *lista)
{
    printf("Lista: ");
    int posicaoAtual = lista->primeiro;

    while (posicaoAtual != -1)
    {
        printf("%d ", lista->elementos[posicaoAtual].valor);
        posicaoAtual = lista->elementos[posicaoAtual].proximo;
    }

    printf("\n");
}

int main()
{
    ListaLigadaEstaticaInteiros lista;
    criarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 10);
    if (posicao != -1)
    {
        printf("Elemento encontrado na posicao %d\n", posicao);
    }
    else
    {
        printf("Elemento nao encontrado na lista\n");
    }

    excluirElemento(&lista, 10);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}
