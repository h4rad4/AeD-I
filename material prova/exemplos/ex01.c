#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct
{

    int valor;
    int proximo;

} ELEMENTO;

typedef struct
{
    ELEMENTO lista[MAX];
    int inicio;
    int n;

} LISTA_INTEIROS;

LISTA_INTEIROS *inicializarlista()
{
    int i;
    LISTA_INTEIROS *m = malloc(sizeof(LISTA_INTEIROS));
    for (i = 0; i < MAX - 1; i++)
    {
        m->lista[i].proximo = i + 1;
    }
    m->lista[MAX - 1].proximo = -1;
    m->inicio = -1;
    m->n = 0;

    return m;
}

int tamanholista(LISTA_INTEIROS *m)
{
    int tam = 0;
    int i = m->inicio;
    while (i != -1)
    {
        tam++;
        i = m->lista[i].proximo;
    }
    return tam;
}

int ListaCheia(LISTA_INTEIROS *lista)
{

    if (lista == NULL || lista->n == MAX)
        return -1;
}

int ListaVazia(LISTA_INTEIROS *lista)
{

    if (lista == NULL || lista->n == 0)
        return -1;
}

int InserirElemento(LISTA_INTEIROS *lista, int x)
{

    if (ListaCheia(lista) == -1)
        return -1;

    if (lista->n == 0)
    {
        lista->lista[0].valor = x;
        lista->lista[0].proximo = -1;
        lista->inicio = 0;
        lista->n++;
    }
    else if (lista->n > 0)
    {
        lista->lista[lista->n].valor = x;
        lista->lista[lista->n].proximo = lista->lista[lista->n - 1].proximo;
        lista->lista[lista->n - 1].proximo = lista->n;
        lista->n++;
    }
}

int inserirOrdenado(LISTA_INTEIROS *lista, int x)
{
    int i = lista->inicio;
    int pos = -1;
    if (ListaCheia(lista) == -1)
        return -1;

    if (lista->n == 0)
    {
        lista->lista[0].valor = x;
        lista->lista[0].proximo = -1;
        lista->inicio = 0;
        lista->n++;
    }
    else
    {
        while (i != -1)
        {
            if (x > lista->lista[i].valor)
            {
                pos = i;
            }
            else if (x == lista->lista[i].valor)
            {
                return -1;
            }
            i = lista->lista[i].proximo;
        }

        lista->lista[lista->n].valor = x;

        if (pos == -1)
        {
            lista->lista[lista->n].proximo = lista->inicio;
            lista->inicio = lista->n;
            lista->n++;
        }
        else
        {
            lista->lista[lista->n].proximo = lista->lista[pos].proximo;
            lista->lista[pos].proximo = lista->n;
            lista->n++;
        }
    }
}

int InserirElemento_pos(LISTA_INTEIROS *lista, int pos, int novo_valor)
{
    int i = lista->inicio;
    int pos_ant = -1;

    if (ListaCheia(lista) == -1 || pos < 0 || pos > MAX)
        return -1;

    if (lista->n == 0)
    {
        lista->lista[pos].valor = novo_valor;
        lista->lista[pos].proximo = -1;
        lista->inicio = pos;
        lista->n++;
    }

    else
    {
        while (i != -1)
        {
            if (novo_valor > lista->lista[i].valor)
            {
                pos_ant = i;
            }
            else if (novo_valor == lista->lista[i].valor)
            {
                return -1;
            }
            i = lista->lista[i].proximo;
        }

        lista->lista[pos].valor = novo_valor;
        if (pos_ant == -1)
        {
            lista->lista[pos].proximo = lista->inicio;
            lista->inicio = pos;
            lista->n++;
        }
        else
        {
            lista->lista[pos].proximo = lista->lista[pos_ant].proximo;
            lista->lista[pos_ant].proximo = pos;
            lista->n++;
        }
    }
}

int excluirElemento(LISTA_INTEIROS *lista, int pos)
{
    int i = lista->inicio;
    int anterior = -1;
    if (ListaVazia(lista) == -1 || pos < 0 || pos > MAX)
        return -1;
    if (lista->n == 1)
    {
        lista->lista[pos].valor = NULL;
        lista->lista[pos].proximo = NULL;
        lista->n--;
    }
    else
    {
        while (i != -1)
        {
            if (lista->lista[pos].valor > lista->lista[i].valor)
            {
                anterior = i;
            }
            i = lista->lista[i].proximo;
        }
        if (anterior == -1)
        {
            lista->inicio = lista->lista[pos].proximo;
            lista->lista[pos].valor = NULL;
            lista->lista[pos].proximo = NULL;
            lista->n--;
        }
        else
        {
            lista->lista[anterior].proximo = lista->lista[pos].proximo;
            lista->lista[pos].valor = NULL;
            lista->lista[pos].proximo = NULL;
            lista->n--;
        }
    }
}

int buscaSeq(LISTA_INTEIROS *lista, int x)
{
    int i = lista->inicio;
    if (ListaVazia(lista) == -1)
        return -1;

    while (i != -1)
    {
        if (x == lista->lista[i].valor)
        {
            return i;
        }
        i = lista->lista[i].proximo;
    }
}

void ImprimirElemento(LISTA_INTEIROS *lista)
{
    int i = lista->inicio;
    while (i != -1)
    {
        printf(" \n Valor: %d", lista->lista[i].valor, lista->lista[i].proximo);
        i = lista->lista[i].proximo;
    }
}

int buscaMaior_Excluir(LISTA_INTEIROS *lista)
{
    int i = lista->inicio;
    int posmaior;
    if (ListaVazia(lista) == -1)
        return -1;

    int maior = lista->lista[i].valor;
    while (i != -1)
    {

        if (lista->lista[i].valor > maior)
        {
            maior = lista->lista[i].valor;
            posmaior = i;
        }
        i = lista->lista[i].proximo;
    }
    printf(" \n Maior elemento: %d", maior);

    lista->lista[posmaior - 1].proximo = lista->lista[posmaior].proximo;
}

int main()
{
    LISTA_INTEIROS *inteiros;
    inteiros = inicializarlista();
    InserirElemento(inteiros, 15);
    InserirElemento(inteiros, 28);
    InserirElemento(inteiros, 9);
    InserirElemento(inteiros, 31);
    InserirElemento(inteiros, 2);
    ImprimirElemento(inteiros);
    buscaMaior_Excluir(inteiros);
    ImprimirElemento(inteiros);
}
