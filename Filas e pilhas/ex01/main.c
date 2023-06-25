#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    FILA fila;

    AVIAO Dawn = {"STDWN", 001};
    AVIAO Twilight = {"TWLGHT", 002};
    AVIAO Eclipse = {"ECLIPSE", 003};

    inserirAviao(&fila, Dawn);
    inserirAviao(&fila, Twilight);
    inserirAviao(&fila, Eclipse);

    imprimirAviao(&fila);

    /* Liberando o primeiro aviao, da 1º posiçao da fila */
    liberarAviao(&fila);
    imprimirAviao(&fila);

    /* Liberando o segundo aviao, da 1º posiçao da fila */
    liberarAviao(&fila);
    imprimirAviao(&fila);

    /* Liberando o terceiro aviao, da 1º posiçao da fila */
    liberarAviao(&fila);
    imprimirAviao(&fila);

    return 0;
}
