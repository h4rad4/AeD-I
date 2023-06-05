/*
-----------------------------------------------------------------------------------------------------------
1. Criar um TDA para uma lista ligada estática dos alunos de uma turma. Cada aluno está representado pela
matricula do aluno (um valor inteiro), o nome e a idade. A quantidade máxima de alunos em uma turma é 100.
Usar a matricula como chave.

Implementar e testar as seguintes operações sobre esse TDA:

•    Inicializar a lista.
•    Liberar a lista.
•    Retornar a quantidade de elementos válidos na lista.
•    Retornar se a lista está cheia.
•    Retornar se a lista está vazia.
•    Exibir os elementos da lista.
•    Inserir um elemento de forma ordenada (ascendente) na lista.
•    Excluir um elemento da lista pelo valor mantendo a lista ordenada.
•    Alterar o valor de uma matricula (de acordo ao valor) mantendo a lista ordenada.
-----------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MAX 100

int main()
{
    ListaAlunos lista;
    inicializarLista(&lista);

    // Inserir elementos
    Aluno aluno1 = {123, "Joao", 20};
    Aluno aluno2 = {456, "Maria", 22};
    Aluno aluno3 = {789, "Pedro", 19};
    inserirAluno(&lista, aluno1);
    inserirAluno(&lista, aluno2);
    inserirAluno(&lista, aluno3);

    printf("\n[Lista inicial]\n");
    imprimirLista(&lista);

    // Alterando matricula
    alterarMatricula(&lista, 456, 111);

    printf("\n[Lista apos alteracao]\n");
    imprimirLista(&lista);

    // Liberando lista
    liberarLista(&lista);

    return 0;
}
