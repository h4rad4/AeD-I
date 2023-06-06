typedef struct No {
    int elemento;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int quantidade;
} ListaLigada;


void inicializarLista(ListaLigada *lista);
void inserirFimLista(ListaLigada *lista, int elemento);
No *A_OperatorL1(No *inicio);
No *B_OperatorL1(No *inicio);
void imprimirLista(No *inicio);
void liberarLista(No *inicio);
