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
bool vazia(Pilha *pilha);
NoArvore *desempilhar(Pilha *pilha);
NoArvore *topo(Pilha *pilha);
NoArvore *criar_no(char dado);
NoArvore *construir_arvore(char *posfixa);
void inserir(Arvore *a, char dado);
void liberar_arvore(NoArvore *no);
int prioridade(char op);
void infixa_para_prefixa(char *infixa, char *prefixa);
void infixa_para_posfixa(char *infixa, char *posfixa);
void inverter(char *str);
int avaliar(NoArvore *no);