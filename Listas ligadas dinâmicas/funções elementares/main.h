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