/*
Em uma Lista ligada Estática de alunos (cada aluno tem código, nome, idade e número de filhos) com os alunos
No	código	nome	idade	número de filhos
1	001	    Daniel	21	0
2	002	    Suza	19	0
3	003	    Danilo	24	1
4	004	    Camila	18	0
5	005	    Carlos	22	1

inseridos em essa ordem.
a)	Criar e testar uma operação no TDA para retornar o aluno com maior idade.
b)	Imprimir todos os dados do aluno com maior idade.
(pode utilizar os TDAs e as operações definidas nos exercícios durante todo o período)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 100

typedef struct
{
    int codigo;
    char nome[50];
    int idade;
    int numFilhos;
    int proximo;
} Aluno;

typedef struct
{
    Aluno elementos[MAX_ELEMENTOS];
    int *primeiro;
    int *proximo;
    int tamanho;
} Lista;

void criarLista(Lista *lista)
{
    lista->primeiro = NULL;
    lista->proximo = &lista->elementos[0].proximo;
    lista->tamanho = 0;

    for (int i = 0; i < MAX_ELEMENTOS - 1; i++)
    {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_ELEMENTOS - 1].proximo = NULL;
}

Lista *inserirAluno(Lista *lista, Aluno aluno)
{
    
}

int main(int argc, char const *argv[])
{
    Lista lista;

    Aluno Al1 = {1, 001, "Daniel", 21, 0};
    Aluno Al2 = {2, 002, "Suza", 19, 0};
    Aluno Al3 = {3, 003, "Danilo", 24, 1};
    Aluno Al4 = {4, 004, "Camila", 18, 0};
    Aluno Al5 = {5, 005, "Carlos", 22, 1};

    inserirAluno(&lista, Al1);
    inserirAluno(&lista, Al2);
    inserirAluno(&lista, Al3);
    inserirAluno(&lista, Al4);
    inserirAluno(&lista, Al5);

    printf("Aluno mais velho: ");
    retornarAluno(&lista);

    return 0;
}