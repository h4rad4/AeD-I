#include <stdio.h>
#include "main.h"

int main()
{
    Expressao expressao_posfixa = criar_expressao();
    adicionar_elemento(&expressao_posfixa, "5");
    adicionar_elemento(&expressao_posfixa, "3");
    adicionar_elemento(&expressao_posfixa, "*");

    Expressao expressao_prefixa = criar_expressao();
    converter_posfixa_para_prefixa(&expressao_posfixa, &expressao_prefixa);

    printf("Expressao Posfixa: ");
    imprimir_expressao(&expressao_posfixa);

    printf("Expressao Prefixa: ");
    imprimir_expressao(&expressao_prefixa);

    float resultado = resultado_expressao(&expressao_posfixa);
    printf("Resultado da Expressao: %.2f\n", resultado);

    apagar_expressao(&expressao_posfixa);
    apagar_expressao(&expressao_prefixa);
    return 0;
}
