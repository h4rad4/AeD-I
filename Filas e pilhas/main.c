#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    FILA fila;

    AVIAO Drummond = {"STDRM", 001};
    AVIAO Twilight = {"TWLGHT", 002};
    AVIAO Eclipse = {"ECLIPSE", 003};

    inserirAviao(&fila, Drummond);
    inserirAviao(&fila, Twilight);
    inserirAviao(&fila, Eclipse);
    
    imprimirAviao(&fila);

    return 0;
}
