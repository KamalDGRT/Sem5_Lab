#include <stdio.h>

#define max 25

int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];

    scanf("%d", &nb);

    scanf("%d", &nf);

    for (i = 1; i <= nb; i++)
        scanf("%d", &b[i]);

    for (i = 1; i <= nf; i++)
        scanf("%d", &f[i]);

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (highest < temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }

    printf("Process_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");

    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);

    return 0;
}
