#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    Arvore arvore;
    inicializarArvore(arvore);

    Paciente Pacientes[10] = {
        {"Albert Einstein", "00000000000", 290, 123},
        {"Robert Oppenheimer", "11111111111", 456},
        {"Marie Curie", "2222222222", 128, 789},
        {"Richard Feynman", "3333333333", 987},
        {"Stephen Hawking", "44444444444", 654},
        {"Max Planck", "55555555555", 321},
        {"Werner Heisenberg", "66666666666", 147},
        {"Carl Sagan", "77777777777", 130, 963},
        {"Galileo Galisei", "88888888888", 720, 258},
        {"Isaac Newton", "99999999999", 350, 852}};

    for (int i = 0; i < 10; i++)
        adiciona2(&arvore, Pacientes[i]);

    listarARVORE(&arvore);

    return 0;
}

/*
Criar um TDA para uma Estrutura de Dado tipo árvore binaria de busca usando uma implementação baseada em listas ligadas. Implementar as seguintes operações para o TDA

- Criar / inicializar a árvore; ✅
- Inserir um elemento na árvore; ✅
- Imprimir a árvore; ✅
- Contar quantos elementos tem na árvore;
– Busca um elemento;
- Percorrer e mostrar as chaves dos elementos da árvore em Pré-ordem;
- Percorrer e mostrar as chaves dos elementos da árvore em In-ordem;
- Percorrer e mostrar as chaves dos elementos da árvore em Pós-ordem;

Utilizar o TDA para inserir os seguintes elementos na árvore
24, 10, 32, 5, 12, 29, 35
*/
