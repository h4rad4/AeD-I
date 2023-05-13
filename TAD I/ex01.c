/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
TDA String em C

Suponha que uma cadeia de caracteres S contenha uma frase qualquer. Vamos construir um programa que, utilizando as operações disponíveis na biblioteca string.h,
verifique se a frase possui pelo menos uma ocorrência de um caractere P, também lido. Em caso afirmativo, imprimir  SIM;  caso contrário, imprimir NÃO.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

int main(int argc, char const *argv[])
{
    char frase[1][100] = {};
    char letra[1];
    int boolean;

    printf("Escreva uma frase. ");
    fgets(frase[0], 100, stdin);

    printf("Insira a letra a ser buscada na frase anterior. ");
    scanf("%c", &letra[0]);

    Busca(frase, letra, boolean);

    return 0;
}

void Busca(char frase[1][100], char letra[1], int boolean)
{
    for (int i = 0; i < strlen(frase[0]) - 1; i++)
    {
        if (frase[0][i] == letra[0])
        {
            boolean = True;
            printf("SIM.");
        }
    }

    if (boolean != True)
    {
        printf("NAO.");
    }
}