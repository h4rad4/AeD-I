#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Turma *criarTurma(int qt)
{
    printf("Alocando memoria... ");

    Turma *turma = malloc(sizeof(Turma));
    turma->quantidade = qt;

    turma->alunos = malloc(qt * sizeof(Aluno));

    printf("Alocado!\n \n");

    return turma;
}

int liberarTurma(Turma *turma)
{
    printf("Liberando memoria alocada...");
    free(turma->alunos);
    free(turma);

    return 1;
}

Turma *preencherTurma(Turma *turma)
{
    for (int i = 0; i < turma->quantidade; i++)
    {
        printf("Aluno %d:\n", i + 1);

        printf("Insira o codigo do aluno. ");
        scanf("%d", &(turma->alunos[i].codigo));

        printf("Insira o nome do aluno. ");
        scanf("%s", turma->alunos[i].nome);

        printf("Insira a idade do aluno. ");
        scanf("%d", &(turma->alunos[i].idade));

        printf("Insira o coeficiente do aluno. ");
        scanf("%f", &(turma->alunos[i].coeficiente));

        printf("\n");
    }

    return turma;
}

void imprimirAluno(Turma *turma)
{
    printf("\n----- Dados do aluno -----\n");

    printf("Nome: %s\n", turma->alunos->nome);
    printf("Idade: %d\n", turma->alunos->idade);
    printf("Coeficiente: %.2f\n", turma->alunos->coeficiente);
    printf("Codigo: %d\n", turma->alunos->codigo);
}

int buscaSequencial(Turma *turma, int cod)
{
    for (int i = 0; i < turma->quantidade; i++)
    {
        if (turma->alunos[i].codigo == cod)
        {
            imprimirAluno(turma);
            return i + 1;
        }
    }

    printf(" (Not found)");
    return -1;
}

int buscaBinariaRecursiva(Turma *turma, int cod, int inicio, int fim)
{
    if (inicio > fim)
    {
        printf(" (Not found)");
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (turma->alunos[meio].codigo == cod)
    {
        imprimirAluno(turma);
        return meio+1;
    }

    else if (turma->alunos[meio].codigo < cod)
        return buscaBinariaRecursiva(turma, cod, meio + 1, fim);

    else
        return buscaBinariaRecursiva(turma, cod, inicio, meio - 1);
}

void imprimirTurma(Turma *turma)
{
    printf("\n----- Alunos da turma -----\n");

    for (int i = 0; i < turma->quantidade; i++)
    {
        printf("[Aluno %d] \n", i + 1);
        printf("Nome: %s\n", turma->alunos[i].nome);
        printf("Idade: %d\n", turma->alunos[i].idade);
        printf("Coeficiente: %.2f\n", turma->alunos[i].coeficiente);
        printf("Codigo: %i\n", turma->alunos[i].codigo);
        printf("\n");
    }
}
