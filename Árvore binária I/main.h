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

void inicializarArvore(Arvore *arvore);
Node *criarNo(Paciente paciente);
Node *inserirNo(Node *raiz, Node *No);
int adiciona(Arvore *arvore, Node *novo);
int adiciona2(Arvore *arvore, Paciente p);
void listarNOS(Node *raiz);
void listarArvore(Arvore *arvore);
int numeroNos(Node *raiz);
Node *contem(Node *raiz, int codigo);
Node *buscar(Arvore *arvore, int codigo);
void percorrer_pre_ordem(Node *raiz);
void percorrer_in_ordem(Node *raiz);
void percorrer_pos_ordem(Node *raiz);