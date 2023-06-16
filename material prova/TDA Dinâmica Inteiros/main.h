#ifndef main_h
#define main_h

typedef struct Node
{
    int valor;
    struct Node *next;

} Node;

typedef struct
{
    Node *inicio;
    int tamanho;

} Lista;

void inicializarLista(Lista *lista);
void inserirElemento(Lista *lista, int elemento);
void removerElemento(Lista *lista, int elemento);
int buscarElemento(Lista *lista, int elemento);
int buscaBinaria(Lista *lista, int elemento);
int buscaBinariaRecursiva(Node *inicio, int elemento, int esquerda, int direita);
void inserirElementoOrdenado(Lista *lista, int elemento);
int obterQuantidadeElementos(Lista *lista);
void imprimirLista(Lista *lista);

#endif