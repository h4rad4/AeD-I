/*
Em uma Lista ligada Estática de alunos (cada aluno tem código, nome, idade e número de filhos) com os alunos
No	código	nome	idade	número de filhos
1	001	    Daniel	21	0
2	002	    Suza	19	0
3	003	    Danilo	24	1
4	004	    Camila	18	0
5	005	    Carlos	22	1

inseridos em essa ordem.
a)	Criar e testar uma operação no TDA para retornar o aluno com maior idade.
b)	Imprimir todos os dados do aluno com maior idade.
(pode utilizar os TDAs e as operações definidas nos exercícios durante todo o período)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 10

typedef struct
{
    int cod_aluno;
    char *nome;
    int idade;
    int filhos;
} ALUNO;

typedef struct
{
    ALUNO alun;
    int proximo;

} ELEMENTO;

typedef struct
{
    ELEMENTO turma[MAX];
    int inicio;
    int atual;

} LISTATURMA;

void inicializarturma(LISTATURMA *m)
{
    int i;
    for (i = 0; i < MAX - 1; i++)
    {
        m->turma[i].proximo = i + 1;
    }
    m->turma[MAX - 1].proximo = -1;
    m->inicio = -1;
    m->atual = 0;
}

int tamanholista(LISTATURMA *m)
{
    int tam = 0;
    int i = m->inicio;
    while (i != -1)
    {
        tam++;
        i = m->turma[i].proximo;
    }
    return tam;
}

int buscarmatricula(LISTATURMA *m, int cod_aluno)
{
    int i = m->inicio;
    while (i != -1 && m->turma[i].alun.cod_aluno < cod_aluno)
    {
        i = m->turma[i].proximo;
    }
    if (i != -1 && m->turma[i].alun.cod_aluno == cod_aluno)
    {
        return 1;
    }
    else
        return -1;
}

int obterno(LISTATURMA *m)
{
    int disp = m->atual;
    if (m->atual != -1)
    {
        m->atual = m->turma[disp].proximo;
    }
    return disp;
}

bool inserirAluno_Ordenado(LISTATURMA *m, ALUNO novo_aluno)
{
    if (m->atual == -1)
    {
        return false;
    }

    int i = m->inicio;
    int pos_inserir = -1;
    while ((i != -1) && (novo_aluno.cod_aluno > m->turma[i].alun.cod_aluno))
    {
        pos_inserir = i;
        i = m->turma[i].proximo;
    }

    if (i != -1 && novo_aluno.cod_aluno == m->turma[pos_inserir].alun.cod_aluno)
    {
        return false;
    }

    i = obterno(m);
    m->turma[i].alun = novo_aluno;
    if (pos_inserir == -1)
    {
        m->turma[i].proximo = m->inicio;
        m->inicio = i;
    }
    else
    {
        m->turma[i].proximo = m->turma[pos_inserir].proximo;
        m->turma[pos_inserir].proximo = i;
    }
}

bool inserirAluno_Nao_Ordenado(LISTATURMA *lista, ALUNO novo_aluno)
{
    if (lista->atual == -1)
    {
        return false;
    }

    int i = obterno(lista);

    if (i == 0)
    {
        lista->turma[0].alun = novo_aluno;
        lista->inicio = 0;
        lista->turma[0].proximo = -1;
    }
    else
    {
        lista->turma[i].alun = novo_aluno;
        lista->turma[i - 1].proximo = i;
        lista->turma[i].proximo = -1;
    }
}

void mostrarlista(LISTATURMA *lista)
{
    int i = lista->inicio;
    while (i != -1)
    {
        printf("Aluno: %d\n", i);
        printf("Codigo Aluno: %d\n", lista->turma[i].alun.cod_aluno);
        printf("Nome: %s\n", lista->turma[i].alun.nome);
        printf("Idade  %d\n", lista->turma[i].alun.idade);
        printf("Filhos: %d\n", lista->turma[i].alun.filhos);
        i = lista->turma[i].proximo;
    }
}

bool excluiraluno(LISTATURMA *m, int codA)
{

    int i = m->atual;
    int anterior = -1;

    while (i != -1 && m->turma[i].alun.cod_aluno < codA)
    {
        anterior = i;
        i = m->turma[i].proximo;
    }
    if (i != -1 && m->turma[i].alun.cod_aluno != codA)
    {
        return false;
    }
    if (anterior == -1)
    {
        m->inicio = m->turma[i].proximo;
    }
    else
    {
        m->turma[anterior].proximo = m->turma[i].proximo;
    }

    alocar(m, i);
    return true;
}

void alocar(LISTATURMA *m, int i)
{

    m->turma[i].proximo = m->atual;
    m->atual = i;
}

int MaiorIdade(LISTATURMA *lista)
{
    int i = lista->inicio;
    int IdadeM = lista->turma[i].alun.idade;
    int pos;
    while (i != -1)
    {

        if (lista->turma[i].alun.idade > IdadeM)
        {
            IdadeM = lista->turma[i].alun.idade;
            pos = i;
        }
        i = lista->turma[i].proximo;
    }
    return pos;
}

int main()
{
    LISTATURMA m;
    int PosMIdade;
    inicializarturma(&m);
    printf("%d \n", tamanholista(&m));

    ALUNO aluno1 = {001, "Daniel", 21, 0};

    inserirAluno_Nao_Ordenado(&m, aluno1);
    ALUNO aluno2 = {002, "Suza", 19, 0};

    inserirAluno_Nao_Ordenado(&m, aluno1);
    ALUNO aluno3 = {003, "Danilo", 24, 1};

    inserirAluno_Nao_Ordenado(&m, aluno1);
    ALUNO aluno4 = {004, "Camila", 18, 0};

    inserirAluno_Nao_Ordenado(&m, aluno1);
    ALUNO aluno5 = {005, "Carlos", 22, 1};

    inserirAluno_Nao_Ordenado(&m, aluno1);
    mostrarlista(&m);

    PosMIdade = MaiorIdade(&m);
    printf("Cod: %d, Nome: %s, Idade: %d, Filhos: %d \n", m.turma[PosMIdade].alun.cod_aluno, m.turma[PosMIdade].alun.nome, m.turma[PosMIdade].alun.idade, m.turma[PosMIdade].alun.filhos);

    time_t now;
    time(&now);

    printf("Data e hora de entrega %s", ctime(&now));

    return 0;
}
