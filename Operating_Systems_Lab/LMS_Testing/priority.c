#include<stdio.h>

int main() {

    int nop, t, wt[10], twt, tat[10], ttat, i, j, p[10], b[10], tmp;
    int awt, atat;

    awt = 0.0;
    atat = 0.0;

    scanf("%d", &nop);

    for(i = 0; i < nop; i++) {
        scanf("%d", &b[i]);
    }

    for(i = 0; i < nop; i++) {
        scanf("%d", &p[i]);
    }

    for(i = 0; i < nop; i++) {
        for(j = i + 1; j < nop; j++) {
            if(p[i] > p[j]) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;

                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = b[0];
    twt = wt[0];
    ttat = tat[0];
    
    for(i = 1; i < nop; i++) {
        wt[i] = wt[i-1] + b[i-1];
        tat[i] = wt[i] + b[i];
        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt/nop;
    atat = ttat/nop;

    printf("%d\n", awt);
    printf("%d", atat);
    return 0;

}
