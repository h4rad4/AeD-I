#ifndef main_h
#define main_h

typedef struct Node
{
    int base, exp;
    struct Node *proximo;

} Node;

typedef struct Lista
{
    Node *inicio;

} Lista;

Lista *criarPolinomio(Lista *p, int base, int exp);
Lista *somaPolinomio(Lista *p1, Lista *p2);
void imprimirPolinomio(Lista *p);


#endif