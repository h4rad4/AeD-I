#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

// Função para criar uma expressão vazia
Expressao criar_expressao()
{
    Expressao expressao;
    expressao.tamanho = 0; // Inicializa o tamanho da expressão como zero
    return expressao;
}

// Função para apagar o conteúdo de uma expressão existente
void apagar_expressao(Expressao *expressao)
{
    expressao->tamanho = 0;         // Define o tamanho da expressão como zero
    expressao->expressao[0] = '\0'; // Define a expressão como uma string vazia
}

// Função para imprimir o conteúdo de uma expressão
void imprimir_expressao(const Expressao *expressao)
{
    printf("Expressao: %s\n", expressao->expressao + 1); // Imprime a expressão
}

// Função para adicionar um elemento (operando ou operador) à expressão
void adicionar_elemento(Expressao *expressao, const char *elemento)
{
    int tamanho_atual = expressao->tamanho;
    int novo_tamanho = tamanho_atual + strlen(elemento) + 2; // Calcula o novo tamanho da expressão

    strcat(expressao->expressao, " ");      // Adiciona um espaço em branco antes do novo elemento
    strcat(expressao->expressao, elemento); // Concatena o novo elemento à expressão existente
    expressao->tamanho = novo_tamanho - 1;  // Atualiza o tamanho da expressão, descontando o caractere nulo
}

// Função para converter uma expressão posfixa em uma expressão prefixa
void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa)
{
    char operadores[] = "+-*/";
    char pilha[200][200];
    int topo = -1;

    char *expressao_posfixa_temp = strdup(expressao_posfixa->expressao); 
    char *token = strtok(expressao_posfixa_temp, " ");                   
    while (token != NULL)
    {
        if (strchr(operadores, token[0]) == NULL) // Se for um operando
        {
            adicionar_elemento(expressao_prefixa, token); // Adiciona o operando à expressão prefixa
        }
        else // Se for um operador
        {
            char operando1[200], operando2[200];
            strcpy(operando1, pilha[topo]); // Obtém o primeiro operando da pilha
            topo--;
            strcpy(operando2, pilha[topo]); // Obtém o segundo operando da pilha
            topo--;

            char expressao_prefixa_temp[200];
            sprintf(expressao_prefixa_temp, "%s %s %s", token, operando1, operando2); // Cria uma expressão prefixa temporária com o operador e operandos na ordem correta
            adicionar_elemento(expressao_prefixa, expressao_prefixa_temp);            // Adiciona a expressão prefixa temporária à expressão prefixa final

            topo++;
            strcpy(pilha[topo], expressao_prefixa_temp); // Adiciona a expressão prefixa temporária à pilha para uso posterior
        }
        token = strtok(NULL, " "); // Move para o próximo token
    }

    free(expressao_posfixa_temp); // Libera a memória alocada para a cópia da expressão posfixa
}

// Função para avaliar o resultado de uma expressão posfixa
float avaliar_expressao(const Expressao *expressao)
{
    char operadores[] = "+-*/";
    float pilha[200];
    int topo = -1;

    char expressao_temp[200];
    strcpy(expressao_temp, expressao->expressao); // Copia a expressão posfixa

    char *token = strtok(expressao_temp, " "); // Divide a expressão em elementos separados por espaços em branco
    while (token != NULL)
    {
        if (strchr(operadores, token[0]) == NULL) // Se for um operando
        {
            pilha[++topo] = atof(token); // Converte o operando para float e adiciona na pilha
        }
        else // Se for um operador
        {
            float operando2 = pilha[topo--]; // Obtém o segundo operando da pilha
            float operando1 = pilha[topo--]; // Obtém o primeiro operando da pilha
            float resultado;
            switch (token[0]) // Realiza a operação correspondente ao operador
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
                printf("Erro: Operador invalido\n");
                resultado = 0.0;
                break;
            }
            pilha[++topo] = resultado; // Adiciona o resultado da operação na pilha
        }
        token = strtok(NULL, " "); // Move para o próximo token
    }

    return pilha[topo]; // Retorna o resultado final da expressão posfixa
}
