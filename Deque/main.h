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
    Node *cabeca;

}DEQUE;

void inicializar(DEQUE *turma);
void inserirInicio(DEQUE *turma, Aluno novo);
void inserirFim(DEQUE *turma, Aluno novo);
void imprimir(DEQUE turma, char ordem, int pos);