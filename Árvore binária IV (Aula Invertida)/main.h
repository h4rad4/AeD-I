#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAVES 4

typedef struct
{
    int codigo;
    char nome[50];

} Paciente;

// Definição para encadeamento dos pacientes
typedef struct NoPaciente
{
    Paciente *paciente;      // Ponteiro para um Paciente
    struct NoPaciente *prox; // Ponteiro para o próximo nó de paciente

} NoPaciente;

// Definição  para os nós da árvore B+
typedef struct No
{
    int num_chaves;                      // Número atual de chaves (pacientes) armazenados no nó
    int chaves[MAX_CHAVES + 1];          // Array para armazenar os códigos dos pacientes
    struct No *filhos[MAX_CHAVES + 2];   // Array de ponteiros para os filhos do nó
    NoPaciente *valores[MAX_CHAVES + 1]; // Array de ponteiros para NoPaciente (pacientes e seus dados)
    struct No *prox;                     // Ponteiro para o próximo nó (encadeamento na lista)
    int folha;                           // Indica se o nó é uma folha (1) ou não (0)

} No;

// Definição para a árvore B+
typedef struct
{
    No *raiz; // Ponteiro para a raiz da árvore

} Arvore;

No *criar_no();
Paciente *buscar(No *raiz, int codigo);
No *inserir(No *raiz, int codigo, char *nome);           // lida com todo o processo de inserção, incluindo a criação de um novo nó folha se necessário e a divisão de nós folha quando estão cheios
No *inserir_em_no_folha(No *no, int codigo, char *nome); // usada quando a árvore já possui um nó folha disponível para inserção e não há necessidade de dividir nenhum nó.
No *remover_paciente(No *raiz, int codigo);
void imprimir_arvore(No *raiz, int nivel);
No *dividir_no(No *pai, int indice_filho);
int encontrar_indice_insercao(No *no, int codigo);
Arvore *criar_arvore();
