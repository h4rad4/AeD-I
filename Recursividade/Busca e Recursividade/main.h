#ifndef main_h
#define main_h

typedef struct StructLista
{
    int n;
    int *vetor;
    int *vetor2;

} lista;

lista *criaVetor(lista *p, int n);
void buscaVetor(lista *p, int size);
lista *criaVetor2(lista *p, int n);

#endif