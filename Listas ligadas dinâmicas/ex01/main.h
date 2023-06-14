#ifndef main_h
#define main_h

typedef struct Node
{
    int valor;
    struct Node *proximo;
    struct Node *anterior;

} Node;

typedef struct Lista
{
    Node *inicio;

} List;

Node *inserirInicioLista(Node *head, int valor);
void imprimirLista(Node *node);
void criarListaOrdenada(Node* listaL, Node** listaK);

#endif