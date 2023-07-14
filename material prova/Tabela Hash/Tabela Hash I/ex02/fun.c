#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int m_hash(int cod)
{
    return (cod % N);
}

void inicializahash(TB_HASH tab)
{
    int i;
    for (i = 0; i < N; i++)
    {
        tab[i] = NULL;
    }
}

void inserir(TB_HASH tab, PACIENTE pac)
{
    int h = m_hash(pac.cod);
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }
    newNode->pac = pac;
    newNode->next = NULL;

    if (tab[h] == NULL)
    {
        tab[h] = newNode;
    }
    else
    {
        NODE *current = tab[h];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void mostrarhash(TB_HASH tab)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (tab[i] != NULL)
        {
            NODE *current = tab[i];
            printf("\nPaciente: %d\n", i);
            while (current != NULL)
            {
                printf("Codigo do Paciente: %d\n", current->pac.cod);
                printf("Nome: %s\n", current->pac.nome);
                printf("CPF: %s\n", current->pac.cpf);
                printf("Idade: %d\n", current->pac.idade);
                current = current->next;
            }
        }
        else
        {
            printf("Paciente: %d NULL\n", i);
        }
    }
}

PACIENTE *busca(TB_HASH tab, int cod)
{
    int h = m_hash(cod);
    NODE *current = tab[h];
    while (current != NULL)
    {
        if (current->pac.cod == cod)
        {
            return &(current->pac);
        }
        current = current->next;
    }
    return NULL;
}
