#ifndef main_h
#define main_h

#define N 5
#define M_PI 3.14159265358979323846

typedef struct
{
    char *nome, *cpf;
    int idade, cod;

} Paciente;

typedef struct node
{
    Paciente pac;
    struct node *next;
} Node;

typedef NODE *TB_HASH[N];

int indiceHash(int cod);
void inicializaHash(TB_HASH tab);
void inserirHash(TB_HASH tab, PACIENTE pac);
void imprimirHash(TB_HASH tab);

#endif
