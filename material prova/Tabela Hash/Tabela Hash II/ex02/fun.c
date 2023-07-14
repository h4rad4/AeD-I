#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

#define N 5

void inicializarHash(TB_HASH tabela)
{
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

int indiceHash(int codigo)
{
    return codigo % N;
}

int inserirHash(TB_HASH tabela, Paciente paciente)
{
    int i = indiceHash(paciente.codigo);
    Node *anterior = NULL;
    Node *j = tabela[i];

    for (j; j != NULL; j++)
    {
        if (j->pac.codigo == paciente.codigo)
            return 0;
        anterior = j;
    }

    j = malloc(sizeof(Node));
    j->pac = paciente;
    j->next = NULL;

    if (anterior == NULL)
        tabela[i] = j;
    else
        anterior->next = j;

    return 1;
}

void imprimirHash(TB_HASH tabela)
{
    Node *j;

    for (int i = 0; i < N; i++)
    {
        if (tabela[i] != NULL)
        {
            j = tabela[i];
            printf("\n[Paciente: %d]", i);

            while (j != NULL)
            {
                printf("\n");
                printf("[Paciente %d] \n", i + 1);
                printf("Codigo do paciente: %d\n", tabela[i]->pac.codigo);
                printf("Nome: %s\n", tabela[i]->pac.nome);
                printf("CPF: %s\n", tabela[i]->pac.cpf);
                printf("Idade: %d\n", tabela[i]->pac.idade);
            }
        }
        else
            printf("\n[Paciente %d]: \nNULL\n", i + 1);
    }
}
