#include <stdio.h>
#include "main.h"

int main()
{
    printf("[Criando expressao posfixa] \n");
    Expressao expressao = criar_expressao();
    adicionar_elemento(&expressao, "5");
    adicionar_elemento(&expressao, "3");
    adicionar_elemento(&expressao, "*");

    imprimir_expressao(&expressao);

    float resultado = resultado_expressao(&expressao);
    printf("Resultado: %.2f\n", resultado);

    printf("Realizando conversao para prefixa... \n");
    Expressao expressao_prefixa = criar_expressao();
    converter_posfixa_para_prefixa(&expressao, &expressao_prefixa);
    imprimir_expressao(&expressao_prefixa);

    printf("Convertendo de volta para posfixa... \n");
    Expressao expressao_posfixa = criar_expressao();
    converter_prefixa_para_posfixa(&expressao_prefixa, &expressao_posfixa);
    imprimir_expressao(&expressao_posfixa);

    apagar_expressao(&expressao);
    apagar_expressao(&expressao_prefixa);
    apagar_expressao(&expressao_posfixa);

    return 0;
}
