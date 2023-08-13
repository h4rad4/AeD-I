#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Arvore *criar_arvore()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No *criar_no()
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->num_chaves = 0;
    novo_no->prox = NULL;
    novo_no->folha = 1; // (é uma folha)

    for (int i = 0; i < MAX_CHAVES + 1; i++)
    {
        novo_no->filhos[i] = NULL;  // inicialmente não tem filhos
        novo_no->valores[i] = NULL; // inicialmente não tem dados (pacientes)
    }
    return novo_no;
}

// função para buscar um paciente na árvore B+
Paciente *buscar(No *raiz, int codigo)
{
    if (raiz == NULL)
        return NULL;

    // encontrar a posição onde o valor buscado estaria
    int i = 0;
    while (i < raiz->num_chaves && codigo > raiz->valores[i]->paciente->codigo)
        i++;

    // verificar se o valor buscado está na lista de valores do nó
    if (i < raiz->num_chaves && codigo == raiz->valores[i]->paciente->codigo)
        return raiz->valores[i]->paciente;
    else if (raiz->folha)
        return NULL; // O valor não está na árvore
    else
        return buscar(raiz->filhos[i], codigo); // Continuar a busca nos filhos apropriados
}

// Função para inserir um paciente em um nó folha
No *inserir_em_no_folha(No *no, int codigo, char *nome)
{
    int indice = no->num_chaves;

    while (indice > 0 && codigo < no->valores[indice - 1]->paciente->codigo)
    {
        no->valores[indice] = no->valores[indice - 1];
        no->chaves[indice] = no->chaves[indice - 1];
        indice--;
    }

    NoPaciente *novo_paciente_node = (NoPaciente *)malloc(sizeof(NoPaciente));
    novo_paciente_node->paciente = (Paciente *)malloc(sizeof(Paciente));
    novo_paciente_node->paciente->codigo = codigo;
    strcpy(novo_paciente_node->paciente->nome, nome);
    novo_paciente_node->prox = no->valores[indice];
    no->valores[indice] = novo_paciente_node;
    no->chaves[indice] = codigo;
    no->num_chaves++;

    return no;
}

// Função para dividir um nó folha cheio
No *dividir_no(No *pai, int indice_filho)
{
    No *filho_cheio = pai->filhos[indice_filho];
    No *novo_filho = criar_no();
    novo_filho->folha = filho_cheio->folha;

    int meio = filho_cheio->num_chaves / 2;
    int chave_promovida = filho_cheio->chaves[meio];

    for (int i = 0; i < meio; i++)
    {
        novo_filho->chaves[i] = filho_cheio->chaves[i + meio];
        novo_filho->valores[i] = filho_cheio->valores[i + meio];
        novo_filho->num_chaves++;
    }

    filho_cheio->num_chaves = meio;

    for (int i = pai->num_chaves; i > indice_filho; i--)
    {
        pai->filhos[i + 1] = pai->filhos[i];
    }

    pai->filhos[indice_filho + 1] = novo_filho;
    pai->chaves[indice_filho] = chave_promovida;
    pai->num_chaves++;

    return pai;
}
// Função para encontrar o índice de inserção de um paciente
int encontrar_indice_insercao(No *no, int codigo)
{
    int indice = 0;
    while (indice < no->num_chaves && codigo > no->valores[indice]->paciente->codigo)
        indice++;

    return indice;
}

// Função para inserir um paciente na árvore B+
No *inserir(No *raiz, int codigo, char *nome)
{
    if (raiz == NULL)
        raiz = criar_no();

    if (raiz->folha)
    {
        if (raiz->num_chaves < MAX_CHAVES)
            raiz = inserir_em_no_folha(raiz, codigo, nome);
        else
        {
            // Dividir o nó folha e ajustar a árvore
            raiz = dividir_no(raiz, 0); // Índice do único filho
            raiz = inserir(raiz, codigo, nome);
        }
    }
    else
    {
        int indice_filho = encontrar_indice_insercao(raiz, codigo);
        raiz->filhos[indice_filho] = inserir(raiz->filhos[indice_filho], codigo, nome);

        if (raiz->filhos[indice_filho]->num_chaves > MAX_CHAVES)
            raiz = dividir_no(raiz, indice_filho);
    }

    return raiz;
}

// Função para remover um paciente da árvore B+
No *remover_paciente(No *raiz, int codigo)
{
    if (raiz == NULL)
        return NULL;

    // Encontrar a posição da chave a ser removida
    int indice = 0;
    while (indice < raiz->num_chaves && codigo > raiz->valores[indice]->paciente->codigo)
        indice++;

    if (indice < raiz->num_chaves && codigo == raiz->valores[indice]->paciente->codigo)
    {
        // Remover o paciente e reorganizar a página folha, se necessário
        free(raiz->valores[indice]->paciente);
        free(raiz->valores[indice]);
        for (int i = indice; i < raiz->num_chaves - 1; i++)
        {
            raiz->valores[i] = raiz->valores[i + 1];
            raiz->chaves[i] = raiz->valores[i + 1]->paciente->codigo;
        }
        raiz->num_chaves--;
        return raiz;
    }
    else if (!raiz->folha)
    {
        // O paciente a ser removido está em uma página não-folha
        raiz->filhos[indice] = remover_paciente(raiz->filhos[indice], codigo);
        return raiz;
    }

    return raiz;
}

// Função para imprimir a árvore B+
void imprimir_arvore(No *raiz, int nivel)
{
    if (raiz != NULL)
    {
        int i;
        for (i = 0; i < raiz->num_chaves; i++)
        {
            imprimir_arvore(raiz->filhos[i], nivel + 1);
            for (int j = 0; j < nivel; j++)
                printf("   ");
            printf("Nome: %s\n", raiz->valores[i]->paciente->nome);
            printf("Codigo: %d\n", raiz->valores[i]->paciente->codigo);
            printf("Chave: %d\n", raiz->chaves[i]);
        }
        imprimir_arvore(raiz->filhos[i], nivel + 1);
    }
}
