#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void inicializarHash(TB_HASH tabela)
{
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

int indiceHash(int codigo)
{
    return (codigo % N);
}

int inserirHash(TB_HASH tabela, Paciente Paciente)
{
    int i = indiceHash(Paciente.codigo);
    Node *anterior = NULL;
    Node *e = tabela[i];
    while (e != NULL)
    {
        if (e->paciente.codigo == Paciente.codigo)
            return 0;
        anterior = e;
        e = e->proximo;
    }
    if (e == NULL)
    {
        e = malloc(sizeof(Paciente));
        e->paciente = Paciente;
        e->proximo = NULL;
        if (anterior == NULL)
            tabela[i] = e;
        else
            anterior->proximo = e;
    }
    return 1;
}

void imprimirTabela(TB_HASH tabela)
{
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        if (tabela[i] != NULL)
        {
            printf("\n");
            printf("[Paciente %d] \n", i + 1);
            printf("Codigo do paciente: %d\n", tabela[i]->paciente.codigo);
            printf("Nome: %s\n", tabela[i]->paciente.nome);
            printf("CPF: %s\n", tabela[i]->paciente.cpf);
            printf("Idade: %d\n", tabela[i]->paciente.idade);
        }
        else
            printf("\n[Paciente %d]: \nNULL\n", i + 1);
    }
}

void excluirHash(TB_HASH tabela, int cod)
{
    int i = indiceHash(cod);
    Node *e = tabela[i];
    Node *anterior = NULL;

    while (e != NULL && e->paciente.codigo != cod)
    {
        anterior = e;
        e = e->proximo;
    }
    if (e == NULL)
    {
        return;
    }
    else if (anterior != NULL)
    {
        anterior->proximo = e->proximo;
        free(e);
    }
    else
    {
        tabela[i] = e->proximo;
        free(e);
    }
}
