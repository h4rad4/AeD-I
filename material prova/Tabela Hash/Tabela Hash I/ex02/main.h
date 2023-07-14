#ifndef main_h
#define main_h

#define N 5
#define M_PI 3.14159265358979323846

typedef struct
{
    char *nome;
    char *cpf;
    int idade;
    int cod;
} PACIENTE;

typedef struct node
{
    PACIENTE pac;
    struct node *next;
} NODE;

typedef NODE *TB_HASH[N];

int m_hash(int cod);
void inicializahash(TB_HASH tab);
void inserir(TB_HASH tab, PACIENTE pac);
void mostrarhash(TB_HASH tab);
PACIENTE *busca(TB_HASH tab, int cod);

#endif
