#ifndef MAIN_H
#define MAIN_H

typedef struct
{
    char expressao[200];
    int tamanho;

} Expressao;

typedef struct no
{
    char elemento[200];
    struct no *proximo;

} No;

typedef struct
{
    No *topo;

} Pilha;

/* Funções relacionadas ao TDA Expressao */
Expressao criar_expressao();                                                                           // Cria e retorna uma expressão vazia
void apagar_expressao(Expressao *expressao);                                                           // Apaga o conteúdo da expressão
void imprimir_expressao(const Expressao *expressao);                                                   // Imprime a expressão na tela
void adicionar_elemento(Expressao *expressao, const char *elemento);                                   // Adiciona um elemento à expressão
void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa); // Converte uma expressão posfixa em prefixa
void converter_prefixa_para_posfixa(const Expressao *expressao_prefixa, Expressao *expressao_posfixa); // Converte uma expressão prefixa em posfixa
float resultado_expressao(const Expressao *expressao);                                                 // Calcula e retorna o resultado da expressão

/* Funções relacionadas ao TDA Pilha */
Pilha *criar_pilha();                              // Cria e retorna uma pilha vazia
void apagar_pilha(Pilha *pilha);                   // Libera a memória ocupada pela pilha
int pilha_vazia(const Pilha *pilha);               // Verifica se a pilha está vazia
void empilhar(Pilha *pilha, const char *elemento); // Empilha um elemento na pilha
void desempilhar(Pilha *pilha);                    // Desempilha o elemento do topo da pilha
char *topo_pilha(const Pilha *pilha);              // Retorna o elemento do topo da pilha

/* Funções auxiliares */
int isOperador(char c);          // Verifica se um caractere é um operador (+, -, *, /)
int getPrioridade(char c);       // Obtém a prioridade de um operador (+, -, *, /)
void inverter_string(char *str); // Inverte uma string

#endif
