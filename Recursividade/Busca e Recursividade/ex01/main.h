#ifndef main_h
#define main_h

typedef struct StructLista
{
    int n;
    int *vetor;

} lista;

lista *criaVetor(int size);
void preencherVetor(lista *p);
void preencherVetorOrdenado(lista *p);
void printVetor(lista *p);
void liberaVetor(lista *p);

int buscaSequencial(lista *p, int value, int *cont);
int buscaSequencialOrdenada(lista *p, int value, int *cont);
int buscaBinariaIterativa (lista *p, int value, int *cont);
int buscaBinariaRecursiva(lista *p, int value, int left, int right);

void imprimirMaiorElemento(lista *p);
void imprimirMenorElemento(lista *p);

void imprimirSomaElementos(lista *p);
void imprimirProdutoElementos(lista *p);

#endif
