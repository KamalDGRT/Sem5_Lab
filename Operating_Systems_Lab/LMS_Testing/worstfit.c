#include <stdio.h>

int main()
{
    int f[10], b[10], p[10], m, n, nb, np, t, d = 0;
    static int ba[10], pa[10];
    
    scanf("%d", &nb);
    scanf("%d", &np);
    
    for(m = 1; m <= nb; m++)
        scanf("%d", &b[m]);
        
    for(n = 1; n <= np; n++)
        scanf("%d", &p[n]);
    
    for(m = 1; m <= np; m++)
    {
        for(n = 1; n <= np; n++)
        {
            if(ba[n] != 1)
            {
                t = b[n] - p[m];
                if(t >= 0)
                    if(d < t)
                    {
                        pa[m] = n;
                        d = t;
                    }
            }
        }
        f[m] = d;
        ba[pa[m]] = 1;
        d = 0;
    }
    
    printf("Process_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragment");
    
    for(m = 1; m <= np; m++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, p[m], pa[m], b[pa[m]], f[m]);
    
    return 0;
}
