#ifndef main_h
#define main_h

#define N 100
#define M_PI 3.14159265358979323846

typedef struct Paciente
{
    char *nome;
    char *cpf;
    int codigo, idade;

} Paciente;

typedef Paciente *TB_HASH[N];

float indiceHash(double codigo);
void inicializarHash(TB_HASH tabela);

#endif
