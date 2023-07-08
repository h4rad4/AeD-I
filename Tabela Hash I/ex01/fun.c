#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void inicializarHash(TB_HASH tabela)
{
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

float indiceHash(double codigo)
{
    /* Retorna o valor convertido para radianos */
    return sin((codigo * M_PI / 180));
}

int inserirHash(TB_HASH tabela, Paciente paciente)
{
    int i = indiceHash(paciente.codigo);

    for (i; tabela[i] != NULL; i++)
    {
        if (tabela[i]->codigo == paciente.codigo)
            return 0;
    }

    tabela[i] = malloc(sizeof(Paciente));
    *(tabela[i]) = paciente;
}

Paciente *buscaHash(TB_HASH tabela, int codigo)
{
    int i = indiceHash(codigo);

    for (i; tabela[i] != NULL; i++)
        return tabela[i];

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
            printf("[Paciente %d] \n", i);
            printf("Codigo do paciente: %d\n", tabela[i]->codigo);
            printf("Nome: %s\n", tabela[i]->nome);
            printf("CPF: %s\n", tabela[i]->cpf);
            printf("Idade: %d\n", tabela[i]->idade);
        }
        else
            printf("Paciente %d: \nNULL", i);
    }
}
