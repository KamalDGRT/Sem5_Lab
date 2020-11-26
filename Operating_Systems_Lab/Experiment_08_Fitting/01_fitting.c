/* First fit, Best fit and Worst fit */

#include <stdio.h>
int main()
{
    int f3[20], f2[20], r[20], r1[20], bod, sb[20], nsb[20], nsb1[20], np, sp[20];
    int f[20], i, j, l, k, z[20], s = 0;
    printf("\n enter the number of block of division of memory:");
    scanf("%d", &bod);
    printf("enter the size of each block:");
    for (i = 1; i <= bod; i++)
    {
        printf("\nBlock[%d]:", i);
        scanf("%d", &sb[i]);
        f[i] = 1;
        f2[i] = 1;
        f3[i] = 1;
        r[i] = 1;
        r1[i] = 1;
        z[i] = sb[i];
    }
    printf("\nenter the number of process:");
    scanf("%d", &np);
    printf("\nenter the size of each process:");
    for (i = 1; i <= np; i++)
    {
        printf("\nprocess[%d]:", i);
        scanf("%d", &sp[i]);
    }
    printf("\n  FIRST FIT  ");
    printf("\n *********  ");
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= bod; j++)
        {
            if ((sb[j] >= sp[i]) && (f[j] != 0))
            {
                printf("\n Process p[%d] is allocated to Block[%d]", i, j);
                f[j] = 0;
                z[j] = sb[j] - sp[i];
                s++;
                goto l1;
            }
        }
        printf("\n process p[%d] cannot be allocated", i);
    l1:
        printf(" ");
    }
    printf("\n\n Remaining space left in each block \n");
    printf("\n     ********************************** \n");
    for (i = 1; i <= bod; i++)
    {
        printf("\n Block[%d]: free space =%d", i, z[i]);
    }
    printf("\n\nUnallocated Blocks");
    printf(" \n ******************");
    for (i = 1; i <= bod; i++)
    {
        if (f[i] != 0)
        {
            printf("\n Block [%d] unallocated", i);
        }
    }
    if (s == bod)
        printf("\n No Block is left unallocated");
    //getch();
    s = 0;
    //getch();
    printf("\n\n BEST FIT ");
    printf("\n   ******** ");
    //to find the order or rank of the block  5,8,4,10 r[1]=2,r[2]=3,r[3]=1,r[4]=4
    for (i = 2; i <= bod; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (sb[i] >= sb[j])
                r[i]++;
            else
                r[j]++;
        }
    }
    // to place the block in ascending order in new variable nsb,and z nsb[2]=5,nsb[3]=8,nsb[1]=4,nsb[4]=10
    for (i = 1; i <= bod; i++)
    {
        nsb[r[i]] = sb[i];
        z[r[i]] = sb[i];
    }
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= bod; j++)
        {
            if ((nsb[j] >= sp[i]) && (f2[j] != 0))
            {
                //To identify the location of the block
                for (k = 1; k <= bod; k++)
                {
                    if (r[k] == j)
                        l = k;
                }
                printf("\nProcess p[%d] is allocated to Block[%d]", i, l);
                f2[j] = 0;
                z[j] = nsb[j] - sp[i];
                s++;
                goto l2;
            }
        }
        printf("\n process p[%d] cannot be allocated", i);
    l2:
        printf(" ");
    }
    printf("\n free space in each block \n");
    printf("   ************************ \n");
    for (i = 1; i <= bod; i++)
        printf("\nBlock [%d]: free space =%d", i, z[r[i]]);

    printf("\n\nUnallocated Blocks");
    printf(" \n ******************");
    for (i = 1; i <= bod; i++)
    {
        if (f2[r[i]] != 0)
        {
            printf("\n Block [%d] unallocated", i);
        }
    }
    if (s == bod)
        printf("\n No Block is left unallocated");
    //getch();
    s = 0;
    //getch();
    printf("\n\n WORST FIT ");
    printf("\n   ********* ");
    for (i = 2; i <= bod; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (sb[i] <= sb[j])
                r1[i]++;
            else
                r1[j]++;
        }
    }
    for (i = 1; i <= bod; i++)
    {
        nsb1[r1[i]] = sb[i];
        z[r1[i]] = sb[i];
    }
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= bod; j++)
        {
            if ((nsb1[j] >= sp[i]) && (f3[j] != 0))
            {
                for (k = 1; k <= bod; k++)
                {
                    if (r1[k] == j)
                        l = k;
                }
                printf("\nProcess p[%d] is allocated to Block[%d]", i, l);
                f3[j] = 0;
                z[j] = nsb1[j] - sp[i];
                s++;
                goto l3;
            }
        }
        printf("\n process p[%d] cannot be allocated", i);
    l3:
        printf(" ");
    }
    printf("\n free space in each block \n");
    printf("   ************************ \n");
    for (i = 1; i <= bod; i++)
        printf("\nBlock [%d]: free space =%d", i, z[r1[i]]);

    printf("\n\nUnallocated Blocks");
    printf(" \n ******************");
    for (i = 1; i <= bod; i++)
    {
        if (f3[r1[i]] != 0)
        {
            printf("\n Block [%d] unallocated", i);
        }
        if (s == bod)
            printf("\n No Block is left unallocated");
        //getch();
        printf("\n");
    }
    return (0);
}
