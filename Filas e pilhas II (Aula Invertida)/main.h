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
Expressao criar_expressao();
void apagar_expressao(Expressao *expressao);
void imprimir_expressao(const Expressao *expressao);
void adicionar_elemento(Expressao *expressao, const char *elemento);

void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa,
                                    Expressao *expressao_prefixa);
void converter_prefixa_para_posfixa(const Expressao *expressao_prefixa,
                                    Expressao *expressao_posfixa);     
float resultado_expressao(const Expressao *expressao);

/* Funções relacionadas ao TDA Pilha */
Pilha *criar_pilha();
void apagar_pilha(Pilha *pilha);
int pilha_vazia(const Pilha *pilha);
void empilhar(Pilha *pilha, const char *elemento);
void desempilhar(Pilha *pilha);
char *topo_pilha(const Pilha *pilha);

/* Funções auxiliares */
int isOperador(char c);
int getPrioridade(char c);
void inverter_string(char *str);

#endif
