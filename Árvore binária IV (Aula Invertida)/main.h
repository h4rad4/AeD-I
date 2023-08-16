#include <stdio.h>
#include <stdlib.h>

#define ordem 5

typedef struct Arvore
{
    int *valor;
    int quantidade;
    int ultimo;
    struct Arvore **ramo;
    struct Arvore *proxima_folha;

} Arvore;

Arvore *criar_no(int ultimo);
int indice(Arvore *no, int key);
void split(Arvore *parent, int child_index);
void inserir_vago(Arvore *no, int key);
void inserir(Arvore **raiz, int key);
void imprimirArvore(Arvore *no);
int maior_elemento(Arvore *no);
int menor_elemento(Arvore *no);
void junta_ramos(Arvore *parent, int child_index);
void mover_da_direita(Arvore *parent, int child_index);
void mover_da_esquerda(Arvore *parent, int child_index);
void exclui_elemento(Arvore *no, int key);
void excluir(Arvore **raiz, int key);
int buscar(Arvore *no, int key);
void ligar_folhas(Arvore *folha_atual, Arvore *proximo);
void imprimirFolhas(Arvore *no);
