#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

void inicializarHash(TB_HASH tabela)
{
    int i;

    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

float indiceHash(double codigo)
{
    return sin((codigo * M_PI / 180));
}

int inserirHash(TB_HASH tabela, Paciente paciente)
{
    /* O código do paciente é meramente um valor para definir a posição da tabela onde o elemento será inserido */
    for (int i = indiceHash(paciente.codigo); i != NULL; i = indiceHash(paciente.codigo + 1))
    {
        return (tabela[i]->codigo == paciente.codigo); // Se a condição for verdadeira, retorna 1
                                                       // Se a condição for falsa, retorna 0
        i = indiceHash(paciente.codigo + 1);
    }
}
