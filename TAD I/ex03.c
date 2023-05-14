/*
----------------------------------------------------------------------------------------
Para o exercício anterior crie um TDA para a data.

-Crie uma função que receba um ponteiro para o TDA e preencha os dados da estrutura.
-Crie outra função que receba um ponteiro para o TDA e imprima os dados da estrutura.
-Crie um ponteiro para o TDA (no programa principal) e utilize as funções criadas.
----------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// 1. Para o exercício anterior crie um TDA para a data.
typedef struct data
{
    int dia, mes, ano;

} Date;

typedef struct dados_pessoa
{
    Date date;
    char nome[36];
    char nascimento[36];
    char cpf[36];

} Dados_Pessoa;


int main(int argc, char const *argv[])
{
    struct dados_pessoa *Pessoa;
    Pessoa = malloc(sizeof(Dados_Pessoa));

    Preencher(Pessoa);
    ColetarData(Pessoa);
    Imprimir(Pessoa);

    return 0;
}

void Preencher(Dados_Pessoa *Pessoa)
{
    printf("---------- CADASTRO ----------\n");

    printf("Insira o nome. ");
    fgets(Pessoa -> nome, 36, stdin);
    fflush(stdin);

    printf("Insira a data de nascimento. ");
    fgets(Pessoa -> nascimento, 36, stdin);
    fflush(stdin);

    printf("Insira o CPF. ");
    fgets(Pessoa -> cpf, 36, stdin);
    fflush(stdin);

}

void Imprimir (Dados_Pessoa *Pessoa)
{
    printf("\n---------- DADOS ----------\n");

    printf("Nome: %s", Pessoa -> nome);
    printf("Data de nascimento: %s", Pessoa -> nascimento);
    printf("CPF: %s", Pessoa -> cpf);
    printf("Data do cadastro: %i/%i/%i", Pessoa -> date.dia, Pessoa -> date.mes, Pessoa -> date.ano);
}

// 2. Crie uma função que receba um ponteiro para o TDA e preencha os dados da estrutura.
void ColetarData(Dados_Pessoa *Pessoa)
{
    printf("Informe a data atual (DD/MM/YY). ");
    scanf("%i/%i/%i", &(Pessoa -> date.dia), &(Pessoa -> date.mes), &(Pessoa -> date.ano));
}