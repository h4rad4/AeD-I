#ifndef ex1_h
#define ex1_h
#define N 5

typedef struct Paciente
{
    char *nome, *cpf;
    int idade, codigo;

} Paciente;

typedef struct aux
{
    Paciente paciente;
    struct aux *proximo;

} Node;

typedef Node *TB_HASH[N];

int indiceHash(int codigo);
void inicializarHash(TB_HASH tabela);
int inserirHash(TB_HASH tabela, Paciente Paciente);
void imprimirTabela(TB_HASH tabela);
void excluirHash(TB_HASH tabela, int cod);

#endif
