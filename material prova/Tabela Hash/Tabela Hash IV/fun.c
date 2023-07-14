#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void inicializarHash(TB_HASH tabela)
{
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

NODE *criarNo(int valor)
{
    NODE *novoNo = (NODE *)malloc(sizeof(NODE));
    novoNo->reg.valor = valor;
    novoNo->next = NULL;

    return novoNo;
}

int funcaoHash(int valor)
{
    return (2 * valor + 5) % N;
}

void inserir(TB_HASH tabelaHash, int valor)
{
    int indice = funcaoHash(valor);
    NODE *novoNo = criarNo(valor);

    if (tabelaHash[indice] == NULL)
        tabelaHash[indice] = novoNo; // A posição da tabela está vazia, insere o novo nó diretamente
    else
    {
        // Já existe um nó na posição da tabela, encadeia o novo nó no final
        NODE *atual = tabelaHash[indice];
        while (atual->next != NULL)
            atual = atual->next;
            
        atual->next = novoNo;
    }
}

void exibirTabelaHash(TB_HASH tabelaHash)
{
    printf("Tabela Hash:\n");
    for (int i = 0; i < N; i++)
    {
        printf("[%d] -> ", i);

        NODE *atual = tabelaHash[i];
        while (atual != NULL)
        {
            printf("%d -> ", atual->reg.valor);
            atual = atual->next;
        }

        printf("NULL\n");
    }
}
