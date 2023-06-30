#include <stdio.h>
#include "main.h"

int main()
{
    Expressao expressao = criar_expressao();
    adicionar_elemento(&expressao, "5");
    adicionar_elemento(&expressao, "3");
    adicionar_elemento(&expressao, "+");

    imprimir_expressao(&expressao);

    float resultado = avaliar_expressao(&expressao);
    printf("Resultado: %.2f\n", resultado);

    Expressao expressao_prefixa = criar_expressao();
    converter_posfixa_para_prefixa(&expressao, &expressao_prefixa);
    imprimir_expressao(&expressao_prefixa);

    apagar_expressao(&expressao);
    apagar_expressao(&expressao_prefixa);

    return 0;
}
