#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    Arvore arvore;
    inicializarArvore(&arvore);

    Paciente Pacientes[7] = {
        {"Albert Einstein", "00000000000", 290, 24},
        {"Robert Oppenheimer", "11111111111", 142 , 10},
        {"Marie Curie", "2222222222", 128, 32},
        {"Richard Feynman", "3333333333", 139, 5},
        {"Stephen Hawking", "44444444444", 114, 12},
        {"Max Planck", "55555555555", 321, 29},
        {"Werner Heisenberg", "66666666666", 231, 35}};

    for (int i = 0; i < 7; i++)
        adiciona2(&arvore, Pacientes[i]);

    listarArvore(&arvore);

    printf("Quantidade de nos = %d. \n", numeroNos(arvore.raiz));

    Node *searchNode;
    searchNode = buscar(&arvore, 24);

    printf("\n[Resultado da Busca] \n");

    printf("Endereco: %p\n", searchNode);
    printf("No esquerdo: %p\n", searchNode->esquerda);
    printf("No direito: %p\n", searchNode->direita);
    printf("Codigo: %d\n", searchNode->paciente.codigo);
    printf("Nome: %s\n", searchNode->paciente.nome);
    printf("\n");

    printf("Arvore em pre-ordem: \n");
    percorrer_pre_ordem(arvore.raiz);

    printf("Arvore em in-ordem: \n");
    percorrer_in_ordem(arvore.raiz);

    printf("Arvore em pos-ordem: \n");
    percorrer_pos_ordem(arvore.raiz);

    return 0;
}

/*
Criar um TDA para uma Estrutura de Dado tipo árvore binaria de busca usando uma implementação baseada em listas ligadas. Implementar as seguintes operações para o TDA

- Criar / inicializar a árvore;
- Inserir um elemento na árvore;
- Imprimir a árvore;
- Contar quantos elementos tem na árvore;
– Busca um elemento;
- Percorrer e mostrar as chaves dos elementos da árvore em Pré-ordem;
- Percorrer e mostrar as chaves dos elementos da árvore em In-ordem;
- Percorrer e mostrar as chaves dos elementos da árvore em Pós-ordem;

Utilizar o TDA para inserir os seguintes elementos na árvore
24, 10, 32, 5, 12, 29, 35

(⚠ os elementos foram inseridos como códigos de paciente)
*/
