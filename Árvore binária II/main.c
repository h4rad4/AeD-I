#include "main.h"
#include <stdio.h>

int main()
{
    Arvore arvore = {.raiz = NULL};
    char expressao_infixa[] = "a*((b-c)/d)";

    for (int i = 0; expressao_infixa[i] != '\0'; i++)
    {
        if (expressao_infixa[i] != ' ')
            inserir(&arvore, expressao_infixa[i]);
    }

    char expressao_posfixa[100];
    infixa_para_posfixa(expressao_infixa, expressao_posfixa);

    char expressao_prefixa[100];
    infixa_para_prefixa(expressao_infixa, expressao_prefixa);

    printf("Expressao Infixa: %s\n", expressao_infixa);
    printf("Expressao Posfixa: %s\n", expressao_posfixa);
    printf("Expressao Prefixa: %s\n", expressao_prefixa);

    printf("Resultado = %d\n", avaliar(arvore.raiz));

    liberar_arvore(arvore.raiz);

    return 0;
}
