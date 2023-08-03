typedef struct Paciente
{
    int cod_pac;
    char nome[36];
    char cpf[36];
    int idade;

} Paciente;

typedef struct Node
{
    Paciente pac;
    Node *direita;
    Node *esquerda;
    int h;

} Node;

typedef struct Arvore
{
    Node *raiz;

} Arvore;