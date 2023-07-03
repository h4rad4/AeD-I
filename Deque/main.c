#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    DEQUE turma;
    inicializar(&turma);

    Aluno lista01[3] = {{"Polaris"}, {"Vega"}, {"Aldebaran"}};
    Aluno lista02[3] = {{"Centauri"}, {"Lyra"}, {"Antares"}};

    for (int i = 0; i < 3; i++)
        inserirInicio(&turma, lista01[i]);

    for (int i = 0; i < 3; i++)
        inserirFim(&turma, lista02[i]);

    imprimir(turma, 'd', 0);
    imprimir(turma, 'i', 5);
}
