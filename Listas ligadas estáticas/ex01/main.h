#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    char nome[50];
    int idade;

} Aluno;

typedef struct No {
    Aluno aluno;
    struct No *proximo;

} No;

typedef struct ListaAunos{
    No *inicio;
    int quantidade;

} ListaAlunos;

int tamanhoLista(ListaAlunos *lista);
void inicializarLista(ListaAlunos *lista);
void liberarLista(ListaAlunos *lista);
void inserirAluno(ListaAlunos *lista, Aluno aluno);
void imprimirLista(ListaAlunos *lista);
void excluirAluno(ListaAlunos *lista, int mat);
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);
