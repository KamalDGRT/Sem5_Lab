#include<stdio.h>

int main() {

    int nop, wt[10], twt, tat[10], ttat, i, bt[10];
    float awt, atat;

    awt = 0.0;
    atat = 0.0;

    nop = 3;

    for(i = 0; i < nop; i++) {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];
    twt = wt[0];
    ttat = tat[0];
    
    for(i = 1; i < nop; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        twt += wt[i];
        ttat += tat[i];
    }

    awt = (float)twt/nop;
    atat = (float)ttat/nop;

    printf("%f\n%f", awt, atat);
    return 0;

}
