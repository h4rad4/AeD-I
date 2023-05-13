/*
---------------------------------------------------------------------------------------------------------
Criar um tipo abstrato de dados que represente uma pessoa, contendo: nome, data de nascimento e CPF.

- Crie uma função que receba um ponteiro para o TDA e preencha os dados da estrutura.
- Crie outra função que receba um ponteiro para o TDA e imprima os dados da estrutura.
- Crie um ponteiro para o TDA (no programa principal) e utilize as funções criadas.
---------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// 1- Criar um tipo abstrato de dados que represente uma pessoa, contendo: nome, data de nascimento e CPF.
typedef struct dados_pessoa
{
    char nome[36];
    char nascimento[36];
    char cpf[36];

} Dados_Pessoa;

int main(int argc, char const *argv[])
{
    struct dados_pessoa *Pessoa;
    Pessoa = (Dados_Pessoa *)malloc(sizeof(Dados_Pessoa));

    Preencher(Pessoa);
    Imprimir(Pessoa);

    return 0;
}

// 2- Crie uma função que receba um ponteiro para o TDA e preencha os dados da estrutura.
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

// 3- Crie outra função que receba um ponteiro para o TDA e imprima os dados da estrutura.

void Imprimir (Dados_Pessoa *Pessoa)
{
    printf("\n---------- DADOS ----------\n");

    printf("Nome: %s", Pessoa -> nome);
    printf("Data de nascimento: %s\n", Pessoa -> nascimento);
    printf("CPF: %s\n", Pessoa -> cpf);
}
