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
    /* "fmod" calcula o mod de um valor de ponto flutuante */
    // return fmod(sin((codigo * M_PI / 180)), N);
    return codigo % N;
}

int inserirHash(TB_HASH tabela, Paciente paciente)
{
    int i = indiceHash(paciente.codigo);

    for (i; tabela[i] != NULL && tabela[i]->status != -1; i++)
    {
        if (tabela[i]->codigo == paciente.codigo)
            return 0;
    }

    tabela[i] = malloc(sizeof(Paciente));
    *(tabela[i]) = paciente;

    tabela[i]->status = 1;

    return 0;
}

int excluirHash(TB_HASH tabela, Paciente paciente)
{
    int i = indiceHash(paciente.codigo);

    if (tabela[i] != NULL && tabela[i]->codigo == paciente.codigo && tabela[i]->status == 1)
    {
        tabela[i]->status = -1;
        free(tabela[i]);
        tabela[i] = NULL;

        return 1;
    }

    return 0;
}

Paciente *buscaHash(TB_HASH tabela, int codigo)
{
    int i = indiceHash(codigo);

    for (i; tabela[i] != NULL; i++)
    {
        if (tabela[i]->codigo == codigo)
            return tabela[i];
    }

    return NULL;
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
            printf("Codigo do paciente: %d\n", tabela[i]->codigo);
            printf("Nome: %s\n", tabela[i]->nome);
            printf("CPF: %s\n", tabela[i]->cpf);
            printf("Idade: %d\n", tabela[i]->idade);
        }
        else
            printf("\n[Paciente %d]: \nNULL\n", i+1);
    }
}
