#ifndef main_h
#define main_h

#define N 5
#define M_PI 3.14159265358979323846

typedef struct Paciente
{
    char *nome;
    char *cpf;
    int idade;
    int codigo;

} Paciente;

typedef Paciente *TB_HASH[N];

/* Função usada para obter o índice da tabela hash em que o elemento será inserido. *Procedimento de dispersão utilizado: sin(x)*/
float indiceHash(double codigo);

/* Inicializa a tabela com todos seus elementos NULL */
void inicializarHash(TB_HASH tabela);

/* Função usada para inserir um elemento na próxima posição avaliable da tabela hash*/
int inserirHash(TB_HASH tabela, Paciente paciente);

/* Função usada para imprimir os elementos da tabela hash */
void imprimirTabela(TB_HASH tabela);

#endif
