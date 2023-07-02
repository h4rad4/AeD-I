#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Pilha *criar_pilha()
{
    // Aloca memória para uma nova pilha
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    // Inicializa o topo da pilha como NULL
    pilha->topo = NULL;
    // Retorna a pilha criada
    return pilha;
}

void apagar_pilha(Pilha *pilha)
{
    // Remove cada nó da pilha, liberando memória
    No *atual = pilha->topo;
    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    // Libera a memória ocupada pela estrutura da pilha
    free(pilha);
}

int pilha_vazia(const Pilha *pilha)
{
    // Verifica se o topo da pilha é NULL
    // Se for, a pilha está vazia
    return (pilha->topo == NULL);
}

void empilhar(Pilha *pilha, const char *elemento)
{
    // Aloca memória para um novo nó
    No *novo_no = (No *)malloc(sizeof(No));
    // Copia o elemento para o campo 'elemento' do novo nó
    strcpy(novo_no->elemento, elemento);
    // Atualiza o campo 'proximo' do novo nó para apontar para o antigo topo da pilha
    novo_no->proximo = pilha->topo;
    // Atualiza o topo da pilha para apontar para o novo nó
    pilha->topo = novo_no;
}

void desempilhar(Pilha *pilha)
{
    // Verifica se a pilha está vazia
    if (pilha_vazia(pilha))
        return;

    // Remove o nó do topo da pilha e atualiza o topo para o próximo nó
    No *no_removido = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    // Libera a memória ocupada pelo nó removido
    free(no_removido);
}

const char *topo_pilha(const Pilha *pilha)
{
    // Verifica se a pilha está vazia
    if (pilha_vazia(pilha))
    {
        // Se estiver vazia, retorna NULL
        return NULL;
    }
    // Retorna o valor do campo 'elemento' do nó no topo da pilha
    return pilha->topo->elemento;
}

Expressao criar_expressao()
{
    // Cria uma nova estrutura de expressão e inicializa seu campo 'expressao' como uma string vazia
    Expressao expressao;
    expressao.expressao[0] = '\0';
    return expressao;
}

void adicionar_elemento(Expressao *expressao, const char *elemento)
{
    // Adiciona um elemento à expressão, concatenando um espaço em branco e o valor do elemento na string 'expressao->expressao'
    strcat(expressao->expressao, " ");
    strcat(expressao->expressao, elemento);
}

void imprimir_expressao(const Expressao *expressao)
{
    // Imprime a expressão armazenada na estrutura de expressão
    printf("%s\n", expressao->expressao);
}

void apagar_expressao(Expressao *expressao)
{
    // Limpa a expressão, definindo seu campo 'expressao' como uma string vazia
    expressao->expressao[0] = '\0';
}

int isOperador(char c)
{
    // Verifica se o caractere 'c' é um operador (+, -, * ou /)
    // Retorna 1 se for um operador e 0 caso contrário
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrioridade(char c)
{
    // Retorna a prioridade do operador representado pelo caractere 'c'
    // Os operadores + e - têm prioridade 1, enquanto * e / têm prioridade 2
    // Qualquer outro caractere retorna prioridade 0
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

void inverter_string(char *str)
{
    // Inverte a ordem dos caracteres na string 'str'
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
    // Cria uma pilha para auxiliar na conversão
    Pilha *pilha = criar_pilha();
    // Cria uma cópia temporária da expressão posfixa
    char *expressao_posfixa_temp = strdup(expressao_posfixa->expressao);
    // Divide a expressão em termos separados por espaço
    char *termo = strtok(expressao_posfixa_temp, " ");
    while (termo != NULL)
    {
        if (isOperador(termo[0]))
        {
            // Se o termo for um operador, verifica a prioridade com o operador no topo da pilha
            while (!pilha_vazia(pilha) && isOperador(topo_pilha(pilha)[0]) && getPrioridade(topo_pilha(pilha)[0]) >= getPrioridade(termo[0]))
            {
                // Enquanto a prioridade do operador no topo da pilha for maior ou igual à do termo atual, desempilha e adiciona o operador à expressão prefixa
                adicionar_elemento(expressao_prefixa, topo_pilha(pilha));
                desempilhar(pilha);
            }
            // Empilha o operador atual
            empilhar(pilha, termo);
        }
        else
        {
            // Se o termo for um número ou operando, adiciona-o diretamente à expressão prefixa
            adicionar_elemento(expressao_prefixa, termo);
        }
        // Obtém o próximo termo da expressão posfixa
        termo = strtok(NULL, " ");
    }

    // Desempilha os operadores restantes na pilha e adiciona-os à expressão prefixa
    while (!pilha_vazia(pilha))
    {
        adicionar_elemento(expressao_prefixa, topo_pilha(pilha));
        desempilhar(pilha);
    }

    // Inverte a expressão prefixa para obter a notação correta
    inverter_string(expressao_prefixa->expressao);

    // Libera a memória alocada e apaga a pilha
    free(expressao_posfixa_temp);
    apagar_pilha(pilha);
}

float resultado_expressao(const Expressao *expressao)
{
    // Cria uma pilha para auxiliar no cálculo
    char operadores[] = "+-*/";

    Pilha *pilha = criar_pilha();
    // Cria uma cópia temporária da expressão
    char *expressao_temp = strdup(expressao->expressao);

    // Divide a expressão em termos separados por espaço
    char *termo = strtok(expressao_temp, " ");
    while (termo != NULL)
    {
        if (strchr(operadores, termo[0]) == NULL)
        {
            // Se o termo não for um operador, empilha o operando na pilha
            empilhar(pilha, termo);
        }
        else
        {
            // Se o termo for um operador, desempilha os dois operandos anteriores da pilha
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
            // Converte o resultado em uma string e empilha na pilha
            char str_resultado[20];
            snprintf(str_resultado, sizeof(str_resultado), "%.2f", resultado);
            empilhar(pilha, str_resultado);
        }
        // Obtém o próximo termo da expressão
        termo = strtok(NULL, " ");
    }

    // Verifica se a pilha está vazia no final
    if (pilha_vazia(pilha))
    {
        printf("Erro: Expressao invalida\n");
        return 0.0;
    }

    // O resultado final é o valor restante no topo da pilha
    float resultado_final = atof(topo_pilha(pilha));

    // Libera a memória alocada e apaga a pilha
    free(expressao_temp);
    apagar_pilha(pilha);

    return resultado_final;
}
