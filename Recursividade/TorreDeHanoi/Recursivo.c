#include <stdio.h>

void MoveTorre(int n, char origem, char destino, char auxiliar)
{
    if (n == 1)
    {
        MoveDisco(origem, destino);
    }
    else
    {
        MoveTorre(n - 1, origem, auxiliar, destino);
        MoveDisco(origem, destino);
        MoveTorre(n - 1, auxiliar, destino, origem);
    }
}

void MoveDisco(char origem, char destino)
{
    printf("Mova o disco de %c para %c\n", origem, destino);
}

int main()
{
    int n = 4;
    char origem = 'A';
    char destino = 'C';
    char auxiliar = 'B';

    MoveTorre(n, origem, destino, auxiliar);

    return 0;
}
