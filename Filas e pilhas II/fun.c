#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int isOperador(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Verifica se o caractere é um operador
}

int getPrioridade(char c)
{
    if (c == '+' || c == '-')
        return 1; // Retorna a prioridade 1 para os operadores + e -
    else if (c == '*' || c == '/')
        return 2; // Retorna a prioridade 2 para os operadores * e /
    return 0;     // Retorna 0 para outros caracteres (números ou outros)
}

void inverter_string(char *str)
{
    int tamanho = strlen(str);
    for (int i = 0; i < tamanho / 2; i++)
    {
        char temp = str[i];
        str[i] = str[tamanho - 1 - i];
        str[tamanho - 1 - i] = temp;
    }
    // Inverte uma string trocando os caracteres da posição inicial com a posição final
}

Expressao criar_expressao()
{
    Expressao expressao;
    expressao.expressao[0] = '\0';
    expressao.tamanho = 0;
    return expressao; // Cria uma expressão vazia
}

void apagar_expressao(Expressao *expressao)
{
    expressao->expressao[0] = '\0';
    expressao->tamanho = 0; // Apaga uma expressão, definindo seu tamanho como zero e limpando o conteúdo
}

void imprimir_expressao(const Expressao *expressao)
{
    printf("Expressao: %s\n", expressao->expressao); // Imprime a expressão
}

void adicionar_elemento(Expressao *expressao, const char *elemento)
{
    int tamanho_atual = expressao->tamanho;
    int novo_tamanho = tamanho_atual + strlen(elemento) + 2; // Calcula o novo tamanho considerando o elemento e os espaços extras

    if (novo_tamanho <= 200) // Verifica se há espaço suficiente para adicionar o elemento
    {
        strcat(expressao->expressao, " ");      // Adiciona um espaço em branco antes do elemento
        strcat(expressao->expressao, elemento); // Adiciona o elemento à expressão
        expressao->tamanho = novo_tamanho - 1;  // Atualiza o tamanho, excluindo o caractere nulo
    }
    else
    {
        printf("Erro: Expressao excedeu o tamanho maximo\n"); // Imprime uma mensagem de erro se a expressão exceder o tamanho máximo
    }
}

void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa)
{
    char pilha[200][200];
    int topo = -1;

    char *expressao_posfixa_temp = strdup(expressao_posfixa->expressao); // Cria uma cópia temporária da expressão posfixa
    char *termo = strtok(expressao_posfixa_temp, " ");                   // Divide a expressão em termos separados por espaços
    while (termo != NULL)
    {
        if (isOperador(termo[0])) // Se o termo for um operador
        {
            while (topo >= 0 && isOperador(pilha[topo][0]) && getPrioridade(pilha[topo][0]) >= getPrioridade(termo[0]))
            {
                // Enquanto houver operadores no topo da pilha com prioridade maior ou igual ao termo atual
                adicionar_elemento(expressao_prefixa, pilha[topo]); // Adiciona o operador no topo da pilha à expressão prefixa
                topo--;                                             // Remove o operador do topo da pilha
            }
            strcpy(pilha[++topo], termo); // Adiciona o termo atual à pilha
        }
        else // Se o termo for um número
        {
            adicionar_elemento(expressao_prefixa, termo); // Adiciona o número à expressão prefixa
        }
        termo = strtok(NULL, " "); // Avança para o próximo termo
    }

    while (topo >= 0)
    {
        adicionar_elemento(expressao_prefixa, pilha[topo]); // Adiciona os operadores restantes da pilha à expressão prefixa
        topo--;
    }

    inverter_string(expressao_prefixa->expressao); // Inverte a expressão prefixa para a ordem correta

    free(expressao_posfixa_temp); // Libera a memória alocada para a expressão posfixa temporária
}

float resultado_expressao(const Expressao *expressao)
{
    char operadores[] = "+-*/";
    float pilha[200];
    int topo = -1;

    char expressao_temp[200];
    strcpy(expressao_temp, expressao->expressao);

    char *termo = strtok(expressao_temp, " "); // Divide a expressão em termos separados por espaços
    while (termo != NULL)
    {
        if (strchr(operadores, termo[0]) == NULL) // Se o termo não for um operador
        {
            pilha[++topo] = atof(termo); // Converte o termo em um número e adiciona à pilha
        }
        else // Se o termo for um operador
        {
            if (topo < 1)
            {
                printf("Erro: Expressao invalida\n"); // Imprime uma mensagem de erro se a expressão for inválida
                return 0.0;
            }

            float operando2 = pilha[topo--]; // Remove o último operando da pilha
            float operando1 = pilha[topo--]; // Remove o penúltimo operando da pilha
            float resultado;
            switch (termo[0]) // Executa a operação com base no operador
            {
            case '+':
                resultado = operando1 + operando2;
                break;
            case '-':
                resultado = operando1 - operando2;
                break;
            case '*':
                resultado = operando1 * operando2;
                break;
            case '/':
                resultado = operando1 / operando2;
                break;
            default:
                printf("Erro: Operador invalido\n"); // Imprime uma mensagem de erro se o operador for inválido
                resultado = 0.0;
                break;
            }
            pilha[++topo] = resultado; // Adiciona o resultado da operação à pilha
        }
        termo = strtok(NULL, " "); // Avança para o próximo termo
    }

    if (topo != 0)
    {
        printf("Erro: Expressao invalida\n"); // Imprime uma mensagem de erro se a expressão for inválida
        return 0.0;
    }

    return pilha[topo]; // Retorna o resultado final da expressão
}

void converter_prefixa_para_posfixa(const Expressao *expressao_prefixa, Expressao *expressao_posfixa)
{
    char pilha[200][200];
    int topo = -1;

    char *expressao_prefixa_temp = strdup(expressao_prefixa->expressao); // Cria uma cópia temporária da expressão prefixa
    char *termo = strtok(expressao_prefixa_temp, " ");                   // Divide a expressão em termos separados por espaços
    while (termo != NULL)
    {
        if (isOperador(termo[0])) // Se o termo for um operador
        {
            while (topo >= 0 && isOperador(pilha[topo][0]) && getPrioridade(pilha[topo][0]) >= getPrioridade(termo[0]))
            {
                // Enquanto houver operadores no topo da pilha com prioridade maior ou igual ao termo atual
                adicionar_elemento(expressao_posfixa, pilha[topo]); // Adiciona o operador no topo da pilha à expressão posfixa
                topo--;                                             // Remove o operador do topo da pilha
            }
            strcpy(pilha[++topo], termo); // Adiciona o termo atual à pilha
        }
        else // Se o termo for um número
        {
            adicionar_elemento(expressao_posfixa, termo); // Adiciona o número à expressão posfixa
        }
        termo = strtok(NULL, " "); // Avança para o próximo termo
    }

    while (topo >= 0)
    {
        adicionar_elemento(expressao_posfixa, pilha[topo]); // Adiciona os operadores restantes da pilha à expressão posfixa
        topo--;
    }

    free(expressao_prefixa_temp); // Libera a memória alocada para a expressão prefixa temporária
}
