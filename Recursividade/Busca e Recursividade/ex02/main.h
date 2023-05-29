typedef struct structAluno{
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
} Aluno;

typedef struct structTurma{
    Aluno* alunos;
    int quantidade;
} Turma;

Turma *criarTurma(int qt);
Turma *preencherTurma(Turma *turma);

void imprimirAluno(Turma *turma);
void imprimirTurma(Turma *turma);

int buscaSequencial(Turma *turma, int cod);
int buscaBinariaRecursiva (Turma *turma, int cod, int inicio, int fim);

int liberarTurma(Turma *turma);