typedef struct Paciente
{
    char nome[80];
    char cpf[12];
    int idade, codigo;

} Paciente;

typedef struct Node
{
    Paciente paciente;
    struct Node *direita;
    struct Node *esquerda;

} Node;

typedef struct Arvore
{
    Node *raiz;

} Arvore;

void inicializarArvore(Arvore arvore);
Node *criarNo(Paciente paciente);
Node *inserirNo(Node *raiz, Node *No);
int adiciona(Node *raiz, Node *novo);
int adiciona2(Arvore *arvore, Paciente p);
void listarNOS(Node *raiz);
void listarARVORE(Arvore *arvore);
