#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Expressao criar_expressao()
{
    Expressao expressao;
    expressao.expressao[0] = '\0';
    expressao.tamanho = 0;
    return expressao;
}

void apagar_expressao(Expressao *expressao)
{
    expressao->expressao[0] = '\0';
    expressao->tamanho = 0;
}

void imprimir_expressao(const Expressao *expressao)
{
    printf("Expressão: %s\n", expressao->expressao);
}

void adicionar_elemento(Expressao *expressao, const char *elemento)
{
    int tamanho_atual = expressao->tamanho;
    int novo_tamanho = tamanho_atual + strlen(elemento) + 2; // +2 para espaço em branco e caractere nulo

    strcat(expressao->expressao, " ");
    strcat(expressao->expressao, elemento);
    expressao->tamanho = novo_tamanho - 1; // -1 para excluir o caractere nulo
}

void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa)
{
    char operadores[] = "+-*/";
    char pilha[200][200];
    int topo = -1;

    char *expressao_posfixa_temp = strdup(expressao_posfixa->expressao); // Copia a expressão
    char *token = strtok(expressao_posfixa_temp, " ");                   // Pega o próximo elemento após o fim da expressão
    while (token != NULL)
    {
        if (strchr(operadores, token[0]) == NULL)
        {
            adicionar_elemento(expressao_prefixa, token);
        }
        else
        {
            char operando1[200], operando2[200];
            strcpy(operando1, pilha[topo]);
            topo--;
            strcpy(operando2, pilha[topo]);
            topo--;
            char expressao_prefixa_temp[200];
            sprintf(expressao_prefixa_temp, "%s %s %s", token, operando1, operando2);
            adicionar_elemento(expressao_prefixa, expressao_prefixa_temp);
            topo++;
            strcpy(pilha[topo], expressao_prefixa_temp);
        }
        token = strtok(NULL, " ");
    }

    free(expressao_posfixa_temp);
}

float avaliar_expressao(const Expressao *expressao)
{
    char operadores[] = "+-*/";
    float pilha[200];
    int topo = -1;

    char expressao_temp[200];
    strcpy(expressao_temp, expressao->expressao);

    char *token = strtok(expressao_temp, " ");
    while (token != NULL)
    {
        if (strchr(operadores, token[0]) == NULL)
        {
            pilha[++topo] = atof(token);
        }
        else
        {
            float operando2 = pilha[topo--];
            float operando1 = pilha[topo--];
            float resultado;
            switch (token[0])
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
                printf("Erro: Operador inválido\n");
                resultado = 0.0;
                break;
            }
            pilha[++topo] = resultado;
        }
        token = strtok(NULL, " ");
    }

    return pilha[topo];
}
