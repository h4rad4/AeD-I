#ifndef ex1_h
#define ex1_h
#define N 11

typedef struct
{
    int valor;
} REGISTRO;

typedef struct node
{
    REGISTRO reg;
    struct node *next;
} NODE;

typedef NODE *TB_HASH[N];

NODE *criarNo(int valor);
int funcaoHash(int valor);
void inserir(TB_HASH tabelaHash, int valor);
void exibirTabelaHash(TB_HASH tabelaHash);
void inicializarHash(TB_HASH tabela);

#endif
