typedef struct{
    char nome[20];
}Aluno;

typedef struct no{
    Aluno aluno;
    struct no *proximo;
    struct no *anterior;

}Node;

typedef struct{
    int tamanho;
    Node *head;

}Deque;

void inicializar(Deque *turma);
void inserirInicio(Deque *turma, Aluno novo);
void inserirFim(Deque *turma, Aluno novo);
void imprimir(Deque turma, char ordem, int pos);

void exibirDequeInicio(Deque *d);
void exibirDequeFim(Deque *d);

int inserirDequeFim(Deque *d, Aluno aluno);
int inserirDequeInicio(Deque *d, Aluno aluno);

int excluirDequeInicio(Deque *d, Aluno *aluno);
int excluirDequeFim(Deque *d, Aluno *aluno);

void reinicializarDeque(Deque *d);