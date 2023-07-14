#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    Deque turma;
    inicializar(&turma);

    Aluno lista[6] = {{"Polaris"}, {"Vega"}, {"Aldebaran"}, {"Centauri"}, {"Lyra"}, {"Antares"}};

    for (int i = 0; i < 3; i++)
        inserirInicio(&turma, lista[i]);

    for (int i = 3; i < 6; i++)
        inserirFim(&turma, lista[i]);

    // imprimir(turma, 'd', 0);
    // imprimir(turma, 'i', 5);

    excluirDequeFim(&turma, &lista[0]);
    excluirDequeInicio(&turma, &lista[0]);

    exibirDequeInicio(&turma);
}
