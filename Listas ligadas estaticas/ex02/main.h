#define MAX 100

typedef struct
{
    int dado;
    int proximo; // Índice do próximo elemento (-1 se for o último elemento)

} No;

typedef struct
{
    No nos[MAX];
    int cabeca;  // Índice do primeiro elemento (-1 se a lista estiver vazia)
    int tamanho; // Tamanho atual da lista
    int cauda;   // Índice do último elemento (-1 se a lista estiver vazia)

} Lista;

void inicializarLista(Lista *lista);
void inserirElemento(Lista *lista, int valor);
void exibirLista(Lista lista);
void copiarLista(Lista *l1, Lista *l2);
void concatenarListas(Lista *l1, Lista *l2);
Lista percorrerListaA(Lista lista);
Lista percorrerListaB(Lista lista);
Lista intercalarListas(Lista *l1, Lista *l2);