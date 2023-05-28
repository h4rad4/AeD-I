#ifndef main_h
#define main_h

typedef struct StructLista
{
    int n;
    int *vetor;
    int *vetor2;

} lista;

lista *criaVetor(lista *p, int size1, int size2);
int buscaSequencial(lista *p, int size1, int size2);

#endif
