#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoArvore
{
    char dado;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

typedef struct Arvore
{
    NoArvore *raiz;
} Arvore;

typedef struct NoPilha
{
    NoArvore *dado;
    struct NoPilha *proximo;
} NoPilha;

typedef struct Pilha
{
    NoPilha *topo;
} Pilha;

Pilha *criar_pilha();
void empilhar(Pilha *pilha, NoArvore *dado);
NoArvore *desempilhar(Pilha *pilha);
NoArvore *topo(Pilha *pilha);
bool vazia(Pilha *pilha);
int prioridade(char op);
void inserir(Arvore *a, char dado);
void infixa_para_posfixa(char *infixa, char *posfixa);
NoArvore *criar_no(char dado);
NoArvore *construir_arvore(char *posfixa);
void liberar_arvore(NoArvore *no);
int avaliar(NoArvore *no);
void inverter(char *str);
void infixa_para_prefixa(char *infixa, char *prefixa);
