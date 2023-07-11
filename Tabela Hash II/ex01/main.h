#ifndef main_h
#define main_h

#define N 5
#define M_PI 3.14159265358979323846

typedef struct Paciente
{
    char *nome, *cpf;
    int idade, codigo, status;

} Paciente;

typedef Paciente *TB_HASH[N];

/* Função usada para obter o índice da tabela hash em que o elemento será inserido. *Procedimento de dispersão utilizado: sin(x)*/
int indiceHash(int codigo);

/* Inicializa a tabela com todos seus elementos NULL */
void inicializarHash(TB_HASH tabela);

/* Função usada para inserir um elemento na próxima posição avaliable da tabela hash*/
int inserirHash(TB_HASH tabela, Paciente paciente);

/* Função usada para imprimir os elementos da tabela hash */
void imprimirTabela(TB_HASH tabela);

/* Função usada para excluir um elemento da tabela hash */
int excluirHash(TB_HASH tabela, Paciente paciente);

/* Função usada para procurar um paciente na tabela hash */
Paciente *buscaHash(TB_HASH tabela, int codigo);

#endif
