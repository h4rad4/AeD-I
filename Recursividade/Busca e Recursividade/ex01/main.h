#ifndef main_h
#define main_h

typedef struct StructLista
{
    int n;
    int *vetor;

} lista;

/* Manipulação do vetor*/
lista *criaVetor(int size);
void preencherVetor(lista *p);
void preencherVetorOrdenado(lista *p);
void printVetor(lista *p);
int liberaVetor(lista *p);

/* Buscas no vetor */
int buscaSequencial(lista *p, int value, int *cont);
int buscaSequencialOrdenada(lista *p, int value, int *cont);
int buscaBinariaIterativa (lista *p, int value, int *cont);
int buscaBinariaRecursiva(lista *p, int value, int left, int right, int *cont);

/* Operações no vetor*/
void imprimirMaiorElemento(lista *p);
void imprimirMenorElemento(lista *p);
void imprimirSomaElementos(lista *p);
void imprimirProdutoElementos(lista *p);

#endif
