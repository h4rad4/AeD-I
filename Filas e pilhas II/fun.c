#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Pilha *criar_pilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void apagar_pilha(Pilha *pilha)
{
    No *atual = pilha->topo;
    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(pilha);
}

int pilha_vazia(const Pilha *pilha)
{
    return (pilha->topo == NULL);
}

void empilhar(Pilha *pilha, const char *elemento)
{
    No *novo_no = (No *)malloc(sizeof(No));
    strcpy(novo_no->elemento, elemento);
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
}

void desempilhar(Pilha *pilha)
{
    if (pilha_vazia(pilha))
    {
        return;
    }
    No *no_removido = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(no_removido);
}

const char *topo_pilha(const Pilha *pilha)
{
    if (pilha_vazia(pilha))
    {
        return NULL;
    }
    return pilha->topo->elemento;
}

Expressao criar_expressao()
{
    Expressao expressao;
    expressao.expressao[0] = '\0';
    return expressao;
}

void adicionar_elemento(Expressao *expressao, const char *elemento)
{
    strcat(expressao->expressao, " ");
    strcat(expressao->expressao, elemento);
}

void imprimir_expressao(const Expressao *expressao)
{
    printf("%s\n", expressao->expressao);
}

void apagar_expressao(Expressao *expressao)
{
    expressao->expressao[0] = '\0';
}

int isOperador(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrioridade(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
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
}

void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa)
{
    Pilha *pilha = criar_pilha();
    char *expressao_posfixa_temp = strdup(expressao_posfixa->expressao);
    char *termo = strtok(expressao_posfixa_temp, " ");
    while (termo != NULL)
    {
        if (isOperador(termo[0]))
        {
            while (!pilha_vazia(pilha) && isOperador(topo_pilha(pilha)[0]) && getPrioridade(topo_pilha(pilha)[0]) >= getPrioridade(termo[0]))
            {
                adicionar_elemento(expressao_prefixa, topo_pilha(pilha));
                desempilhar(pilha);
            }
            empilhar(pilha, termo);
        }
        else
        {
            adicionar_elemento(expressao_prefixa, termo);
        }
        termo = strtok(NULL, " ");
    }

    while (!pilha_vazia(pilha))
    {
        adicionar_elemento(expressao_prefixa, topo_pilha(pilha));
        desempilhar(pilha);
    }

    inverter_string(expressao_prefixa->expressao);

    free(expressao_posfixa_temp);
    apagar_pilha(pilha);
}

float resultado_expressao(const Expressao *expressao)
{
    char operadores[] = "+-*/";
    Pilha *pilha = criar_pilha();
    char *expressao_temp = strdup(expressao->expressao);
    char *termo = strtok(expressao_temp, " ");
    while (termo != NULL)
    {
        if (strchr(operadores, termo[0]) == NULL)
        {
            empilhar(pilha, termo);
        }
        else
        {
            if (pilha_vazia(pilha))
            {
                printf("Erro: Expressao invalida\n");
                return 0.0;
            }

            float operando2 = atof(topo_pilha(pilha));
            desempilhar(pilha);
            if (pilha_vazia(pilha))
            {
                printf("Erro: Expressao invalida\n");
                return 0.0;
            }

            float operando1 = atof(topo_pilha(pilha));
            desempilhar(pilha);

            float resultado;
            switch (termo[0])
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
            char str_resultado[20];
            snprintf(str_resultado, sizeof(str_resultado), "%.2f", resultado);
            empilhar(pilha, str_resultado);
        }
        termo = strtok(NULL, " ");
    }

    if (pilha_vazia(pilha))
    {
        printf("Erro: Expressao invalida\n");
        return 0.0;
    }

    float resultado_final = atof(topo_pilha(pilha));

    free(expressao_temp);
    apagar_pilha(pilha);

    return resultado_final;
}
