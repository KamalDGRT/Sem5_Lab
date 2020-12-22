#include <stdio.h>

int main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];

    scanf("%d", &nb);
    scanf("%d", &np);

    for (i = 1; i <= nb; i++)
        scanf("%d", &b[i]);

    for (i = 1; i <= np; i++)
        scanf("%d", &p[i]);

    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
            }
        }

        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }

    printf("Process_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= np & parray[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);

    return 0;
}
