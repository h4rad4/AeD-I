#ifndef main_h
#define main_h

typedef struct Node {
    int valor;
    struct Node *proximo;

} Node;

typedef struct Lista
{
    Node *inicio;
    
} Lista;

#endif

/* Imprime os elementos da lista */
void imprimeLista(Lista *p)

/* Verifica se a lista está vazia (0) ou não (1) */
int estadoLista(Lista *p);

/* Busca um valor fornecido na lista */
void buscaLista(Lista *p, int value);