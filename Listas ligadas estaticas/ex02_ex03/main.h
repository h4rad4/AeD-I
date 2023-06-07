#define MAX 100

typedef struct
{
    int dado;
    int proximo;

} No;

typedef struct
{
    No nos[MAX];
    int cabeca;
    int cauda;
    int tamanho;

} Lista;

void inicializarLista(Lista *lista);
void inserirElemento(Lista *lista, int valor);
void exibirLista(Lista lista);
void copiarLista(Lista *l1, Lista *l2);
void concatenarListas(Lista *l1, Lista *l2);
Lista percorrerListaA(Lista lista);
Lista percorrerListaB(Lista lista);
Lista intercalarListas(Lista *l1, Lista *l2);