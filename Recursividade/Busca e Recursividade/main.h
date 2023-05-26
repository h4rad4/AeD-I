#ifndef main_h
#define main_h

typedef struct StructLista
{
    int n;
    int *vetor;
} lista;

lista *criaVetor(lista *p, int n);
void buscaVetor(lista *p, int size);

#endif