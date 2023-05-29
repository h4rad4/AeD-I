#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    int qt;

    printf("Insira a quantidade de alunos da turma. ");
    scanf("%d", &qt);

    Turma *turma = criarTurma(qt);
    preencherTurma(turma);

    int cod;

    printf("Busca Sequencial: Insira o codigo a ser buscado. ");
    scanf("%d", &cod);

    printf("-> Busca Sequencial: Aluno encontrado na posicao %d.\n", buscaSequencial(turma, cod));
    printf("-> Busca Binaria: Aluno encontrado na posicao %d.\n", buscaBinariaRecursiva(turma, cod, 0, turma->quantidade - 1));

    imprimirTurma(turma);

    if (liberarTurma(turma) != -1)
        printf("\tLiberado!");

    return 0;
}
