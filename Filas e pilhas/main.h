typedef struct Aviao
{
    char nome[20];
    int codigo;

} AVIAO;

typedef struct NODE
{
    AVIAO aviao;
    struct NODE *proximo;

} NODE;

typedef struct Fila
{
    NODE *inicio;
    NODE *fim;
    int tamanho = 0;

} FILA;

