#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    Arvore *arvore = criar_arvore();

    // Inserção de pacientes na árvore
    arvore->raiz = inserir(arvore->raiz, 1, "Ana Banana");
    arvore->raiz = inserir(arvore->raiz, 2, "Joao Pao");
    arvore->raiz = inserir(arvore->raiz, 3, "Isabela Geleia");
    arvore->raiz = inserir(arvore->raiz, 4, "Gabriela Guitarra");
    arvore->raiz = inserir(arvore->raiz, 5, "Gabriela Guitarra");


    // Busca de paciente na árvore
    int codigo_busca = 1;
    Paciente *paciente_encontrado = buscar(arvore->raiz, codigo_busca);

    printf("Buscando paciente de codigo %d... \n", codigo_busca);
    if (paciente_encontrado != NULL)
        printf("Paciente encontrado: Codigo %d, Nome: %s\n", paciente_encontrado->codigo, paciente_encontrado->nome);
    else
        printf("Paciente com codigo %d nao encontrado.\n", codigo_busca);

    printf("[Imprimindo a arvore] \n");
    imprimir_arvore(arvore->raiz, 0);

    // Remoção de paciente da árvore
    int codigo_remocao = 2;
    arvore->raiz = remover_paciente(arvore->raiz, codigo_remocao);

    printf("[Imprimindo a arvore depois da exclusao] \n");
    imprimir_arvore(arvore->raiz, 0);

    return 0;
}
