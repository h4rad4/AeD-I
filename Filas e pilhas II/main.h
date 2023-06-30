#ifndef MAIN_H
#define MAIN_H

typedef struct
{
    char expressao[200];
    int tamanho;
} Expressao;

Expressao criar_expressao();
void apagar_expressao(Expressao *expressao);
void imprimir_expressao(const Expressao *expressao);
void adicionar_elemento(Expressao *expressao, const char *elemento);
void converter_posfixa_para_prefixa(const Expressao *expressao_posfixa, Expressao *expressao_prefixa);
float avaliar_expressao(const Expressao *expressao);

#endif
