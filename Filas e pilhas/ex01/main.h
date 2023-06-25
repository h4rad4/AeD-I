typedef struct AVIAO
{
    char nome[20];
    int codigo;

} AVIAO;

typedef struct NODE
{
    AVIAO aviao;
    struct NODE *proximo;

} NODE;

typedef struct FILA
{
    NODE *inicio;
    NODE *fim;
    int tamanho;

} FILA;

void inicializarFila(FILA *fila);
int inserirAviao(FILA *fila, AVIAO novo_aviao);
void imprimirAviao(FILA *fila);
void liberarAviao(FILA *fila);