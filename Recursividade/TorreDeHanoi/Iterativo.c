#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 3;
    int from, to, k;

    for (k = 1; k < (1 << n); k++)
    {
        /* obtem haste origem */
        from = (k & (k - 1)) % 3;

        /* obtem haste destino */
        to = ((k | (k - 1)) + 1) % 3;

        /* descreve o movimento */
        printf("Mova disco de %d para %d\n", from, to);
    }

    return 0;
}
