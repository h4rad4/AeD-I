#ifndef main_h
#define main_h

#define N 5
#define M_PI 3.14159265358979323846

typedef struct
{
    char *nome, *cpf;
    int idade, codigo;

} Paciente;

typedef struct node
{
    Paciente pac;
    struct node *next;
} Node;

typedef Node *TB_HASH[N];

void inicializarHash(TB_HASH tabela);
int indiceHash(int codigo);
int inserirHash(TB_HASH tabela, Paciente paciente);
void imprimirHash(TB_HASH tabela);

#endif
